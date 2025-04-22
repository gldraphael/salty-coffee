// 17 January, 2013

#include "Scene.h"
#include <SDL/SDL.h>

Scene::Scene(Game* game, int allocatedFrames, Transition* Transition)
{
	this->allocatedFrames = allocatedFrames;
	currentFrame = 0;
	transition = nullptr;
	sceneOver = false;
	this->game = game;
	this->transition = transition;
}

Scene::~Scene()
{

}

void Scene::Initialize()
{
	if (transition)
		transition->Initialize(game);
}

void Scene::Update()
{

}

void Scene::Draw()
{
	if(currentFrame == allocatedFrames)
	{
		if (transition)		// If a transition needs to be played
			// Run till transition is over
			while( !transition->Run() );
		
		//Close Scene
		sceneOver = true;
	}
	currentFrame++;
}

void Scene::UnloadContent()
{
	if(transition)
		delete transition;
}

bool Scene::isSceneOver()
{
	return sceneOver;
}

Game* Scene::GetGameInstance()
{
	return game;
}

int Scene::GetCurrentFrame()
{
	return currentFrame;
}
