#include "Script.h"
#include "Globaldefine.h"
#include<iostream>
void Script::update(GameObject *me)
{
}

void Script::start(GameObject* me)
{
	std::cout << "我是父类" << std::endl;
}

Script* Script::instance()
{
	//重写的时候，你的工作是new一个新的子类脚本并返回就行
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
