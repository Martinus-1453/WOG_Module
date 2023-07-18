#include "Browser.h"

const unsigned long formatBGRA8888 = 7;

char* resizeTexture(int* srcsize, int dstx, int dsty, void* src, void* dest, unsigned long fmt)
{
	XCALL(0x00659670);
}

namespace wog
{
	Browser::Browser(int x, int y, int width, int height, const char* url) :
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
	}

	Browser::~Browser()
	{
		browser = nullptr;
	}

	bool Browser::setUrl(const char* url)
	{
		if (!browser)
			return false;

		CefRefPtr<CefFrame> frame = browser->GetMainFrame();

		//TODO: optional POST data
		frame->LoadURL(url);

		return true;
	}

	const char* Browser::getUrl()
	{
		if (!browser)
			return "";

		CefRefPtr<CefFrame> frame = browser->GetMainFrame();

		return frame->GetURL().ToString().c_str();
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

	void Browser::OnAfterCreated(CefRefPtr<CefBrowser> browser)
	{
		browser = browser;
	}

	void Browser::OnBeforeClose(CefRefPtr<CefBrowser> browser)
	{
		isClosing = true;
		browser = nullptr;
	}

	void Browser::OnPaint(CefRefPtr<CefBrowser> browser, CefRenderHandler::PaintElementType type, const CefRenderHandler::RectList& dirtyRects, const void* buffer, int width, int height)
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
		texInfo.texFormat = zTRnd_TextureFormat::zRND_TEX_FORMAT_BGRA_8888;
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
}
