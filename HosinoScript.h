#pragma once
#include "Script.h"
#include "GameObject.h"
#include <string>
class HosinoScript :
    public Script
{
private:
	std::string bullet;
	GLFWwindow* window;
	bool pressed;
public:
	HosinoScript(GLFWwindow* w, std::string b);
	void update(GameObject *me);
	void start(GameObject* me);
	void changeBullet(std::string newbullet);
	Script* instance() override;
};

