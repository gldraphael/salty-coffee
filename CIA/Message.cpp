#include "Message.h"
#include <Windows.h>

bool Message::Show(char* title, char* message, Buttons buttons)
{
	auto arg = MB_OK;
	int result;

	switch (buttons)
	{
	case Buttons::OK:
		break;
	case Buttons::YES_NO:
		arg = MB_YESNO;
		break;
	default:
		break;
	}
	result = MessageBox( 0, message, title, arg );

	switch (result)
	{
	case IDYES:
	case IDOK:
		return true;
	case IDNO:
		return false;
	}
	return false;
}