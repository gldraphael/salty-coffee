#pragma once
#include "Scene.h"
#include <Surface.h>
#include <SpriteBatch.h>
#include <FontManager.h>

class Letter2 : public Scene
{
	Surface image;
	SpriteBatch* sb;
	FontManager* fm;

public:
	Letter2(Game* game, int allocatedFrames = 100, Transition* transition = nullptr);
	~Letter2();

	void LoadContent();
	void Update();
	void Draw();
};
