#include "IA.h"
// #include "Message.h"
#include <iostream>

// Application Entry Point
int main(int argc, char** argv)
{
	// True if the Project should run in a debug mode
	bool debug = true; // Message::Show("CG Project", "Run in debug mode?", Message::Buttons::YES_NO);
	
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
    std::cerr << "!!! CG Project: " << const_cast<char*> (ge.what()) << std::endl; 
	}
	catch (std::exception& e)
	{
    std::cerr << "!!! CG Project: " << const_cast<char*> (e.what()) << std::endl;; 
	}
	catch(...)
	{
    std::cerr << "!!! CG Project: " << "Unhandled exception" << std::endl;;
	}

#pragma endregion

	return 0;
}
