#include "Browser.h"

#include "ClientInit.h"
#include "event/ClientEventHandlers.h"
#include "function/ClientFunctions.h"
#include "function/SharedFunctions.h"

const unsigned long formatBGRA8888 = 7;

char* resizeTexture(int* srcsize, int dstx, int dsty, void* src, void* dest, unsigned long fmt)
{
	XCALL(0x00659670);
}

namespace wog
{
	Browser::Browser(const int x, const int y, const int width, const int height, const char* url) :
		View(x, y, width, height)
	{
		texConverter = nullptr;
		isClosing = false;

		//Setup texture
		alphafunc = zRND_ALPHA_FUNC_BLEND;
		initTextureFormat();
		clearBuffer();

		//Setup Cef
		CefWindowInfo windowInfo;
		windowInfo.SetAsWindowless(nullptr);

		CefBrowserSettings browserSettings;
		browserSettings.web_security = STATE_ENABLED;
		browserSettings.file_access_from_file_urls = STATE_ENABLED;
		browserSettings.universal_access_from_file_urls = STATE_ENABLED;

		CefBrowserHost::CreateBrowserSync(windowInfo, this, url, browserSettings, nullptr, nullptr);
		objectList.push_back(this);

		g2o::ClientEventHandlers::onMouseClickHandler.emplace_back([this](const Int key)
			{
				sendMouseClickEvent(key, false);
			});

		g2o::ClientEventHandlers::onMouseReleaseHandler.emplace_back([this](const Int key)
			{
				sendMouseClickEvent(key, true);
			});

		g2o::ClientEventHandlers::onMouseMoveHandler.emplace_back([this](const Int x, const Int y)
			{
				sendMouseMoveEvent(x, y);
			});
		g2o::ClientEventHandlers::onMouseWheelHandler.emplace_back([this](const Int z)
			{
				sendMouseWheelEvent(z);
			});

		C_F->setCursorVisible(true);
	}

	Browser::~Browser()
	{
		browser = nullptr;
		auto result = std::ranges::remove(objectList, this);
		objectList.erase(result.begin(), result.end());
	}

	bool Browser::setUrl(const char* url) const
	{
		if (!browser) return false;

		const CefRefPtr<CefFrame> frame = browser->GetMainFrame();

		//TODO: optional POST data
		frame->LoadURL(url);

		return true;
	}

	const char* Browser::getUrl() const
	{
		if (!browser) return "";

		const CefRefPtr<CefFrame> frame = browser->GetMainFrame();

		return frame->GetURL().ToString().c_str();
	}

	void Browser::processKeyboardEvents(const CefKeyEvent& keyEvent)
	{
		for (auto&& browserObject : objectList)
		{
			if (browserObject->browser)
				browserObject->browser->GetHost()->SendKeyEvent(keyEvent);
		}
	}

	CefRefPtr<CefRenderHandler> Browser::GetRenderHandler()
	{
		return this;
	}

	CefRefPtr<CefLifeSpanHandler> Browser::GetLifeSpanHandler()
	{
		return this;
	}

