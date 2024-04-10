#pragma once
#include<mutex>
#include<GLFW/glfw3.h>
class MousePos
{
public:
	static MousePos* getinstance();
	void update(GLFWwindow*& window);
	double getx() { return x; }
	double gety() { return y; }
private:
	MousePos(){}
	MousePos(const MousePos& m) = delete;
	MousePos operator = (const MousePos& m) = delete;
	static double x, y;
	static MousePos* mousepos;
	static std::mutex mpos_mutex;
};

