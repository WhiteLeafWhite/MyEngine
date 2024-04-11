#pragma once
#include <mutex>
#include <vector>
#include "GameObject.h"
class GameObjectManager
{
public:
	static GameObjectManager* getinstance();
	void emplace_go(GameObject go);
	void draw_all();
	void draw_all(float r,float g,float b);
	void start_all();
	void updateScript_all();
	void uodateRigidbody_all();
	GameObject& getObject(int id);
private:
	static GameObjectManager* gomanager;
	GameObjectManager():idCounter(0) {}
	GameObjectManager(const GameObjectManager& gm) = delete;
	GameObjectManager operator =(const GameObjectManager& x) = delete;
	static std::mutex gom_mutex;
	std::map<int,GameObject> gos;
	int idCounter;
};
