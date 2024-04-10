#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Globaldefine.h"

class Rigidbody:
	public Component
{
private:
	float gacc = 9.8f;
public:
	float getgacc();
	void setgacc(float newaog);
	
	glm::vec2 velocity;
	glm::vec2 acceleration;
	float weight;
	bool gravity;
	Rigidbody();
	Rigidbody(glm::vec2 vv,glm::vec2 aa,float ww,bool gg);
	void update();
	void impact(glm::vec2 force);
};
