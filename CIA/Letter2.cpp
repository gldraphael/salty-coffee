// 18th January, 2012

#include "Letter2.h"
#include <Color.h>
#include "IA.h"


Letter2::Letter2(Game* game, int allocatedFrames , Transition* transition ) : Scene (game, allocatedFrames, transition)
{

}

Letter2::~Letter2()
{

}

void Letter2::LoadContent()
{
	// Load the Sprite Batch
	sb = reinterpret_cast<SpriteBatch*> (GetGameInstance()->Services["spritebatch"]);
	fm = reinterpret_cast<FontManager*> (GetGameInstance()->Services["fontmanager"]);

	// Load the image here
	image = Surface::Load ("images/letter2.png", ImageFormat::PNG, Color::White() );
}

void Letter2::Update()
{

	Scene::Update();
}

void Letter2::Draw()
{
	GetGameInstance()->GetGraphicsDevice()->Clear(Color::Black());
	sb->Draw( image, Point() , Color::White() );
	Scene::Draw();
}
