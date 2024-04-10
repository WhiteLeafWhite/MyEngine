#pragma once
#include "Script.h"
#include "GameObject.h"
class KokomiScript:
	public Script
{
private:
	
public:bool mouseFocus;
	KokomiScript();
	void update(GameObject* me);
	void onMouse();
	void notOnMouse();
	void onClick(GameObject *me);
	void start(GameObject* me);
	Script* instance() override;
};

