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
    ++idCounter;
    go.getCollider()->gameObjectID = idCounter;
    go.name = go.name + std::to_string(idCounter);
    gos.insert(std::pair<int,GameObject>(idCounter,std::move(go)));
}

void GameObjectManager::draw_all()
{
    for (auto& id_go : gos) {
        id_go.second.draw(1, 1, 1);
    }
}

void GameObjectManager::draw_all(float r, float g, float b)
{
    for (auto& id_go : gos) {
        id_go.second.draw(r, g, b);
    }
}

void GameObjectManager::start_all()
{
    for (auto& id_go : gos) {
        id_go.second.startScript();
    }
}

void GameObjectManager::updateScript_all()
{
    std::map<GameObject*, GameObject*> CollidedObjects;
    for (auto& id_go : gos) {
        id_go.second.updateScript();
        Collider* now = id_go.second.getCollider();
        if (now) {
            for (auto& id_go2 : gos) {
                if (&id_go == &id_go2) continue;
                Collider* temp = id_go2.second.getCollider();
                if (temp->isColliding(*now)) {
                    CollidedObjects.insert(std::pair<GameObject*, GameObject*>(&id_go.second, &id_go2.second));
                }
            }
        }
    }
    for (auto& goPair : CollidedObjects) {
        goPair.first->getScript()->onColliderEnter(goPair.second, *goPair.second->getCollider());
        goPair.second->getScript()->onColliderEnter(goPair.first, *goPair.first->getCollider());
    }
}

void GameObjectManager::uodateRigidbody_all()
{
    for (auto& id_go : gos) {
        id_go.second.updateRigidbody();
    }
}

GameObject& GameObjectManager::getObject(int id)
{
    // TODO: 在此处插入 return 语句
    return gos[id];
}
