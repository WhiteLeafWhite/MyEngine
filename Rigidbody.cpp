#include "Rigidbody.h"
#include "Globaldefine.h"
#include<iostream>
float Rigidbody::getgacc()
{
	return gacc;
}
void Rigidbody::setgacc(float newaog)
{
	gacc = newaog;
}
Rigidbody::Rigidbody()
{
	velocity = glm::vec2(0, 0);
	acceleration = glm::vec2(0, 9.80);
	weight = 1;
	gravity = true;
}
Rigidbody::Rigidbody(glm::vec2 vv, glm::vec2 aa, float ww, bool gg)
{
	velocity = vv;
	acceleration = aa;
	weight = ww;
	gravity = gg;
}
void Rigidbody::update()
{
	this->velocity = velocity+this->acceleration * ENGINE_TICK_TIME;
	this->acceleration = glm::vec2(0, 9.8) * (float)(gravity?1:0);
}

void Rigidbody::impact(glm::vec2 force)
{
	this->acceleration = this->acceleration + (force / weight);
}

