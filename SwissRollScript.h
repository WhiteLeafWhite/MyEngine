#pragma once
#include "Script.h"
class SwissRollScript :
    public Script
{
private:
    float speed;
public:
    SwissRollScript();
    void update(GameObject *me);
    void start(GameObject* me);
    void onColliderEnter(GameObject* me, Collider& co);
    Script* instance() override;
};

