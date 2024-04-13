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
    for (auto& id_go : gos) {
        id_go.second.updateScript();
        Collider* now = id_go.second.getCollider();
        if (now) {
            for (auto& id_go2 : gos) {
                Collider* temp = id_go2.second.getCollider();
                if (temp->isColliding(*id_go.second.getCollider())) {
                    id_go.second.getScript()->onColliderEnter(&id_go.second,*temp);
                }
            }
        }
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
    // TODO: �ڴ˴����� return ���
    return gos[id];
}
