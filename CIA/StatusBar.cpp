#include "StatusBar.h"
#include <Game.h>

StatusBar::StatusBar(Game* game, Surface image,FontManager* fontManager, std::string font, SpriteBatch* spritebatch, Point position) : current_color(Color::White() )
{
	visible = false;
	this->image = image;
	current_string = " ";
	this->position = position;
	this->font = font;
	sb = spritebatch;
	fm = fontManager;
	this->game = game;
}


StatusBar::~StatusBar()
{

}

void StatusBar::Show (std::string message, Color color)
{
	visible = true;
	current_color = color;
	current_string = message;
}

void StatusBar::Draw ()
{
	// Draw the image
	sb->Draw(image, position, Color::White() );

	if (visible)
	{
		// Draw the text
		sb->DrawString ( fm->GetFont(font),																												// Font
			current_string,																																// Text
			Point( (game->GetScreenBounds().X - fm->MeasureString(font, const_cast<char*>(current_string.c_str()) ).X )/2, position.Y),					// Position
			current_color);																																// Colour
	}
}

void StatusBar::Hide()
{
	visible = false;
}

Point StatusBar::GetPosition()
{
	return position;
}

void StatusBar::ResetText()
{
	this->current_string = " ";
}