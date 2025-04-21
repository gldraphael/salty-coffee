#pragma once
#include <Surface.h>
#include <Color.h>
#include <FontManager.h>
#include <SpriteBatch.h>

// Forward declaration
class Game;

// A Status bar control
class StatusBar
{
	// Visibility of the status bar
	bool visible;

	// The background image
	Surface image;

	// The position at which the status bar is to be shown
	Point position;

	// The padding with respect to the top left of the status bar
	Point padding;

	// The text to be rendered
	std::string current_string;

	// The color in which the text is to be rendered
	Color current_color;

	// The current application instance
	Game* game;

	// The font Manager
	FontManager* fm;

	// The font used for rendering
	std::string font;

	// The sprite batch used to render text
	SpriteBatch* sb;

public:
	StatusBar(Game* game, Surface image, FontManager* fontManager, std::string font, SpriteBatch* sb, Point position);
	~StatusBar();

	// Shows the status bar
	void Show (std::string message, Color color);

	// Draws the status bar
	void Draw ();

	// Hides the Status bar
	void Hide();

	// Resets the text
	void ResetText();

	Point GetPosition();
};
