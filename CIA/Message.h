#pragma once
class Message
{
public:
	enum class Buttons
	{
		OK,
		YES_NO
	};
	static bool Show(char* title, char* message, Buttons buttons = Buttons::OK );
};
