#pragma once
#include "Scene.h"
#include <Surface.h>
#include <SpriteBatch.h>
#include <FontManager.h>

class Flashback : public Scene
{
	Surface image;
	Surface heart;
	Surface boy, girl;
	bool back, b, g, h;
	int i;

	SpriteBatch* sb;
	FontManager* fm;

public:
	Flashback(Game* game, int allocatedFrames = 100, Transition* transition = nullptr);
	~Flashback();

	void LoadContent();
	void Update();
	void Draw();
};
