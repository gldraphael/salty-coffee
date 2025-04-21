#pragma once
#include "Transition.h"

class Game;

// A Base class representing a Scene
// Derive your own scene from this class
class Scene
{
	Game* game;
	Transition* transition;
	int allocatedFrames;
	int currentFrame;
	bool sceneOver;
public:

	// game is the current instance of the application
	// Use the "this" keyword
	// Allocated Frames for the current scene
	// Default is 100 frames i.e. 5 secs
	// 1sec = 20 frames
	// transition is the ending transition to be played
	Scene(Game* game, int allocatedFrames = 100, Transition* transition = nullptr);

	~Scene();

	// Override this to initialize your scene variables
	virtual void Initialize();

	// Pure Virtual Function: Load your scene contents here
	virtual void LoadContent() = 0;

	// Override this to Unload scene contents
	virtual void UnloadContent();

	// Override this to Update the scene variables
	virtual void Update();

	// Override this to animate the scene
	virtual void Draw();

	// Returns true if the scene is over
	bool isSceneOver();
	// Returns the current instance of the application
	Game* GetGameInstance();
	// Returns the current frame
	int GetCurrentFrame();

};