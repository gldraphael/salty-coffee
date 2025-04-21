#include "Ask.h"
#include <Color.h>
#include "IA.h"

Ask::Ask(Game* game, int allocatedFrames , Transition* transition ) : Scene (game, allocatedFrames, transition)
{

}

Ask::~Ask()
{

}

void Ask::LoadContent()
{
	// Load the Sprite Batch
	sb = reinterpret_cast<SpriteBatch*> (GetGameInstance()->Services["spritebatch"]);
	fm = reinterpret_cast<FontManager*> (GetGameInstance()->Services["fontmanager"]);
	ae = reinterpret_cast<AudioEngine*> (GetGameInstance()->Services["audioengine"]);

	// Load the image here
	image = Surface::Load ("images/neighbourhood.png", ImageFormat::PNG, Color::White() );
	front = Surface::Load ("images/fences.png", ImageFormat::PNG, Color::White() );
	speech = reinterpret_cast<StatusBar*>(GetGameInstance()->Services["speechbar"]);

	Girl = reinterpret_cast<Character*>(GetGameInstance()->Services["girl"]);
	Guy = reinterpret_cast<Character*>(GetGameInstance()->Services["guy"]);
}

void Ask::Update()
{

	// At frame 0 do this
	if (GetCurrentFrame() == 0)
	{
		// Display the text in the speech bar
		reinterpret_cast<StatusBar*>(GetGameInstance()->Services["speechbar"])->Show("John is in love with Mary who stays in his neighbourhood", Color::White() );
		Girl->SetPosition(Point(0,360));
		Guy->SetPosition( Point(800-Guy->GetSize().X, 360) );
		Guy->SetAnimation(Character::Animation::LEFT);	
		ae->PlayMusic("music");
	}
	else if (GetCurrentFrame() == 120)
	{
		reinterpret_cast<StatusBar*>(GetGameInstance()->Services["speechbar"])->Show("She was so outstanding", Color::White() );
	}
	else if (GetCurrentFrame() == 181)
	{
		reinterpret_cast<StatusBar*>(GetGameInstance()->Services["speechbar"])->Show("Many guys chased her, but John was normal and nobody paid attention to him", Color::White() );
	}
	else if (GetCurrentFrame() == 250)
	{
		Guy->Animate(Character::Animation::LEFT);
	}
	else if (GetCurrentFrame() == 390)
	{
		Girl->Animate(Character::Animation::RIGHT);
	}

	else if (GetCurrentFrame() == 443)
	{
		Guy->StopAnimation();
	}
	else if (GetCurrentFrame() == 460)
	{
		reinterpret_cast<StatusBar*>(GetGameInstance()->Services["speechbar"])->Show("Once he invited Mary to have coffee with him", Color::White() );
	}
	else if( GetCurrentFrame() == 613)
	{
		Girl->StopAnimation();
		speech->Show("John: Uhm... You wanna have some coffee at the cafe..?", Color(153,217, 234) );
	}
	else if (GetCurrentFrame() == 680)
	{
		speech->Show(" She was surprised, but she accepted to be polite.", Color::White() );
	}
	else if (GetCurrentFrame() == 750)
	{
		speech->Show("Mary: Uhm... sure... ", Color::Green() );
	}

	Guy->Update(GetCurrentFrame(), 5);
	Girl->Update(GetCurrentFrame(), 5);

	Scene::Update();
}

void Ask::Draw()
{
	GetGameInstance()->GetGraphicsDevice()->Clear(Color::Black());
	sb->Draw(image, Point(0,0), Color::White());
	sb->Draw(front, Point(0,0), Color::White());

	Guy->Draw();
	Girl->Draw();
	

	Scene::Draw();
}
