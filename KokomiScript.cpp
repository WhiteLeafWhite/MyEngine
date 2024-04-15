#include "KokomiScript.h"
#include <time.h>
KokomiScript::KokomiScript()
{
	mouseFocus = false;
	if (!PrefabManager::Scripts.count("KokomiScript")) {
		PrefabManager::LoadScript(this, "KokomiScript");//先放一个假的，防止无限递归
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
	std::cout << me->getPosition().x << " " << me->getPosition().y << std::endl;
	//log(me->getCollider()->getObject().name);
}

void KokomiScript::onClick(GameObject* me)
{
	if (this->mouseFocus) {
		me->SetPostion(rand() % 500, rand() % 500);
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
		if(me->name=="珊瑚宫心海1")
			me->Translate(0, -50);
		whatCanISay(me);
		}, me);
	inputListener.addCallback('S', [](GameObject* me) {
		if (me->name == "珊瑚宫心海1")
			me->Translate(0, 50);
		whatCanISay(me);
		}, me);
	inputListener.addCallback('A', [](GameObject* me) {
		if (me->name == "珊瑚宫心海1")
			me->Translate(-50, 0);
		whatCanISay(me);
		}, me);
	inputListener.addCallback('D', [](GameObject* me) {
		if (me->name == "珊瑚宫心海1")
			me->Translate(50,0);
		whatCanISay(me);
		}, me);
}

void KokomiScript::onColliderEnter(GameObject* me,Collider& co)
{
	me->SetPostion(rand() % 500, rand() % 500);
}

Script* KokomiScript::instance()
{
	KokomiScript* a = new KokomiScript();
	return a;
}
