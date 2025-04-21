#pragma once
class Game;

#include <Surface.h>
#include <vector>
#include <structs.h>
#include <SpriteBatch.h>

// This class represents a character
class Character
{
public:
	// The different animations
	enum class Animation
	{
		RIGHT = 0,			// Row 0 in the sprite sheet
		LEFT = 1,
		COFFEE = 2,
		ROSE = 3
	};

private:
	Game* game;
	Surface sheet;
	SpriteBatch* sb;
	bool isAnimating;
	std::vector< std::vector<Rectangle> > rects;
	std::string filename;
	Point frameSize;
	Point position;
	Animation currentAnimation;
	int currentFrame;
	int speed;

public:

#pragma region Properties

	// Returns the current animation status
	bool IsAnimating();
	// Set the current position of the 
	void SetPosition(Point position);
	// Returns the position of the sprite
	Point GetPosition();
	// Set the speed of the sprite
	void SetSpeed(int speed);
	// Returns the speed of the sprite
	int GetSpeed();
	// Returns the size of a sprite
	Point GetSize();
#pragma endregion

#pragma region Animation Controllers

	// Animates the animation using the giving argument
	void Animate(Character::Animation animation);
	// Sets the animation
	void SetAnimation(Character::Animation animation);
	// Animates the Character
	void Animate();
	// Stops the animation
	void StopAnimation();

#pragma endregion

	Character(Game* game, std::string filename, Point frameSize = Point(32,32) , int framesPerAnimation = 6, int Animations = 4, Point position = Point(), int speed = 1);
	~Character();

#pragma region Loop

	void Initialize();
	void LoadContent();
	void Update(int currentFrame, int skip = 5);
	void Draw();

#pragma endregion
};
