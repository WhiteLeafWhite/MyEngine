#include "Component.h"

Component::Component()
{
    this->active = true;
    this->comtype = ComponentType::COMPONENT;
}

bool Component::Isactive()
{
    return active;
}

void Component::dosomething()
{
}

void Component::disable()
{
    active = false;
}

void Component::enable()
{
    active = true;
}
