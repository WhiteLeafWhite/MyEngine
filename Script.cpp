#include "Script.h"
#include "Globaldefine.h"
#include<iostream>
void Script::update(GameObject *me)
{
}

void Script::start(GameObject* me)
{
	std::cout << "���Ǹ���" << std::endl;
}

Script* Script::instance()
{
	//��д��ʱ����Ĺ�����newһ���µ�����ű������ؾ���
	return nullptr;
}

void Script::addListener(const InputListener& l)
{
}

void Script::onColliderEnter(GameObject* me,Collider& co)
{
}

void Script::onDestroy(GameObject* me)
{
}
