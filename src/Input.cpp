/*
	Input.cpp

	Utillity class for Unity-like input detection.
	resetKeys() is called lateUpdate by App to prepare for next frame.

*/

#include "Input.h"
int Input::m_thisFrameKeyPress = KeyCode::Unknown;
int Input::m_thisFrameKeyRelease = KeyCode::Unknown;

void Input::processKeyPress(sf::Event e)
{
	Input::m_thisFrameKeyPress = e.key.code;
}

void Input::processKeyRelease(sf::Event e)
{
	Input::m_thisFrameKeyRelease = e.key.code;
}

void Input::resetKeys()
{
	Input::m_thisFrameKeyPress = sf::Keyboard::Key::Unknown;
	Input::m_thisFrameKeyRelease = sf::Keyboard::Key::Unknown;
}

bool Input::getKey(KeyCode keyCode)
{
	if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keyCode))
	{
		return true;
	}
	return false;
}

bool Input::getKeyDown(KeyCode key)
{
	if ((KeyCode)m_thisFrameKeyPress == key)
	{
		return true;
	}
	return false;
}

bool Input::getKeyUp(KeyCode key)
{
	if ((KeyCode)m_thisFrameKeyRelease == key)
	{
		return true;
	}
	return false;
}

