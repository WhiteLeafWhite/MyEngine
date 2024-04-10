#include "KokomiScript.h"
#include <time.h>
KokomiScript::KokomiScript()
{
	mouseFocus = false;
	if (!PrefabManager::Scripts.count("KokomiScript")) {
		PrefabManager::LoadScript(this, "KokomiScript");//�ȷ�һ���ٵģ���ֹ���޵ݹ�
		static KokomiScript a;
		PrefabManager::LoadScript(&a, "KokomiScript");
	}
}

void KokomiScript::update(GameObject* me){}

void KokomiScript::onMouse()
{
	this->mouseFocus = true;
}

void KokomiScript::notOnMouse()
{
	this->mouseFocus = false;
}

void whatCanISay(GameObject* me) {
	std::cout << me->position.x << " " << me->position.y << std::endl;
}

void KokomiScript::onClick(GameObject* me)
{
	if (this->mouseFocus) {
		me->position = glm::vec2(rand() % 500, rand() % 500);
		whatCanISay(me);
	}
}

void KokomiScript::start(GameObject* me)
{
	srand(time(0));
	inputListener.addCallback(1, &KokomiScript::onClick, this,me);
	inputListener.addMouseOn(&KokomiScript::onMouse,this);
	inputListener.addMouseNotOn(&KokomiScript::notOnMouse, this);
	inputListener.addCallback('W', [](GameObject* me) {
		me->Translate(0, -50);
		whatCanISay(me);
		}, me);
	inputListener.addCallback('S', [](GameObject* me) {
		me->Translate(0, 50);
		whatCanISay(me);
		}, me);
	inputListener.addCallback('A', [](GameObject* me) {
		me->Translate(-50, 0);
		whatCanISay(me);
		}, me);
	inputListener.addCallback('D', [](GameObject* me) {
		me->Translate(50,0);
		whatCanISay(me);
		}, me);
}

Script* KokomiScript::instance()
{
	KokomiScript* a = new KokomiScript();
	return a;
}