#include "PrefabManager.h"
#include<iostream>

std::map<std::string, GameObject> PrefabManager::Prefabs;
std::map<std::string, std::function<GameObject()> > PrefabManager::PrefabFactory;
std::map<std::string, Script*> PrefabManager::Scripts;

GameObject PrefabManager::LoadPrefab(GameObject go, std::string name)
{
    Prefabs[name] = go;
    return go;
}

GameObject PrefabManager::LoadPrefab(std::function<GameObject()> func, std::string name)
{
    PrefabFactory[name] = func;
    return func();
}

GameObject PrefabManager::GetPrefab(std::string name)
{
    GameObject res = Prefabs[name];
    return res;
}

GameObject PrefabManager::MakePrefab(std::string name)
{
    return PrefabFactory[name]();
}

void PrefabManager::LoadScript(Script* s, std::string name)
{
    Scripts[name] = s;
}

Script* PrefabManager::GetScript(std::string name)
{
    return Scripts[name]->instance();
}
