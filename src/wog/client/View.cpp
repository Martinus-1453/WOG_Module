#include "View.h"

namespace wog
{
	View::View(int x, int y, int width, int height) :
		zCView(0, 0, 0, 0),
		position(screen->nax(x), screen->nay(y)),
		size(screen->nax(width), screen->nay(height))
	{
		//Create vertices
		zVEC2 half = zVEC2(0.5f, 0.5f); //Fix for DirectX half-pixel bug

		vertices.emplace_back(position - half, 0.0f, zVEC2(0.0f, 0.0f), zCOLOR(255, 255, 255, 255));
		vertices.emplace_back(zVEC2(position[0] + size[0], position[1]) - half, 0.0f, zVEC2(1.0f, 0.0f), zCOLOR(255, 255, 255, 255));
		vertices.emplace_back(position + size - half, 0.0f, zVEC2(1.0f, 1.0f), zCOLOR(255, 255, 255, 255));
		vertices.emplace_back(zVEC2(position[0], position[1] + size[1]) - half, 0.0f, zVEC2(0.0f, 1.0f), zCOLOR(255, 255, 255, 255));
	}

	void View::top()
	{
		Top();
	}

	void View::setColor(const int r, const int g, const int b)
	{
		color.r = r;
		color.g = g;
		color.b = b;
	}

	void View::setAlpha(const int alpha)
	{
		color.alpha = alpha;
	}

	void View::setPosition(const int x, const int y)
	{
		position[0] = screen->nax(x);
		position[1] = screen->nay(y);

		updateVertices();
	}

	void View::setPositionPx(const int x, const int y)
	{
		position[0] = x;
		position[1] = y;

		updateVertices();
	}

	void View::setSize(const int width, const int height)
	{
		size[0] = screen->nax(width);
		size[1] = screen->nay(height);

		updateVertices();
	}

	void View::setSizePx(const int width, const int height)
	{
		size[0] = width;
		size[1] = height;

		updateVertices();
	}

	void View::setVisible(const bool visible)
	{
		if (bool(ondesk) == visible)
			return;

		if (visible)
			screen->InsertItem(this);
		else
			screen->RemoveItem(this);
	}

	void View::setFilename(const char* filename)
	{
		InsertBack(filename);
	}

	void View::setUV(float x, float y, float width, float height)
	{
		uv[0] = x;
		uv[1] = y;
		uv[2] = width;
		uv[3] = height;

		vertices[0].uv = { x, y };
		vertices[1].uv = { x + width, y };
		vertices[2].uv = { x + width, y + height };
		vertices[3].uv = { x, y + height };
	}

	g2o::Color View::getColor() const
	{
		g2o::Color color;
		color.r = this->color.r;
		color.g = this->color.g;
		color.b = this->color.b;

		return color;
	}

	int View::getAlpha() const
	{
		return color.alpha;
	}

	g2o::Position2d View::getPosition()
	{
		g2o::Position2d result;
		result.x = screen->nax(position[0]);
		result.y = screen->nay(position[1]);

		return result;
	}

	g2o::Position2d View::getPositionPx()
	{
		g2o::Position2d result;
		result.x = position[0];
		result.y = position[1];

		return result;
	}

	g2o::Size2d View::getSize()
	{
		g2o::Size2d result;
		result.width = screen->nax(size[0]);
		result.height = screen->nay(size[1]);

		return result;
	}

	g2o::Size2d View::getSizePx()
	{
		g2o::Size2d result;
		result.width = size[0];
		result.height = size[1];

		return result;
	}

	bool View::getVisible() const
	{
		return ondesk;
	}

	const char* View::getFilename() const
	{
		if (!backTex)
			return "";

		return backTex->GetObjectName().ToChar();
	}

	zVEC4 View::getUV() const
	{
		return uv;
	}

	void View::Blit()
	{
		// Get positions of upper left (posMin) and lower right (posMax) corners of element
		const zVEC2& posMin = position;
		const zVEC2 posMax = position + size;

		// if element is outside the screen -> break
		if (posMin[0] > zrenderer->vid_xdim || posMin[1] > zrenderer->vid_ydim)
			return;

		if (posMax[0] < 0 || posMax[1] < 0)
			return;

		// calculating screen positions of upper left (screenPosMin) and lower right (posMax) corners of element
		const zVEC2 screenPosMin = Alg_Max(posMin, zVEC2());
		const zVEC2 screenPosMax = Alg_Min(posMax, zVEC2(zrenderer->vid_xdim, zrenderer->vid_ydim));

		// calculating screen size of element
		const zVEC2 screenSize = screenPosMax - screenPosMin;

		// if element is invisible (upperLeft == lowerRight) -> break
		if (screenSize[0] <= 0 || screenSize[1] <= 0)
			return;

		zrenderer->SetViewport(screenPosMin[0], screenPosMin[1], screenSize[0], screenSize[1]);

		const zBOOL oldzWrite = zrenderer->GetZBufferWriteEnabled();
		zrenderer->SetZBufferWriteEnabled(m_bFillZ);

		const zTRnd_ZBufferCmp oldCmp = zrenderer->GetZBufferCompare();
		zrenderer->SetZBufferCompare(zRND_ZBUFFER_CMP_ALWAYS);

		const zTRnd_AlphaBlendFunc oldBlendFunc = zrenderer->GetAlphaBlendFunc();
		zrenderer->SetAlphaBlendFunc(alphafunc);

		const zBOOL oldBilerpFilter = zrenderer->GetBilerpFilterEnabled();
		zrenderer->SetBilerpFilterEnabled(TRUE);

		// Update far z
		float farZ;

		if (m_bFillZ)
			farZ = (zCCamera::activeCam) ? zCCamera::activeCam->farClipZ - 1.0f : 65534.0f;
		else
			farZ = (zCCamera::activeCam) ? zCCamera::activeCam->nearClipZ + 1.0f : 1.0f;

		for (auto& vert : vertices)
			vert.z = farZ;

		zrenderer->DrawPolySimple(backTex, vertices.data(), vertices.size());

		// Restoring old values (defaults in zrenderer)
		zrenderer->SetBilerpFilterEnabled(oldBilerpFilter);
		zrenderer->SetAlphaBlendFunc(oldBlendFunc);
		zrenderer->SetZBufferWriteEnabled(oldzWrite);
		zrenderer->SetZBufferCompare(oldCmp);
	}

	void View::updateVertices()
	{
		vertices[0].pos = position;
		vertices[1].pos = zVEC2(position[0] + size[0], position[1]);
		vertices[2].pos = position + size;
		vertices[3].pos = zVEC2(position[0], position[1] + size[1]);
	}
}