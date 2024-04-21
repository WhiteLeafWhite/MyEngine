#include "NagisaScript.h"
#include "PrefabManager.h"
#include "GameObjectManager.h"
NagisaScript::NagisaScript()
{
	if (!PrefabManager::Scripts.count("NagisaScript")) {
		PrefabManager::LoadScript(this, "NagisaScript");//先放一个假的，防止无限递归
		static NagisaScript a;
		PrefabManager::LoadScript(&a, "NagisaScript");
	}
}

void NagisaScript::update(GameObject* me)
{
}

void NagisaScript::start(GameObject* me)
{
	bullet = "swissRoll";
	inputListener.addCallback('F', [this,me](){
		GameObject roll = PrefabManager::MakePrefab(bullet);
		roll.SetPosition(me->getPosition());
		GameObjectManager::getinstance()->emplace_go(roll);
	});
	inputListener.addCallback('W', [](GameObject* me) {
			me->Translate(0, -50);
		}, me);
	inputListener.addCallback('S', [](GameObject* me) {
			me->Translate(0, 50);
		}, me);
	inputListener.addCallback('A', [](GameObject* me) {
			me->Translate(-50, 0);
		}, me);
	inputListener.addCallback('D', [](GameObject* me) {
			me->Translate(50, 0);
		}, me);
}

void NagisaScript::onColliderEnter(GameObject* me, Collider& co)
{
}

Script* NagisaScript::instance()
{
	NagisaScript* a = new NagisaScript();
	return a;
}
