#include "Naration.h"
#include <Color.h>
#include "IA.h"


Narration::Narration(Game* game, int allocatedFrames , Transition* transition ) : Scene (game, allocatedFrames, transition)
{

}

Narration::~Narration()
{

}

void Narration::LoadContent()
{
	// Load the Sprite Batch
	sb = reinterpret_cast<SpriteBatch*> (GetGameInstance()->Services["spritebatch"]);
	fm = reinterpret_cast<FontManager*> (GetGameInstance()->Services["fontmanager"]);

}

void Narration::Update()
{
	Scene::Update();
}

void Narration::Draw()
{
	GetGameInstance()->GetGraphicsDevice()->Clear(Color::Black());
	if(GetCurrentFrame() < 100)
	{
		sb->DrawString( fm->GetFont("fb"), "The prince married the princess", Point((Point(800,568).X - fm->MeasureString("fb", "The prince married the princess").X)/2,250), Color::White() );
		sb->DrawString( fm->GetFont("fb"), "and every time she made coffee for him", Point((Point(800,568).X - fm->MeasureString("fb", "and every time she made coffee for him").X)/2, 300), Color::White() );
	}
	else if(GetCurrentFrame() < 200)
	{
		sb->DrawString( fm->GetFont("fb"), "she put some salt in it", Point((Point(800,568).X - fm->MeasureString("fb", "she put some salt in it").X)/2, 300), Color::White() );
	}
	else if(GetCurrentFrame() < 300)
	{
		sb->DrawString( fm->GetFont("fb"), "as she knew that's the way he liked it", Point((Point(800,568).X - fm->MeasureString("fb", "as she knew that's the way she liked it").X)/2,250), Color::White() );
		sb->DrawString( fm->GetFont("fb"), " After 40 years John passed away", Point((Point(800,568).X - fm->MeasureString("fb", "After 40 years <John> passed away").X)/2, 300), Color::White() );
	}
	else if(GetCurrentFrame() < 400)
	{
		sb->DrawString( fm->GetFont("fb"), " He left her a letter...", Point((Point(800,568).X - fm->MeasureString("fb", "He left her a letter...").X)/2, 300), Color::White() );
	}
	Scene::Draw();
}