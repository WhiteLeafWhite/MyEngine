#include "AliceScript.h"
#include "GameObject.h"
#include "Globaldefine.h"
void AliceScript::start() {
	myself->Translate(0, 300);
}
Script* AliceScript::instance()
{
	AliceScript *a = new AliceScript();
	log("www");
	return a;
}
AliceScript::AliceScript()
{
	if (!PrefabManager::Scripts.count("AliceScript")) {
		PrefabManager::LoadScript(this, "AliceScript");//�ȷ�һ���ٵģ���ֹ���޵ݹ�
		static AliceScript a;
		PrefabManager::LoadScript(&a, "AliceScript");
	}
}
void AliceScript::update() {
	myself->Translate(5, 0);
}