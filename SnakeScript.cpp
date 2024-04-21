#include "SnakeScript.h"
#include "GameObjectManager.h"
SnakeScript::SnakeScript(GLFWwindow* w, std::string b):window(w),bullet(b),pressed(false)
{
	if (!PrefabManager::Scripts.count("SnakeScript")) {
		PrefabManager::LoadScript(this, "SnakeScript");//先放一个假的，防止无限递归
		static SnakeScript a(window, bullet);
		PrefabManager::LoadScript(&a, "SnakeScript");
	}
}

void SnakeScript::update(GameObject* me)
{	
	if (!pressed&&glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
		pressed = true;
		GameObject temp = PrefabManager::MakePrefab("mika");
		temp.SetPosition(rand() % 500, rand() % 500);
		GameObjectManager::getinstance()->emplace_go(temp);
	}
	if (pressed && glfwGetKey(window, GLFW_KEY_F) == GLFW_RELEASE) {
		pressed = false;
	}
}

void SnakeScript::start()
{
	srand(time(0));
}

Script* SnakeScript::instance()
{
	SnakeScript* a = new SnakeScript(window,bullet);
	return a;
}
