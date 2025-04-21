// 18th January, 2012

#include "Flashback.h"
#include <Color.h>
#include "IA.h"


Flashback::Flashback(Game* game, int allocatedFrames , Transition* transition ) : Scene (game, allocatedFrames, transition)
{
	h = b = back = g = false;
	i = 0;
}

Flashback::~Flashback()
{

}

void Flashback::LoadContent()
{
	// Load the Sprite Batch
	sb = reinterpret_cast<SpriteBatch*> (GetGameInstance()->Services["spritebatch"]);
	fm = reinterpret_cast<FontManager*> (GetGameInstance()->Services["fontmanager"]);

	// Load the image here
	image = Surface::Load ("images/beach.png", ImageFormat::PNG);
	heart = Surface::Load( "images/heart.png", ImageFormat::PNG);
	boy = Surface::Load("images/bigb.png", ImageFormat::PNG );
	girl = Surface::Load("images/bigg.png", ImageFormat::PNG);
}

void Flashback::Update()
{
	if (GetCurrentFrame() == 60)
	{
		b = true;
	}
	else if(GetCurrentFrame() == 130)
		back = true;
	else if( GetCurrentFrame() == 550)
		g = true;
	Scene::Update();
}

void Flashback::Draw()
{
	GetGameInstance()->GetGraphicsDevice()->Clear(Color::Black());
	if (back)
		sb->Draw(image, Point(0,0), Color::White());
	if(b)
		sb->Draw(boy, Point(), Color::White() );
	if (g)
		sb->Draw( girl, Point(), Color::White());
	if(h)
		sb->Draw ( heart, (Point(800,600-32) - Point(heart.Width(), heart.Height()))/2 + Point(30,40), Color::White() );
	// Text
	if(GetCurrentFrame() < 70)
	{
		sb->DrawString( fm->GetFont("fb"), "He replied", (Point(800,600-32) - fm->MeasureString("fb", "He replied"))/2, Color::White() );
	}
	else if(GetCurrentFrame() < 130)
	{
		sb->DrawString( fm->GetFont("fb"), "When I was a little boy", Point(50,40), Color::White() );
	}
	else if(GetCurrentFrame() < 190)
	{
		sb->DrawString( fm->GetFont("fb"), "I was living near the sea", Point(50,40), Color::White() );
	}
	else if(GetCurrentFrame() < 250)
	{
		sb->DrawString( fm->GetFont("fb"), "I like playing in the sea and would", Point(50,40), Color::White() );
		sb->DrawString( fm->GetFont("fb"), "        feel the taste of the sea", Point(50,90), Color::White() );
	}
	else if(GetCurrentFrame() < 310)
	{
		sb->DrawString( fm->GetFont("fb"), "Just like the taste of the Salty Coffee", Point(50,40), Color::White() );
	}
	else if(GetCurrentFrame() < 390)
	{
		sb->DrawString( fm->GetFont("fb"), "Now everytime I taste the salty coffee, ", Point(50,40), Color::White() );
		sb->DrawString( fm->GetFont("fb"), "   I always think about my childhood     ", Point(50,90), Color::White() );
	}
	else if(GetCurrentFrame() < 470)
	{
		sb->DrawString( fm->GetFont("fb"), " I think of my hometown", Point(50,40), Color::White() );
		sb->DrawString( fm->GetFont("fb"), "           I miss my hometown.", Point(50,90), Color::White() );
	}
	else if(GetCurrentFrame() < 550)
	{
		sb->DrawString( fm->GetFont("fb"), "I miss my parents who are still living there", Point(50,40), Color::White() );
	}
	else if(GetCurrentFrame() < 630)
	{
		sb->DrawString( fm->GetFont("fb"), "While saying that, tears filled his eyes.", Point(50,40), Color::White() );
		sb->DrawString( fm->GetFont("fb"), "  She was deeply touched  ", Point(50,90), Color::White() );
	}
	else if(GetCurrentFrame() < 710)
	{
		sb->DrawString( fm->GetFont("fb"),"That's his true feeling ", Point(50,40), Color::White() );
		sb->DrawString( fm->GetFont("fb"), " from the bottom of his heart  ", Point(50,90), Color::White() );
	}
	else if(GetCurrentFrame() < 790)
	{
		sb->DrawString( fm->GetFont("fb"),"Both of them shared", Point(50,40), Color::White() );
		sb->DrawString( fm->GetFont("fb"), "about their hometown. It was a nice talk", Point(50,90), Color::White() );
	}
	else if(GetCurrentFrame() < 830)
	{
		sb->DrawString( fm->GetFont("fb")," And also a beautiful ", Point(50,40), Color::White() );
		sb->DrawString( fm->GetFont("fb"),"  beginning of their story....", Point(50,90), Color::White() );
	}
	else if(GetCurrentFrame() < 870)
	{
		sb->DrawString( fm->GetFont("fb")," And also a beautiful ", Point(50,40), Color::White() );
		sb->DrawString( fm->GetFont("fb"),"  beginning of their story....", Point(50,90), Color::White() );
		h = true;
	}
	else if(GetCurrentFrame() < 950)
	{
		sb->DrawString( fm->GetFont("fb")," They continued to date....", Point(50,40), Color::White() );
	}
	else if(GetCurrentFrame() < 1020)
	{
		sb->DrawString( fm->GetFont("fb")," She found out that he was ", Point(50,40), Color::White() );
		sb->DrawString( fm->GetFont("fb")," actually a man who meets", Point(50,90), Color::White() );
		sb->DrawString( fm->GetFont("fb"),"                    all her demands.", Point(50,140), Color::White() );
	}
	else if(GetCurrentFrame() < 1100)
	{
		sb->DrawString( fm->GetFont("fb")," He was such a good person ", Point(50,40), Color::White() );
		sb->DrawString( fm->GetFont("fb")," but she almost missed him!", Point(50,90), Color::White() );
	}
	else if(GetCurrentFrame() < 1190)
	{
		sb->DrawString( fm->GetFont("fb")," Thanks to his salty coffee!!", Point(50,40), Color::White() );
	}
	else if(GetCurrentFrame() <1280)
	{
		sb->DrawString( fm->GetFont("fb")," Just like every beautiful love story... !", Point(50,40), Color::White() );
	}
	Scene::Draw();
}