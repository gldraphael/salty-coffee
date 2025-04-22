// 17 January, 2012

#pragma once
#include <Game.h>
#include <vector>
#include "Scene.h"
#include <AudioEngine.h>
#include <FontManager.h>
#include "StatusBar.h"
// #include "AnimatedSprite.h"
#include "Character.h"

class CIA :	public Game
{
	bool debugMode;

	// Scenes to be played
	std::vector <Scene*> Scenes;

	// Scene currently being played
	unsigned int currentScene;

	// The fontManager
	// Use Game::Services["fontmanager"] to access it
	FontManager fontManager;

	// The Audio Engine
	// Use Game::Services["audioengine"] to access it
	AudioEngine audioEngine;

	// The Status bar for debugging
	StatusBar* debugBar;
	// Status Bar for speech
	StatusBar* speechBar;

	// The Guy
	// Use Game::Services["guy"] to access it
	Character* Guy;

	// The Girl
	// Use Game::Services["girl"] to access it
	Character* Girl;

public:

	CIA(bool debugMode = false);
	
	// Initializes variables
	void Initialize();

	// Loads graphics and sounds
	void LoadContent();

	// Updates the variables
	void Update();

	// Draws the screen
	void Draw();

	// Unloads the scenes
	void UnloadContent();

	~CIA();

	bool isDebugMode();
};
