#include "InputListener.h"
#include <windows.h>
#include <iostream>
#include "MousePos.h"
InputListener::InputListener()
{
}

void InputListener::update(glm::vec2 pos, glm::vec2 size)
{
	double x= MousePos::getinstance()->getx(), y= MousePos::getinstance()->gety();
	if (x >= pos.x && x <= pos.x + size.x && y >= pos.y && y <= pos.y + size.y) {
		if (hasMouseOn) {
			mouseOn();
		}
	}
	else {
		if (hasMouseNotOn) {
			mouseNotOn();
		}
	}
	for (const auto& c : callback) {
		if ((isPressed[c.first]==false)&&GetAsyncKeyState(c.first) & 0x8000) {
			c.second();
			isPressed[c.first] = true;
		}
		else if(!(GetAsyncKeyState(c.first)&0x8000)){
			isPressed[c.first] = false;
		}
	}
}
