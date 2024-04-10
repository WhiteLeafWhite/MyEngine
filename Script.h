#pragma once
#include "Component.h"
#include "InputListener.h"
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
private:
    
};

