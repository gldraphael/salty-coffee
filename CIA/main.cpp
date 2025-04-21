#include "IA.h"
#include "Message.h"

// Application Entry Point
int main(int argc, char** argv)
{
	// True if the Project should run in a debug mode
	bool debug = Message::Show("CG Project", "Run in debug mode?", Message::Buttons::YES_NO);
	
	try
	{
		CIA project(debug);
		project.Run(20);

		//if ( project.isDebugMode() )
		//{
		//	// Display uncaught exceptions
		//	Message::Show ( "Debug Mode", const_cast<char*> (GameBaseException().what()) ); 
		//}
	}

#pragma region Catching Exceptions

	catch (GameBaseException& ge)
	{
		Message::Show ( "!!! CG Project", const_cast<char*> ( ge.what()) ); 
	}
	catch (std::exception& e)
	{
		Message::Show ("!!! CG Project", const_cast<char*> (e.what()) ); 
	}
	catch(...)
	{
		Message::Show("!!! CG Project", "Unhandled exception");
	}

#pragma endregion

	return 0;
}