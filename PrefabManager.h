#pragma once

#ifndef PREFABMANAGER
#define PREFABMANAGER

#include<map>
#include<string>
#include<functional>
#include"GameObject.h"
#include"Script.h"

class PrefabManager
{
public:
	//´¢´æprefabs
	static std::map<std::string, std::function<GameObject(void)> > PrefabFactory;
	static std::map<std::string, GameObject> Prefabs;
	static std::map<std::string, Script*> Scripts;
	static GameObject LoadPrefab(GameObject go,std::string name);
	static GameObject LoadPrefab(std::function<GameObject()> func, std::string name);
	static GameObject GetPrefab(std::string name);
	static GameObject MakePrefab(std::string name);
	static void LoadScript(Script* s,std::string name);
	static Script* GetScript(std::string name);
};

#endif // PREFABMANAGER