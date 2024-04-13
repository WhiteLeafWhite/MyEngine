#include "GameObject.h"
#include "Globaldefine.h"
GameObject::GameObject()
{
	position = glm::vec2(0.0f, 0.0f);
	size.x = 100;
	size.y = 100;
	angle = 0.0f;
	name = "newobject";
	script = nullptr;
	scriptIsNewed = false;
	component[0] = false;
	component[1] = false;
	component[2] = false;
	component[3] = false;
}

glm::vec2 GameObject::getPosition()
{
	return position;
}

void GameObject::SetPostion(float xx, float yy)
{
	position.x = xx;
	position.y = yy;
	if (component[2]) {
		getCollider()->adjustBox(position.x, position.y, size.x, size.y);
	}
	return;
}

void GameObject::Translate(float deltaX, float deltaY)
{
	position.x += deltaX;
	position.y += deltaY;
	if (component[2]) {
		getCollider()->adjustBox(position.x, position.y, size.x, size.y);
	}
}

void GameObject::Rotate(float deltaA)
{
	angle += deltaA;
	while (fabs(angle) > 360) {
		if (angle < 0) {
			angle += 360;
		}
		else {
			angle -= 360;
		}
	}
}

void GameObject::Scale(float dwidth, float dheight)
{
	if (dwidth < 0 || dheight < 0) return;
	size.x *= dwidth;
	size.y *= dheight;
	if (component[2]) {
		getCollider()->adjustBox(position.x, position.y, size.x, size.y);
	}
}

void GameObject::addRenderer(Renderer r)
{
	component[0] = true;
	renderer = r;
}

Renderer* GameObject::getRenderer()
{
	if(component[0])
		return &renderer;
	Renderer idle;
	return &idle;
}

void GameObject::draw(glm::vec3 color)
{
	if (component[0]) {
		this->getRenderer()->draw(position, size, angle, color);
	}
}

void GameObject::draw(float r, float g, float b)
{
	glm::vec3 color(r, g, b);
	this->draw(color);
}

void GameObject::addRigidbody(Rigidbody r)
{
	component[1] = true;
	rigidbody = r;
}

Rigidbody* GameObject::getRigidbody() {
	if (component[1])
		return &rigidbody;
	Rigidbody idle;
	return &idle;
}

void GameObject::updateRigidbody()
{
	if (component[1]) {
		
		this->position = position + this->getRigidbody()->velocity * ENGINE_TICK_TIME;
		if (component[2]) {
			this->getCollider()->adjustBox(position.x, position.y, size.x, size.y);
		}
		rigidbody.update();
	}
}

void GameObject::impactRigidbody(glm::vec2 force)
{
	if (component[1]) {
		rigidbody.impact(force);
	}
}

void GameObject::addCollider(Collider c)
{
	component[2] = true;
	collider = c;
	collider.adjustBox(position.x, position.y, size.x, size.y);
}

void GameObject::addCollider(Collider c, float x, float y, float width, float height)
{
	component[2] = true;
	collider = c;
	collider.adjustBox(x, y, width, height);
}

Collider* GameObject::getCollider()
{
	if (component[2]) {
		return &collider;
	}
	//Collider idle;
	return nullptr;
}

void GameObject::startScript()
{
	if(component[3]) {
		script->start(this);
	}
}

void GameObject::addScript(std::string name)
{
	component[3] = true;
	script=PrefabManager::GetScript(name);
	scriptName = name;
	script->myself = this;
}

void GameObject::updateScript()
{
	if (component[3]) {
		script->inputListener.update(this->position,this->size);
		script->update(this);
	}
}

Script* GameObject::getScript()
{
	if (component[3]) {
		return script;
	}
	return nullptr;
}

void GameObject::reLoadScript()
{
	if (component[3]) {
		scriptIsNewed = true;
		script = PrefabManager::GetScript(scriptName);
		script->myself = this;
		script->start(this);
	}
}

