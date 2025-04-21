// 18th January, 2012

#include "Letter1.h"
#include <Color.h>
#include "IA.h"


Letter1::Letter1(Game* game, int allocatedFrames , Transition* transition ) : Scene (game, allocatedFrames, transition)
{

}

Letter1::~Letter1()
{

}

void Letter1::LoadContent()
{
	// Load the Sprite Batch
	sb = reinterpret_cast<SpriteBatch*> (GetGameInstance()->Services["spritebatch"]);
	fm = reinterpret_cast<FontManager*> (GetGameInstance()->Services["fontmanager"]);

	// Load the image here
	image = Surface::Load ("images/letter1.png", ImageFormat::PNG, Color::White() );
}

void Letter1::Update()
{

	Scene::Update();
}

void Letter1::Draw()
{
	GetGameInstance()->GetGraphicsDevice()->Clear(Color::Black());
	sb->Draw(image, Point(), Color::White() );
	Scene::Draw();
}
