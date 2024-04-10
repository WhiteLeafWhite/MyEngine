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
	//0.��Ⱦ��, 1.���壬2.��ײ����3.�ű� 
	Renderer renderer;
	Rigidbody rigidbody;
	Collider collider;
	bool scriptIsNewed;
	std::string scriptName;
public:
	Script *script;
	//����
	std::string name;
	//���췽��
	GameObject();
	//�����λ�ã���С����ת�Ƕ�
	glm::vec2 size;
	float angle;
	glm::vec2 position;
	void Translate(float deltaX,float deltaY);
	void Rotate(float deltaA);
	void Scale(float dwidth, float dheight);
	//�������
	//��Ⱦ��
	void addRenderer(Renderer r);
	Renderer* getRenderer();
	void draw(glm::vec3 color);
	void draw(float r, float g, float b);
	//����
	void addRigidbody(Rigidbody r);
	Rigidbody* getRigidbody();
	void updateRigidbody();
	void impactRigidbody(glm::vec2 force);
	//��ײ��
	void addCollider(Collider c);
	void addCollider(Collider c, float x, float y, float width, float height);
	Collider* getCollider();
	//�ű�
	void addScript(std::string name);
	void startScript();
	void updateScript();
	Script* getScript();

	void reLoadScript();
};

