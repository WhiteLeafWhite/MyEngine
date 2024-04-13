#pragma once
#include "Component.h"
#include "InputListener.h"
#include "Collider.h"
class Script :
    public Component
{
public:
    class GameObject *myself;
    InputListener inputListener;
    virtual void update(GameObject *me);
    virtual void start(GameObject* me);
    virtual Script* instance();
    virtual void addListener(const InputListener& l);
    virtual void onColliderEnter(GameObject* me,Collider& co);
private:
    
};

