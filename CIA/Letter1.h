#pragma once
#include "Scene.h"
#include <Surface.h>
#include <SpriteBatch.h>
#include <FontManager.h>

class Letter1 : public Scene
{
	Surface image;
	SpriteBatch* sb;
	FontManager* fm;

public:
	Letter1(Game* game, int allocatedFrames = 100, Transition* transition = nullptr);
	~Letter1();

	void LoadContent();
	void Update();
	void Draw();
};
