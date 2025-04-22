#pragma once
#include "Scene.h"
#include <Surface.h>
#include <SpriteBatch.h>
#include <FontManager.h>

class TheEnd : public Scene
{
	SpriteBatch* sb;
	FontManager* fm;

public:
	TheEnd(Game* game, int allocatedFrames = 100, Transition* transition = nullptr);
	~TheEnd();

	void LoadContent();
	void Update();
	void Draw();
};
