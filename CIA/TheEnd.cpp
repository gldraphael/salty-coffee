#include "TheEnd.h"
#include <Color.h>
#include "IA.h"


TheEnd::TheEnd(Game* game, int allocatedFrames , Transition* transition ) : Scene (game, allocatedFrames, transition)
{

}

TheEnd::~TheEnd()
{

}

void TheEnd::LoadContent()
{
	// Load the Sprite Batch
	sb = reinterpret_cast<SpriteBatch*> (GetGameInstance()->Services["spritebatch"]);
	fm = reinterpret_cast<FontManager*> (GetGameInstance()->Services["fontmanager"]);

}

void TheEnd::Update()
{

	Scene::Update();
}

void TheEnd::Draw()
{
	GetGameInstance()->GetGraphicsDevice()->Clear(Color::Black());
	sb->DrawString( fm->GetFont("cg"), "The End", (Point(800,568) - fm->MeasureString("cg", "The End"))/2, Color::White() );
	Scene::Draw();
}
