#include "SpriteBatch.h"
#include <SDL/SDL_ttf.h>
#include <sstream>

SpriteBatch::SpriteBatch(GraphicsDevice* graphicsDevice)
{
	this->graphicsDevice = graphicsDevice;
}

void SpriteBatch::Draw(const Surface& surface, const Rectangle& destinationRectangle)
{
	SDL_BlitSurface(surface.GetSurface(), NULL, graphicsDevice->Window(), &(SDL_Rect)destinationRectangle);
}

void SpriteBatch::Draw(const Surface& surface, const Rectangle& destinationRectangle, const Color& color)
{
	SDL_BlitSurface (surface.GetSurface(), NULL, graphicsDevice->Window(), &(SDL_Rect)destinationRectangle);
}

void SpriteBatch::Draw(const Surface& surface, const Point& position)
{
	SDL_BlitSurface (surface.GetSurface(), NULL, graphicsDevice->Window(), &(SDL_Rect)Rectangle(position,surface.GetSurface()->w,surface.GetSurface()->h));
}

void SpriteBatch::Draw(const Surface& surface, const Point& position, const Color& color)
{
	SDL_BlitSurface (surface.GetSurface(), NULL, graphicsDevice->Window(), &(SDL_Rect)Rectangle(position,surface.GetSurface()->w,surface.GetSurface()->h));
}

void SpriteBatch::Draw(const Surface& surface, const Rectangle& destinationRectangle, const Rectangle& sourceRectangle)
{
	SDL_BlitSurface (surface.GetSurface(), &(SDL_Rect)sourceRectangle, graphicsDevice->Window(), &(SDL_Rect)destinationRectangle);
}

void SpriteBatch::Draw(const Surface& surface, const Rectangle& destinationRectangle, const Rectangle& sourceRectangle, const Color& color)
{
	SDL_BlitSurface (surface.GetSurface(), &(SDL_Rect)sourceRectangle, graphicsDevice->Window(), &(SDL_Rect)destinationRectangle);
}

void SpriteBatch::Draw(const Surface& surface, const Point& position, const Rectangle& sourceRectangle)
{
	SDL_BlitSurface (surface.GetSurface(), &((SDL_Rect)sourceRectangle), graphicsDevice->Window(), &(SDL_Rect)Rectangle(position, sourceRectangle.Width, sourceRectangle.Height));
}

void SpriteBatch::Draw(const Surface& surface, const Point& position, const Rectangle& sourceRectangle, const Color& color)
{
	Rectangle drect(position, sourceRectangle.Width, sourceRectangle.Height);
	SDL_BlitSurface (surface.GetSurface(), &((SDL_Rect)sourceRectangle), graphicsDevice->Window(), &((SDL_Rect)drect));
}

void SpriteBatch::DrawString(TTF_Font* font, const std::string& text, const Point& position, const Color& color,TextRenderMode mode)
{
	if (text == "")
		return;
	if (mode == TextRenderMode::SOLID)
		Draw(Surface ( TTF_RenderText_Solid(font, text.c_str(), color)) ,position,color );
	else
		Draw(Surface ( TTF_RenderText_Blended(font, text.c_str(), color)) ,position,color );
}

void SpriteBatch::DrawString(TTF_Font* font, const std::stringstream& text, const Point& position, const Color& color,TextRenderMode mode)
{
	if (text.str() == "")
		return;
	if(mode == TextRenderMode::SOLID)
		Draw(Surface (TTF_RenderText_Solid(font, text.str().c_str(), color)) ,position);
	else
		Draw(Surface (TTF_RenderText_Blended(font, text.str().c_str(), color)) ,position);
}

void SpriteBatch::DrawString(TTF_Font* font, char* text, const Point& position, const Color& color,TextRenderMode mode)
{
	if (text == "")
		return;
	if(mode == TextRenderMode::SOLID)
		Draw(Surface (TTF_RenderText_Solid(font, text, color)) ,position);
	else
		Draw(Surface (TTF_RenderText_Blended(font, text, color)) ,position);
}

SpriteBatch::~SpriteBatch(void)
{

}
