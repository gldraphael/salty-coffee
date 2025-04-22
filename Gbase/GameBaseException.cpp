#include "GameBaseException.h"
#include <SDL/SDL.h>

//namespace GameBase
//{
	GameBaseException::GameBaseException(std::string message)
	{
		this->message = message;
	}

	GameBaseException::GameBaseException()
	{
		this->message = SDL_GetError();
	}

	const char* GameBaseException::what() const noexcept
	{
		return message.c_str();
	}
//}
