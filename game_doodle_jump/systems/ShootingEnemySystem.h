#pragma once
#include <algorithm>
#include <unordered_map>

#include "System.h"
#include "../utilities/Collider.h"
#include "../nodes/ShootingEnemyNode.h"

class ShootingEnemySystem : System<ShootingEnemyNode>
{
public:
    ShootingEnemySystem(std::unordered_map<std::string, ShootingEnemyNode> nodes)
        : nodes(std::move(nodes)){}

    void addNodeEmplace(std::string&& uuid, ShootingEnemyNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process()
    {
        std::ranges::for_each(nodes, [this](std::pair<const std::string, ShootingEnemyNode> pair)
            {
            for (EnemyObject &enemy : *pair.second.getEnemies())
            {
                auto projectileCoord = pair.second.getProjectileCoord();
                auto enemyCoord = enemy.getRenderNode().getCoord();
                auto projectileSize = pair.second.getProjectileSize();
                auto enemySize = enemy.getRenderNode().getSize();
                
                double a1x = projectileCoord->getXCor();
                double a2x = projectileCoord->getXCor() + projectileSize.getWidth();
                double a1y = projectileCoord->getYCor();
                double a2y = projectileCoord->getYCor() + projectileSize.getHeigth();
                double b1x = enemyCoord.getXCor();
                double b2x = enemyCoord.getXCor() + enemySize.getWidth();
                double b1y = enemyCoord.getYCor();
                double b2y = enemyCoord.getYCor() + enemySize.getHeigth();
                
                if(Collider::isCollide(a1x, a2x, a1y, a2y, b1x, b2x, b1y, b2y))
                {
                    pair.second.getRemovingUUID()->emplace(pair.second.getRemovingUUID()->begin(), enemy.getUUID());
                    pair.second.getRemovingUUID()->emplace(pair.second.getRemovingUUID()->begin(), pair.second.getProjectileUUID());
                }
            }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::unordered_map<std::string, ShootingEnemyNode> nodes;
};
