#include "SwissRollScript.h"
#include "PrefabManager.h"
SwissRollScript::SwissRollScript()
{
	speed = 30;
	if (!PrefabManager::Scripts.count("SwissRollScript")) {
		PrefabManager::LoadScript(this, "SwissRollScript");//�ȷ�һ���ٵģ���ֹ���޵ݹ�
		static SwissRollScript a;
		PrefabManager::LoadScript(&a, "SwissRollScript");
	}
}

void SwissRollScript::update(GameObject* me)
{
	me->Translate(speed,0);
	if (me->getPosition().x >= 300) {
		me->Destroy();
	}
}

void SwissRollScript::start(GameObject* me)
{
}

void SwissRollScript::onColliderEnter(GameObject* me, Collider& co)
{
}

Script* SwissRollScript::instance()
{
	SwissRollScript* a = new SwissRollScript();
	return a;
}