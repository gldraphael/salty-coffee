#pragma once
#include "scene.h"
#include <Surface.h>
#include <SpriteBatch.h>
#include <FontManager.h>
#include "Character.h"

class Taste : public Scene
{
	Surface image;
	SpriteBatch* sb;
	FontManager* fm;

	Character* Girl,* Friend;

public:
	Taste(Game* game, int allocatedFrames = 100, Transition* transition = nullptr);
	~Taste();

	void LoadContent();
	void Update();
	void Draw();
};
