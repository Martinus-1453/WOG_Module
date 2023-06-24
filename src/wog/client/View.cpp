#include "View.h"

namespace wog
{
	View::View(int x, int y, int width, int height) :
		zCView(0, 0, 0, 0),
		_position(screen->nax(x), screen->nay(y)),
		_size(screen->nax(width), screen->nay(height))
	{
		//Create vertices
		_vertices.emplace_back(zTRndSimpleVertex{ _position, 0.0f, zVEC2(0.0f, 0.0f), zCOLOR(255, 255, 255, 255)});
		_vertices.emplace_back(zTRndSimpleVertex{ zVEC2(_position[0] + _size[0], _position[1]), 0.0f, zVEC2(1.0f, 0.0f), zCOLOR(255, 255, 255, 255)});
		_vertices.emplace_back(zTRndSimpleVertex{ _position + _size, 0.0f, zVEC2(1.0f, 1.0f), zCOLOR(255, 255, 255, 255) });
		_vertices.emplace_back(zTRndSimpleVertex{ zVEC2(_position[0], _position[1] + _size[1]), 0.0f, zVEC2(0.0f, 1.0f), zCOLOR(255, 255, 255, 255)});
	}

	void View::top()
	{
		Top();
	}

	void View::setColor(int r, int g, int b)
	{
		color.r = r;
		color.g = g;
		color.b = b;
	}

	void View::setAlpha(int alpha)
	{
		color.alpha = alpha;
	}

	void View::setPosition(int x, int y)
	{
		_position[0] = screen->nax(x);
		_position[1] = screen->nay(y);

		updateVertices();
	}

	void View::setPositionPx(int x, int y)
	{
		_position[0] = x;
		_position[1] = y;

		updateVertices();
	}

	void View::setSize(int width, int height)
	{
		_size[0] = screen->nax(width);
		_size[1] = screen->nay(height);

		updateVertices();
	}

	void View::setSizePx(int width, int height)
	{
		_size[0] = width;
		_size[1] = height;

		updateVertices();
	}

	void View::setVisible(bool visible)
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

	g2o::Color View::getColor()
	{
		g2o::Color color;
		color.r = this->color.r;
		color.g = this->color.g;
		color.b = this->color.b;

		return color;
	}

	int View::getAlpha()
	{
		return color.alpha;
	}

	g2o::Position2d View::getPosition()
	{
		g2o::Position2d position;
		position.x = screen->nax(_position[0]);
		position.y = screen->nay(_position[1]);

		return position;
	}

	g2o::Position2d View::getPositionPx()
	{
		g2o::Position2d position;
		position.x = _position[0];
		position.y = _position[1];

		return position;
	}

	g2o::Size2d View::getSize()
	{
		g2o::Size2d size;
		size.width = screen->nax(_size[0]);
		size.height = screen->nay(_size[1]);

		return size;
	}

	g2o::Size2d View::getSizePx()
	{
		g2o::Size2d size;
		size.width = _size[0];
		size.height = _size[1];

		return size;
	}

	bool View::getVisible()
	{
		return ondesk;
	}

	const char* View::getFilename()
	{
		if (!backTex)
			return "";

		return backTex->GetObjectName().ToChar();
	}

	void View::Blit()
	{
		// Get positions of upper left (posMin) and lower right (posMax) corners of element
		const zVEC2& posMin = _position;
		const zVEC2 posMax = _position + _size;

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

		zBOOL oldzWrite = zrenderer->GetZBufferWriteEnabled();
		zrenderer->SetZBufferWriteEnabled(m_bFillZ);

		zTRnd_ZBufferCmp oldCmp = zrenderer->GetZBufferCompare();
		zrenderer->SetZBufferCompare(zRND_ZBUFFER_CMP_ALWAYS);

		zTRnd_AlphaBlendFunc oldBlendFunc = zrenderer->GetAlphaBlendFunc();
		zrenderer->SetAlphaBlendFunc(alphafunc);

		zBOOL oldBilerpFilter = zrenderer->GetBilerpFilterEnabled();
		zrenderer->SetBilerpFilterEnabled(TRUE);

		// Update far z
		float farZ;

		if (m_bFillZ)
			farZ = (zCCamera::activeCam) ? zCCamera::activeCam->farClipZ - 1.0f : 65534.0f;
		else
			farZ = (zCCamera::activeCam) ? zCCamera::activeCam->nearClipZ + 1.0f : 1.0f;

		for (auto& vert : _vertices)
			vert.z = farZ;

		zrenderer->DrawPolySimple(backTex, _vertices.data(), _vertices.size());

		// Restoring old values (defaults in zrenderer)
		zrenderer->SetBilerpFilterEnabled(oldBilerpFilter);
		zrenderer->SetAlphaBlendFunc(oldBlendFunc);
		zrenderer->SetZBufferWriteEnabled(oldzWrite);
		zrenderer->SetZBufferCompare(oldCmp);
	}

	void View::updateVertices()
	{
		_vertices[0].pos = _position;
		_vertices[1].pos = zVEC2(_position[0] + _size[0], _position[1]);
		_vertices[2].pos = _position + _size;
		_vertices[3].pos = zVEC2(_position[0], _position[1] + _size[1]);
	}
}