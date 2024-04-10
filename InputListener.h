#pragma once
#include<functional>
#include<map>
#include <glm/glm.hpp>
class InputListener
{
public:
	InputListener();
	InputListener(InputListener&&)noexcept = default;
	template<class F,class... Args>
	bool addCallback(int ascii,F&& f,Args&&... args);
	template<class F,class... Args>
	void addMouseOn(F&& f, Args&&... args);
	template<class F, class... Args>
	void addMouseNotOn(F&& f, Args&&... args);
	void update(glm::vec2 pos,glm::vec2 size);
private:
	bool hasMouseOn,hasMouseNotOn;
	std::function<void()> mouseOn;
	std::function<void()> mouseNotOn;
	std::map<int, std::function<void()> > callback;
	std::map<int, bool> isPressed;
};

template<class F, class ...Args>
inline bool InputListener::addCallback(int ascii, F&& f, Args && ...args)
{
	callback[ascii] = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
	isPressed[ascii] = false;
	return false;
}

template<class F, class ...Args>
inline void InputListener::addMouseOn(F&& f, Args && ...args)
{
	hasMouseOn = true;
	mouseOn = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
}

template<class F, class ...Args>
inline void InputListener::addMouseNotOn(F&& f, Args && ...args)
{
	hasMouseNotOn = true;
	mouseNotOn = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
}
