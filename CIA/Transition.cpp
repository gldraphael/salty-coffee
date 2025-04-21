// 17 January, 2013

#include "Transition.h"
#include <Timer.h>
#include <SDL.h>

Transition::Transition(int allocatedFrames)
{
	this->allocatedFrames = allocatedFrames;
	transitionOver = false;
}


Transition::~Transition()
{
}

bool Transition::Run()
{
	Timer timer;
	timer.Start();

	this->Update();
	this->Draw();

	if(timer.GetTicks()<50)
			SDL_Delay(50 - timer.GetTicks());

	return transitionOver;
}

void Transition::Update()
{
}

void Transition::Draw()
{
	if(currentFrame > allocatedFrames)
		transitionOver = true;
	currentFrame ++;
}

void Transition::Initialize(Game* game)
{
	this->game = game;
}