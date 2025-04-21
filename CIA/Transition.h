// 17 January, 2013

#pragma once
class Game;

// A Transition represents a transition from one scene to another
// and can be appended to the end of a scene ONLY
// Events won't be handled while a transition is being played
class Transition
{

private:
	Game* game;
	bool transitionOver;
	int currentFrame;
	int allocatedFrames;

public:

	// Allocated Frames for the current transition
	// Default is 100 frames i.e. 5 secs
	// 1sec = 20 frames
	Transition(int allocatedFrames = 100);
	~Transition();
	
	// Initializes the Transition object
	// game is the current instance of the application
	// Use the "this" keyword
	void Initialize(Game* game);

	void Update();
	void Draw();

	// Returns true if transition is over
	bool Run();
};