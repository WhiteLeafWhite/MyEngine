#include "GameObjectManager.h"

std::mutex GameObjectManager::gom_mutex;
GameObjectManager* GameObjectManager::gomanager = nullptr;

GameObjectManager* GameObjectManager::getinstance()
{
    if (gomanager == nullptr) {
        std::lock_guard<std::mutex> m(gom_mutex);
        if (gomanager == nullptr) {
            gomanager = new GameObjectManager();
        }
    }
    return gomanager;
}

void GameObjectManager::emplace_go(GameObject go)
{
    gos.emplace_back(std::move(go));
}

void GameObjectManager::draw_all()
{
    for (int i = 0; i < gos.size(); ++i) {
        gos[i].draw(1, 1, 1);
    }
}

void GameObjectManager::draw_all(float r, float g, float b)
{
    for (int i = 0; i < gos.size(); ++i) {
        gos[i].draw(r, g, b);
    }
}

void GameObjectManager::start_all()
{
    for (int i = 0; i < gos.size(); ++i) {
        gos[i].startScript();
    }
}

void GameObjectManager::updateScript_all()
{
    for (int i = 0; i < gos.size(); ++i) {
        gos[i].updateScript();
    }
}

void GameObjectManager::uodateRigidbody_all()
{
    for (int i = 0; i < gos.size(); ++i) {
        gos[i].updateRigidbody();
    }
}
