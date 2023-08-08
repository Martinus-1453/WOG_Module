#include "Browser.h"

#include "ClientInit.h"
#include "event/ClientEventHandlers.h"
#include "function/ClientFunctions.h"
#include "function/SharedFunctions.h"

#include <fstream>
#include <include/wrapper/cef_message_router.h>

const unsigned long formatBGRA8888 = 7;

char* resizeTexture(int* srcsize, int dstx, int dsty, void* src, void* dest, unsigned long fmt)
{
	XCALL(0x00659670);
}

void SaveBrowserImage(const char* filename, const void* buffer, int width, int height)
{
	// Populate the bitmap info header.
	BITMAPINFOHEADER info;
	info.biSize = sizeof(BITMAPINFOHEADER);
	info.biWidth = width;
	info.biHeight = -height;  // minus means top-down bitmap
	info.biPlanes = 1;
	info.biBitCount = 32;
	info.biCompression = BI_RGB;  // no compression
	info.biSizeImage = 0;
	info.biXPelsPerMeter = 1;
	info.biYPelsPerMeter = 1;
	info.biClrUsed = 0;
	info.biClrImportant = 0;

	// Create the bitmap and retrieve the bit buffer.
	HDC screen_dc = GetDC(NULL);
	void* bits = NULL;
	HBITMAP bitmap = CreateDIBSection(screen_dc, reinterpret_cast<BITMAPINFO*>(&info), DIB_RGB_COLORS, &bits, NULL, 0);
	ReleaseDC(NULL, screen_dc);

	// Read the image into the bit buffer.
	if (bitmap == NULL)
		return;

	memcpy(bits, buffer, width * height * 4);

	// Populate the bitmap file header.
	BITMAPFILEHEADER file;
	file.bfType = 0x4d42;
	file.bfSize = sizeof(BITMAPFILEHEADER);
	file.bfReserved1 = 0;
	file.bfReserved2 = 0;
	file.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	// Write the bitmap to file.
	HANDLE file_handle = CreateFile(filename, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (file_handle != INVALID_HANDLE_VALUE)
	{
		DWORD bytes_written = 0;
		WriteFile(file_handle, &file, sizeof(file), &bytes_written, 0);
		WriteFile(file_handle, &info, sizeof(info), &bytes_written, 0);
		WriteFile(file_handle, bits, width * height * 4, &bytes_written, 0);
		CloseHandle(file_handle);
	}

	DeleteObject(bitmap);
}

namespace wog
{
	Browser::Browser(const int x, const int y, const int width, const int height, const char* url) :
		View(x, y, width, height), m_resourceManager(new CefResourceManager)
	{
		isClosing = false;

		//Setup texture
		alphafunc = zRND_ALPHA_FUNC_BLEND;
		initTexture();
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

	static void blabla(CefRefPtr<CefFrame> frame)
	{
		auto msg = CefProcessMessage::Create("chleb");
		frame->SendProcessMessage(PID_BROWSER, msg);
	}

	bool Browser::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefProcessId source_process, CefRefPtr<CefProcessMessage> message)
	{
		if (message->GetName() == "chleb")
		{
			if (!CefCurrentlyOn(TID_IO)) {
				// Execute on the browser IO thread.
				CefPostTask(TID_IO,base::Bind(&blabla, frame));
				return true;
			}
			//auto str = CefV8Value::CreateString("bep!");
			//auto context = frame->GetV8Context();
			//context->GetGlobal()->SetValue("chleb", str, V8_PROPERTY_ATTRIBUTE_NONE);

			return true;
		}
		return false;
	}

	CefRefPtr<CefRenderHandler> Browser::GetRenderHandler()
	{
		return this;
	}

	CefRefPtr<CefLifeSpanHandler> Browser::GetLifeSpanHandler()
	{
		return this;
	}

	CefRefPtr<CefResourceHandler> Browser::GetResourceHandler(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
		CefRefPtr<CefRequest> request)
	{
		return m_resourceManager->GetResourceHandler(browser, frame, request);
	}

	CefRefPtr<CefResourceRequestHandler> Browser::GetResourceRequestHandler(CefRefPtr<CefBrowser> cefBrowser,
		CefRefPtr<CefFrame> cefFrame, CefRefPtr<CefRequest> cefRequest, bool cond, bool cond1,
		const CefString& cefStringUtf16, bool& cond2)
	{
		return this;
	}

	CefRefPtr<CefRequestHandler> Browser::GetRequestHandler()
	{ return this; }

	cef_return_value_t Browser::OnBeforeResourceLoad(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
	                                                 CefRefPtr<CefRequest> request, CefRefPtr<CefRequestCallback> callback)
	{
		return m_resourceManager->OnBeforeResourceLoad(browser, frame, request, callback);
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

		if (backTex->Lock(0))
		{
			void* srcBuffer = nullptr;
			int pitchXBytes = 0;

			// Copy CEF frame to texture buffer
			if (backTex->GetTextureBuffer(0, srcBuffer, pitchXBytes))
			{
				char* textureBuffer = reinterpret_cast<char*>(srcBuffer);
				char* cefBuffer = reinterpret_cast<char*>(const_cast<void*>(buffer));

				for (auto i = 0; i < height; ++i)
				{
					memcpy(textureBuffer, cefBuffer, width * 4);
					textureBuffer += pitchXBytes;
					cefBuffer += width * 4;
				}
			}

			backTex->Unlock();
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

	void Browser::initTexture()
	{
		zCTextureInfo texInfo;
		texInfo.numMipMap = 1;
		texInfo.texFormat = zRND_TEX_FORMAT_BGRA_8888;
		correctPow2(texInfo.sizeX = size[0], texInfo.sizeY = size[1]);

		backTex = zrenderer->CreateTexture();
		backTex->SetTextureInfo(texInfo);

		setUV(0.0f, 0.0f, size[0] / texInfo.sizeX, size[1] / texInfo.sizeY);
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
