#pragma once
class Message
{
public:
	enum class Buttons
	{
		OK,
		YES_NO
	};
	static bool Show(const char* title, const char* message, Buttons buttons = Buttons::OK );
};
