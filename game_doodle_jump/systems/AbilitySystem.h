#pragma once
#include <algorithm>
#include <unordered_map>
#include <timercpp.h>

#include "ProjectileGeneratorSystem.h"
#include "System.h"
#include "../entities/EnemyObject.h"

class AbilitySystem : System<AbilityNode>
{
public:
    AbilitySystem(std::shared_ptr<ProjectileGeneratorSystem> projectileGeneratorSystem,
        std::unordered_map<std::string, AbilityNode> nodes)
        : projectileGeneratorSystem(std::move(projectileGeneratorSystem)),
          nodes(std::move(nodes)){}

    void addNodeEmplace(std::string&& uuid, AbilityNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process()
    {
        std::ranges::for_each(nodes, [this](std::pair<const std::string, AbilityNode> pair)
            {
                for (EnemyObject enemy : *pair.second.getEnemies())
                {
                    auto doodleCoord = enemy.getJumpOnEnemyNode().getDoodleCoord();
                    auto enemyCoord = enemy.getJumpOnEnemyNode().getEnemyCoord();
                    auto gravitation = *enemy.getJumpOnEnemyNode().getGravitationSpeed();
                    if(enemyCoord->getYCor() > 100 && gravitation > -3 && gravitation < 3)
                    {pair.second.setPressedMouseButton(FRMouseButton::LEFT);
                    pair.second.setMouseCoord(enemy.getRenderNode().getCoord().getXCor(), enemy.getRenderNode().getCoord().getYCor());

                    projectileGeneratorSystem->process();
                    }
                }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::shared_ptr<ProjectileGeneratorSystem> projectileGeneratorSystem;
    std::unordered_map<std::string, AbilityNode> nodes;
};
