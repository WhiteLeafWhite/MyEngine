#pragma once
#include "Component.h"
#include <string>
#include <list>
#include <set>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Renderer.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "Script.h"
#include "PrefabManager.h"

class GameObject
{
private:
	GameObject* father;
	std::list<GameObject> son;
	bool component[4];
	//0.渲染器, 1.刚体，2.碰撞器，3.脚本 
	Renderer renderer;
	Rigidbody rigidbody;
	Collider collider;
	bool scriptIsNewed;
	std::string scriptName;
public:
	Script *script;
	//名字
	std::string name;
	//构造方法
	GameObject();
	//自身的位置，大小，旋转角度
	glm::vec2 size;
	float angle;
	glm::vec2 position;
	void Translate(float deltaX,float deltaY);
	void Rotate(float deltaA);
	void Scale(float dwidth, float dheight);
	//控制组件
	//渲染器
	void addRenderer(Renderer r);
	Renderer* getRenderer();
	void draw(glm::vec3 color);
	void draw(float r, float g, float b);
	//刚体
	void addRigidbody(Rigidbody r);
	Rigidbody* getRigidbody();
	void updateRigidbody();
	void impactRigidbody(glm::vec2 force);
	//碰撞器
	void addCollider(Collider c);
	void addCollider(Collider c, float x, float y, float width, float height);
	Collider* getCollider();
	//脚本
	void addScript(std::string name);
	void startScript();
	void updateScript();
	Script* getScript();

	void reLoadScript();
};

