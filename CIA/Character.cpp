#include "Character.h"
#include <Game.h>

// Animates the animation using the giving argument
void Character::Animate(Character::Animation animation)
{
	SetAnimation(animation);
	Animate();
}

// Sets the animation
void Character::SetAnimation(Character::Animation animation)
{
	currentAnimation = animation;
}

// Set the current position of the 
void Character::SetPosition(Point position)
{
	this->position = position;
}

// Returns the position of the sprite
Point Character::GetPosition()
{
	return position;
}

// Animates the Character
void Character::Animate()
{
	isAnimating = true;
}

// Stops the animation
void Character::StopAnimation()
{
	isAnimating = false;
	currentFrame = 0;
}

Point Character::GetSize()
{
	return frameSize;
}

// Set the speed of the sprite
void Character::SetSpeed(int speed)
{
	this->speed = speed;
}

// Returns the speed of the sprite
int Character::GetSpeed()
{
	return speed;
}

// Returns the current animation status
bool Character::IsAnimating()
{
	return isAnimating;
}

Character::Character(Game* game, std::string filename, Point frameSize, int framesPerAnimation, int Animations, Point position, int speed)
{
	this->game = game;
	this->filename = filename;
	this->frameSize = frameSize;
	this->position = position;
	this->speed = speed;

	isAnimating = false;
	currentFrame = 0;
	currentAnimation = Animation(0);

	for(int i = 0; i < Animations; i ++ )
	{
		rects.push_back(std::vector<Rectangle>());
		for(int j = 0; j < framesPerAnimation; j++ )
			rects[i].push_back(Rectangle(j * frameSize.X, i * frameSize.Y, frameSize.X, frameSize.Y));
	}
}

void Character::Initialize()
{

}

void Character::LoadContent()
{
	sheet = Surface::Load(filename, ImageFormat::PNG);
	sb = reinterpret_cast<SpriteBatch*>( game->Services["spritebatch"] );
}

void Character::Update(int currentFrame, int skip)
{
	if(isAnimating )
	{
		if(currentFrame%skip == 0)
		{
			this->currentFrame++;
			if (this->currentFrame == rects[static_cast<int>(currentAnimation)].size())
				this->currentFrame = 1;
		}

		switch (currentAnimation)
		{
		case Character::Animation::RIGHT:
			position.X += speed;
			break;
		case Character::Animation::LEFT:
			position.X -= speed;
			break;
		case Character::Animation::COFFEE:
			break;
		case Character::Animation::ROSE:
			break;
		default:
			break;
		}
	}
}

void Character::Draw()
{
	// Draw the appropriate part from the spritesheet
	sb->Draw(sheet, position, rects[ static_cast<int>(currentAnimation)][currentFrame], Color::White() );
}

Character::~Character()
{

}
