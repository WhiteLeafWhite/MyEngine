#include "HosinoScript.h"
#include <Windows.h>
HosinoScript::HosinoScript(GLFWwindow* w, std::string b):window(w),bullet(b)
{
	pressed = false;
	if (!PrefabManager::Scripts.count("HosinoScript")) {
		PrefabManager::LoadScript(this, "HosinoScript");//�ȷ�һ���ٵģ���ֹ���޵ݹ�
		static HosinoScript a(window,bullet);
		PrefabManager::LoadScript(&a, "HosinoScript");
	}
}

void onD(GameObject* me) {
	me->Translate(50, 0);
	log("�����ߣ�");
}
void onMouse(GameObject* me) {
	me->Translate(0, 50);
	log("����������ˣ�");
}

void HosinoScript::update(GameObject *me)
{
}

void HosinoScript::start(GameObject* me)
{
	inputListener.addCallback('D', onD, me);
	inputListener.addMouseOn(onMouse, me);
}

void HosinoScript::changeBullet(std::string newbullet)
{
	bullet = newbullet;
}

Script* HosinoScript::instance()
{
	HosinoScript* a = new HosinoScript(window, bullet);
	return a;
}
