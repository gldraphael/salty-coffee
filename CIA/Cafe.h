#pragma once
#include "Scene.h"
#include <Surface.h>
#include <SpriteBatch.h>
#include <FontManager.h>
#include "Character.h"
#include "StatusBar.h"

class Cafe : public Scene
{
	Surface image;
	SpriteBatch* sb;
	FontManager* fm;
	bool txt;
	Character* Girl,* Guy;
	StatusBar* speech;

public:
	Cafe(Game* game, int allocatedFrames = 100, Transition* transition = nullptr);
	~Cafe();

	void LoadContent();
	void Update();
	void Draw();
};
