#pragma once
#include "scene.h"
#include <Surface.h>
#include <SpriteBatch.h>
#include <FontManager.h>

class Intro : public Scene
{
	Surface image;
	SpriteBatch* sb;
	FontManager* fm;

public:
	Intro(Game* game, int allocatedFrames = 100, Transition* transition = nullptr);
	~Intro();

	void LoadContent();
	void Update();
	void Draw();
};
