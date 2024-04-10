#pragma once
#include "Component.h"
#include "Rect.h"


class Collider :
    public Component
{
public:
    Rect collid_box;
    Collider();
    Collider(float x, float y, float width, float height);
    void adjustBox(float x, float y, float width, float height);
    bool isColliding(Collider co);
    bool isColliding(Rect rect);
};



