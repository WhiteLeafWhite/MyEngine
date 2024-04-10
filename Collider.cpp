#include "Collider.h"

Collider::Collider()
{
	adjustBox(0,0,0,0);
}

Collider::Collider(float x, float y, float width, float height)
{
	adjustBox(x, y, width, height);
}

void Collider::adjustBox(float x, float y, float width, float height)
{
	collid_box.x = x;
	collid_box.y = y;
	collid_box.width = width;
	collid_box.height = height;
}

bool Collider::isColliding(Collider co)
{
	return isColliding(co.collid_box);
}

bool Collider::isColliding(Rect rect)
{
	Rect rect1 = collid_box,rect2 = rect;
	if (rect1.x <= rect2.x + rect2.width &&
		rect1.x + rect1.width >= rect2.x &&
		rect1.y <= rect2.y + rect2.height &&
		rect1.y + rect1.height >= rect2.y) {
		return true;
	}
	return false;
}
