#include "ZakoScript.h"
#include "PrefabManager.h"
#include "GameObjectManager.h"

ZakoScript::ZakoScript()
{
	mouse_focus = false;
	if (!PrefabManager::Scripts.count("ZakoScript")) {
		PrefabManager::LoadScript(this, "ZakoScript");//先放一个假的，防止无限递归
		static ZakoScript a;
		PrefabManager::LoadScript(&a, "ZakoScript");
	}
}

void ZakoScript::start(GameObject* me)
{
	log(me->ID);
	get_sensai.set(me->ID, "I want sensai!");
	inputListener.addCallback(1, &ZakoScript::on_click, this,me);
	inputListener.addMouseOn([this]() {mouse_focus = true; });
	inputListener.addMouseNotOn([this]() {mouse_focus = false; });
	me->SetPosition(rand() % 500, rand() % 500);
}

void ZakoScript::update(GameObject* me)
{
	for (E_Message message : EMessageBox::get_instance()->get_box()) {
		if (message.get_content() == "I want sensai!" && message.get_sender_id() != me->ID) {
			me->Destroy();
		}
	}
}

Script* ZakoScript::instance()
{
	ZakoScript* a = new ZakoScript();
	return a;
}

void ZakoScript::on_click(GameObject* me)
{
	if (mouse_focus == false) return;
	EMessageBox::get_instance()->put_message(get_sensai);
	log(me->ID);
}
