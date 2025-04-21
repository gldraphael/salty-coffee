#include "Cafe.h"
#include <Color.h>
#include "IA.h"


Cafe::Cafe(Game* game, int allocatedFrames , Transition* transition ) : Scene (game, allocatedFrames, transition)
{
	txt = true;
}

Cafe::~Cafe()
{

}

void Cafe::LoadContent()
{
	// Load the Sprite Batch
	sb = reinterpret_cast<SpriteBatch*> (GetGameInstance()->Services["spritebatch"]);
	fm = reinterpret_cast<FontManager*> (GetGameInstance()->Services["fontmanager"]);
	speech = reinterpret_cast<StatusBar*> (GetGameInstance()->Services["speechbar"]);

	// Load the image here
	image = Surface::Load ("images/cafe.png", ImageFormat::PNG, Color::White() );

	// Load the characters
	Guy =  reinterpret_cast<Character*> (GetGameInstance()->Services["guy"]);
	Girl = reinterpret_cast<Character*> (GetGameInstance()->Services["girl"]);
}

void Cafe::Update()
{
	if(GetCurrentFrame() == 50)
	{
		txt = false;
	}
	// !Adjust the timing!
	if (GetCurrentFrame() == 50)
	{
		speech->Show(" They sat in a nice coffee shop", Color::White() );
	}
	else if (GetCurrentFrame() ==110)
	{
		speech->Show("He was too nervous to say anything ", Color::White() );
	}
	else if (GetCurrentFrame() ==170)
	{
		speech->Show("She felt uncomfortable ", Color::White() );
	}
	else if (GetCurrentFrame() ==230)
	{
		speech->Show("She thought - \"Please let me go home\" ", Color::White() );
	}
	else if (GetCurrentFrame() ==290)
	{
		reinterpret_cast<StatusBar*>(GetGameInstance()->Services["speechbar"])->Show(" He asked the waiter:", Color::White() );
	}
	else if (GetCurrentFrame() ==330)
	{
		speech->Show("John: Would you please give me some salt? I'd like to put it in my coffee ", Color::Brown() );
		SDL_Delay(1000);
	}
	else if (GetCurrentFrame() ==440)
	{
		speech->Show(" Everyone stared at him", Color::White() );
	}
	else if (GetCurrentFrame() ==500)
	{
		speech->Show("His face turned Red", Color::White() );
	}
	else if (GetCurrentFrame() ==560)
	{
		speech->Show("But still he put the salt in the coffee and drank it", Color::White() );
	}
	else if (GetCurrentFrame() ==610)
	{
		speech->Show("She asked him curiously..", Color::White() );
	}
	else if (GetCurrentFrame() ==670)
	{
		speech->Show("Mary: Why you have this hobby?", Color::Green() );
	}
	Scene::Update();
}

void Cafe::Draw()
{
	GetGameInstance()->GetGraphicsDevice()->Clear(Color::Black());
	if (txt)
	{
		sb->DrawString( fm->GetFont("fb"), "At the Cafe", (Point(800,568) - fm->MeasureString("fb", "At the Cafe"))/2, Color::White() );
	}
	else
	{
		sb->Draw(image, Point(0,0), Color::White() );
		// Guy->Draw();
		// Girl->Draw();
	}
	Scene::Draw();
}
