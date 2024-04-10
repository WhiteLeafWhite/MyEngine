#pragma once
#include "Script.h"
#include "GameObject.h"
#include <vector>
class SnakeScript :
    public Script
{
private:
	std::string bullet;
	GLFWwindow* window;
	bool pressed;
public:
	SnakeScript(GLFWwindow* w, std::string b);
	void update(GameObject* me);
	void start();
	Script* instance() override;
};

