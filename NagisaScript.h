#pragma once
#include "Script.h"
#include "string"
class NagisaScript :
    public Script
{
private:
    std::string bullet;
public:
    NagisaScript();
    void update(GameObject* me);
    void start(GameObject* me);
    void onColliderEnter(GameObject* me, Collider& co);
    Script* instance() override;
};