	void Browser::GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect)
	{
		if (!isClosing)
			rect = { 0, 0, static_cast<int>(size[0]), static_cast<int>(size[1]) };
		else
			rect = { 0, 0, 1, 1 };
	}

	void Browser::OnAfterCreated(const CefRefPtr<CefBrowser> browser)
	{
		this->browser = browser;
	}

	void Browser::OnBeforeClose(CefRefPtr<CefBrowser> browser)
	{
		isClosing = true;
		browser = nullptr;
	}

	void Browser::OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects, const void* buffer, int width, const int height)
	{
		if (isClosing)
			return;

		if (!texConverter)
		{
			if (backTex->Lock(0))
			{
				void* srcBuffer = nullptr;
				int pitchXBytes = 0;

				// Copy CEF frame to srcBuffer buffer
				if (backTex->GetTextureBuffer(0, srcBuffer, pitchXBytes))
					memcpy(srcBuffer, buffer, pitchXBytes * height);

				backTex->Unlock();
			}
		}
		else
		{
			if (texConverter->Lock(0))
			{
				// Copy CEF frame to texConverter buffer
				void* srcBuffer = nullptr;
				int pitchXBytes = 0;

				if (texConverter->GetTextureBuffer(0, srcBuffer, pitchXBytes))
					memcpy(srcBuffer, buffer, pitchXBytes * height);

				// Copy scaled image to backTex
				backTex->Lock(0);

				void* dstBuffer = nullptr;
				if (backTex->GetTextureBuffer(0, dstBuffer, pitchXBytes))
				{
					int srcSize[] = { texConverter->GetTextureInfo().sizeX, texConverter->GetTextureInfo().sizeY };
					const int dstSize[] = { backTex->GetTextureInfo().sizeX, backTex->GetTextureInfo().sizeY };

					resizeTexture(srcSize, dstSize[VX], dstSize[VY], srcBuffer, dstBuffer, scaleFormat);
				}

				texConverter->Unlock();
				backTex->Unlock();
			}
		}
	}
	void Browser::clearBuffer() const
	{
		if (backTex->Lock(0))
		{
			int pitchXBytes = 0;

			const zCTextureInfo texInfo = backTex->GetTextureInfo();

			if (void* srcBuffer = nullptr; backTex->GetTextureBuffer(0, srcBuffer, pitchXBytes))
				memset(srcBuffer, 0x0, pitchXBytes * texInfo.sizeY);

			backTex->Unlock();
		}
	}

	void Browser::initTextureFormat()
	{
		backTex = zrenderer->CreateTexture();

		zCTextureInfo texInfo;
		texInfo.numMipMap = 1;
		texInfo.texFormat = zRND_TEX_FORMAT_BGRA_8888;
		scaleFormat = formatBGRA8888;
		correctPow2(texInfo.sizeX = size[0], texInfo.sizeY = size[1]);

		if (backTex->Lock(0))
		{
			backTex->SetTextureInfo(texInfo);
			backTex->Unlock();
		}

		if (texInfo.sizeX != size[0] || texInfo.sizeY != size[1])
		{
			texInfo.sizeX = size[0];
			texInfo.sizeY = size[1];

			texConverter = zrenderer->CreateTextureConvert();
			texConverter->SetTextureInfo(texInfo);
		}
	}

	void Browser::correctPow2(int& xsize, int& ysize)
	{
		int xdim = 1, ydim = 1;

		do { xdim <<= 1; } while (xdim < xsize);
		do { ydim <<= 1; } while (ydim < ysize);

		xsize = xdim;
		ysize = ydim;
	}

	std::optional<CefBrowserHost::MouseButtonType> getMouseType(const Int key)
	{
		if (key == ClientConstants::MOUSE_LMB)
		{
			SH_F->print("LMB");
			return std::make_optional(CefBrowserHost::MouseButtonType::MBT_LEFT);
		}
		if (key == ClientConstants::MOUSE_MMB)
		{
			SH_F->print("MMB");
			return  std::make_optional(CefBrowserHost::MouseButtonType::MBT_MIDDLE);
		}
		if (key == ClientConstants::MOUSE_RMB)
		{
			SH_F->print("RMB");
			return std::make_optional(CefBrowserHost::MouseButtonType::MBT_RIGHT);
		}
		return std::nullopt;
	}

	void Browser::sendMouseClickEvent(const Int key, const bool isUp)
	{
		if (!browser) return;

		CefMouseEvent mouseEvent;
		const auto type = getMouseType(key);

		auto [mouseX, mouseY] = mousePos;
		mouseEvent.x = mouseX;
		mouseEvent.y = mouseY;

		if (type.has_value())
		{
			mouseFlags[type.value()] = isUp;
			browser->GetHost()->SendMouseClickEvent(mouseEvent, type.value(), isUp, 1);
		}
	}

	void Browser::sendMouseMoveEvent(const Int x, const Int y)
	{
		if (!browser) return;

		auto [cursorX, cursorY] = C_F->getCursorPositionPx().toTuple();
		auto [windowX, windowY] = getPositionPx().toTuple();

		CefMouseEvent mouseEvent;
		auto& [mouseX, mouseY] = mousePos;
		mouseX = cursorX - windowX;
		mouseY = cursorY - windowY;

		mouseEvent.x = mouseX;
		mouseEvent.y = mouseY;

		if (mouseFlags[CefBrowserHost::MouseButtonType::MBT_LEFT])
			mouseEvent.modifiers |= EVENTFLAG_LEFT_MOUSE_BUTTON;
		if (mouseFlags[CefBrowserHost::MouseButtonType::MBT_MIDDLE])
			mouseEvent.modifiers |= EVENTFLAG_MIDDLE_MOUSE_BUTTON;
		if (mouseFlags[CefBrowserHost::MouseButtonType::MBT_RIGHT])
			mouseEvent.modifiers |= EVENTFLAG_RIGHT_MOUSE_BUTTON;

		browser->GetHost()->SendMouseMoveEvent(mouseEvent, false);

		SH_F->print("cursorX: " + std::to_string(cursorX) + " cursorY: " + std::to_string(cursorY));
		SH_F->print("windowX: " + std::to_string(windowX) + " windowY: " + std::to_string(windowY));
	}

	void Browser::sendMouseWheelEvent(const Int z)
	{
		if (!browser) return;

		CefMouseEvent mouseEvent;
		auto [mouseX, mouseY] = mousePos;
		mouseEvent.x = mouseX;
		mouseEvent.y = mouseY;

		browser->GetHost()->SendMouseWheelEvent(mouseEvent, 0, z * 100);
	}
}
