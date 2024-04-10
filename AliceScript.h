#pragma once
#include "Script.h"
#include "PrefabManager.h"
class AliceScript : public Script
{
public:
	AliceScript();
	void update();
	void start();
	Script* instance() override;
};