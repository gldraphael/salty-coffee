#pragma once
#include "Scene.h"
#include <Surface.h>
#include <SpriteBatch.h>
#include <FontManager.h>
#include "Character.h"
#include "StatusBar.h"
#include <AudioEngine.h>

class Ask : public Scene
{
	Surface image;
	Surface front;

	SpriteBatch* sb;
	FontManager* fm;
	StatusBar* speech;
	AudioEngine* ae;

	Character *Girl, *Guy;

public:
	Ask(Game* game, int allocatedFrames = 100, Transition* transition = nullptr);
	~Ask();

	void LoadContent();
	void Update();
	void Draw();
};
