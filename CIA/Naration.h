#pragma once
#include "Scene.h"
#include <Surface.h>
#include <SpriteBatch.h>
#include <FontManager.h>

class Narration : public Scene
{
	Surface image;
	SpriteBatch* sb;
	FontManager* fm;

public:
	Narration(Game* game, int allocatedFrames = 100, Transition* transition = nullptr);
	~Narration();

	void LoadContent();
	void Update();
	void Draw();
};
