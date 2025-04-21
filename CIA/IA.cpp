#include "IA.h"
#include <sstream>

#include "Intro.h"
#include "Ask.h"
#include "Cafe.h"
#include "FlashBack.h"
#include "Naration.h"
#include "Letter1.h"
#include "Letter2.h"
#include "Taste.h"
#include "TheEnd.h"

CIA::CIA(bool debugMode) : Scenes(0,nullptr)
{
	this->debugMode = debugMode;

	// Set the Event Handler
	Game::SetEventHandler(new Events);

	// Start from scene 0
	currentScene = 0;
}

CIA::~CIA()
{

}

void CIA::Initialize()
{
	// Initialize the 800 x 600 px Window
	SetTitle("The Salty Coffee - CG Project");
	if(!debugMode)
		Game::HideCursor();
	SetPreferredResolution( Point(800,600), 32, !debugMode);

	//Push Scenes here
	Scenes.push_back(new Intro(this, 150) );		// Completed
	Scenes.push_back(new Ask(this, 800) );			// Completed
	Scenes.push_back(new Cafe(this, 770) );			
	Scenes.push_back(new Flashback(this, 1280) );	// Completed	
	Scenes.push_back(new Narration(this, 400) );	// COMPLETED
	Scenes.push_back(new Letter1(this, 350) );		// Completed
	Scenes.push_back(new Letter2(this, 350) );		// Completed
	// Scenes.push_back(new Taste(this, 50) ) ;			
	Scenes.push_back(new TheEnd(this, 200) );		// Completed

	Game::Initialize();

	// Instantiating the characters
	Guy = new Character(this, "images/guy.png", Point(149, 216) );
	Girl = new Character(this, "images/girl.png", Point(149, 216) );

	// and initializing them
	Guy->Initialize();
	Girl->Initialize();

	// Quit if no scenes exist
	if (Scenes.size() == 0)
		throw GameBaseException("No scenes exist\n\nAdd scenes in:\n   File:              "
		"IA.cpp\n   Function:    CIA::Initialize() \n\n"
		"before Game::Initialize() statement");		
}

void CIA::LoadContent()
{
	// Registering services
	Services["spritebatch"] = reinterpret_cast<Component*>(spriteBatch);
	Services["fontmanager"] = reinterpret_cast<Component*>(&fontManager);
	Services["audioengine"] = reinterpret_cast<Component*>(&audioEngine);

	// Show the splash screen image and then load the content
	spriteBatch->Draw(Surface::Load("images/splash.png",ImageFormat::PNG),Point(0,0),Color::White());
	graphicsDevice->Draw();
	// Wait for a second
	SDL_Delay(1000);

	// Load Fonts
	fontManager.Load("tw", "fonts/sub.ttf", 18 );
	fontManager.Load("lc", "fonts/lucon.ttf", 26 );
	fontManager.Load("cg", "fonts/cg.ttf", 72 );
	fontManager.Load("fb", "fonts/fb.ttf", 36);

	// Instantiate the status bars and add them as services
	Surface statusBack = Surface::Load( "images/bar.png", ImageFormat::PNG, Color::White() );
	speechBar = new StatusBar(this, statusBack, &fontManager, "tw", spriteBatch, Point( 0.0, (float)(graphicsDevice->Viewport().Height - 32 )) );
	if (debugMode)
		debugBar = new StatusBar(this, statusBack, &fontManager, "lc", spriteBatch, Point(0,0) );

	Services["speechbar"] = reinterpret_cast <Component*> (speechBar);
	Services["debugbar"] = reinterpret_cast <Component*> (debugBar);

	Guy->LoadContent();
	Girl->LoadContent();

	// Add them as a Service
	Services["guy"] = reinterpret_cast<Component*>(Guy);
	Services["girl"] = reinterpret_cast<Component*>(Girl);

	// Load Scenes
	for (auto s : Scenes)
		s->LoadContent();

	 // Load the music
	audioEngine.Load("music", "music/music.wav", AudioEngine::Type::MUSIC);

	Game::LoadContent();

	// Play bg music once loading is done
	// audioEngine.PlayMusic("music");
}

void CIA::Update()
{
	// If the current scene is over
	if (Scenes[currentScene]->isSceneOver() )
	{
		// If more scenes exist
		if (currentScene < Scenes.size() )
		{
			// go to next scene
			currentScene++;

			// and remove speech text
			speechBar->ResetText();

			// Stop the animation of the characters
			Guy->StopAnimation();
			Girl->StopAnimation();
		}
		else
			// Else close the application
			Close();
	}
	
	// Update the current scene
	Scenes[currentScene]->Update();

	if(debugMode)
	{
		// Set the debug bar text
		std::stringstream stream;
		stream<<"Scene: "
			<<currentScene + 1
			<<"      Time: "
			<<static_cast<int>(Scenes[currentScene]->GetCurrentFrame()/20)
			<<"s       Frame: "
			<< Scenes[currentScene]->GetCurrentFrame();

		// Show the debug bar
		debugBar->Show(stream.str(), Color::Gray() );
	}

	// Update the App
	Game::Update();
}

void CIA::Draw()
{
	// Clear the backbuffer
	graphicsDevice->Clear( Color::Black() );

	// Draw the current scene
	Scenes[currentScene]->Draw();

	// Draw the speech bar
	speechBar->Draw();

	// Draw the debug 
	if(debugMode)
		debugBar->Draw();

	// Swap the buffers
	graphicsDevice->Draw();
}

void CIA::UnloadContent()
{

	// Unload Scenes
	for (auto s : Scenes)
		s->UnloadContent();

	// Free the sprites
	delete Guy;
	delete Girl;

	// Free the scenes from memory
	for (auto s : Scenes)
		delete s;

	// Free the status bars from memory
	delete speechBar;
	if (debugMode)
		delete debugBar;

	Game::UnloadContent();
}

bool CIA::isDebugMode()
{
	return debugMode;
}
