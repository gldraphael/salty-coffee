// 18th January, 2012

#include "Taste.h"
#include <Color.h>
#include "IA.h"


Taste::Taste(Game* game, int allocatedFrames , Transition* transition ) : Scene (game, allocatedFrames, transition)
{

}

Taste::~Taste()
{

}

void Taste::LoadContent()
{
	// Load the Sprite Batch
	sb = reinterpret_cast<SpriteBatch*> (GetGameInstance()->Services["spritebatch"]);
	fm = reinterpret_cast<FontManager*> (GetGameInstance()->Services["fontmanager"]);

	// Load the image here
	// image = Surface::Load ("images/test.png", ImageFormat::PNG, Color::White() );

	// Load the characters
	Friend =  reinterpret_cast<Character*> (GetGameInstance()->Services["friend"]);
	Girl = reinterpret_cast<Character*> (GetGameInstance()->Services["girl"]);
}

void Taste::Update()
{
	if (GetCurrentFrame() == 0)
	{
		reinterpret_cast<StatusBar*>(GetGameInstance()->Services["speechbar"])->Show("Mary's Friend: What's the taste of salty coffee?", Color::White() );
	}
	if (GetCurrentFrame() == 60)
	{
		reinterpret_cast<StatusBar*>(GetGameInstance()->Services["speechbar"])->Show("Mary: It's sweet", Color::Green() );
	}

	Scene::Update();
}

void Taste::Draw()
{
	GetGameInstance()->GetGraphicsDevice()->Clear(Color::Black());
	sb->DrawString( fm->GetFont("cg"), "The Salty Coffee", (Point(800,568) - fm->MeasureString("cg", "The Salty Coffee"))/2, Color::White() );
	Scene::Draw();
}
