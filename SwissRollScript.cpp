#include "SwissRollScript.h"
#include "PrefabManager.h"
SwissRollScript::SwissRollScript()
{
	speed = 30;
	if (!PrefabManager::Scripts.count("SwissRollScript")) {
		PrefabManager::LoadScript(this, "SwissRollScript");//先放一个假的，防止无限递归
		static SwissRollScript a;
		PrefabManager::LoadScript(&a, "SwissRollScript");
	}
}

void SwissRollScript::update(GameObject* me)
{
	me->Translate(speed,0);
	if (me->getPosition().x >= 800) {
		me->Destroy();
	}
}

void SwissRollScript::start(GameObject* me)
{
}

void SwissRollScript::onColliderEnter(GameObject* me, Collider& co)
{
	if (co.getObject().tag == "enemy") {
		log("www");
		me->Destroy();
		co.getObject().Destroy();
	}
}

Script* SwissRollScript::instance()
{
	SwissRollScript* a = new SwissRollScript();
	return a;
}
