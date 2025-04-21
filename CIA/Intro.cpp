// 18th January, 2012

#include "Intro.h"
#include <Color.h>
#include "IA.h"


Intro::Intro(Game* game, int allocatedFrames , Transition* transition ) : Scene (game, allocatedFrames, transition)
{

}

Intro::~Intro()
{

}

void Intro::LoadContent()
{
	// Load the Sprite Batch
	sb = reinterpret_cast<SpriteBatch*> (GetGameInstance()->Services["spritebatch"]);
	fm = reinterpret_cast<FontManager*> (GetGameInstance()->Services["fontmanager"]);

	// Load the image here
	image = Surface::Load ("images/test.png", ImageFormat::PNG, Color::White() );
}

void Intro::Update()
{
	/*if (GetCurrentFrame() == 0)
		reinterpret_cast<StatusBar*>(GetGameInstance()->Services["speechbar"])->Show("Speech bar", Color::White() );*/

	Scene::Update();
}

void Intro::Draw()
{
	GetGameInstance()->GetGraphicsDevice()->Clear(Color::Black());
	sb->DrawString( fm->GetFont("cg"), "The Salty Coffee", (Point(800,568) - fm->MeasureString("cg", "The Salty Coffee"))/2, Color::White() );
	Scene::Draw();
}
