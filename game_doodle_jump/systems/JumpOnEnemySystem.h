#pragma once
#include <algorithm>
#include <unordered_map>
#include "../utilities/Collider.h"

class JumpOnEnemySystem : System<JumpOnEnemyNode>
{
public:
    JumpOnEnemySystem(std::unordered_map<std::string, JumpOnEnemyNode> nodes)
        : nodes(std::move(nodes)){}

    void addNodeEmplace(std::string&& uuid, JumpOnEnemyNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process()
    {
        std::ranges::for_each(nodes, [this](std::pair<const std::string, JumpOnEnemyNode> pair)
            {
            auto doodleCoord = pair.second.getDoodleCoord();
            auto enemyCoord = pair.second.getEnemyCoord();
            auto doodleSize = pair.second.getDoodleSize();
            auto enemySize = pair.second.getEnemySize();

            double a1x = doodleCoord->getXCor();
            double a2x = doodleCoord->getXCor() + doodleSize.getWidth();
            double a1y = doodleCoord->getYCor();
            double a2y = doodleCoord->getYCor() + doodleSize.getHeigth();
            double b1x = enemyCoord->getXCor();
            double b2x = enemyCoord->getXCor() + enemySize.getWidth();
            double b1y = enemyCoord->getYCor();
            double b2y = enemyCoord->getYCor() + enemySize.getHeigth();

                if(Collider::isCollide(a1x, a2x, a1y, a2y, b1x, b2x, b1y, b2y))
                {
                    if(Collider::isCollideBelow(a2y, b1y, b2y))
                    {
                        pair.second.getRemovingUUID()->emplace(pair.second.getRemovingUUID()->begin(), pair.second.getEnemyUUID());
                    }
                    else
                    {
                        *pair.second.IsGameOver() = true;
                    }
                }
            
                
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::unordered_map<std::string, JumpOnEnemyNode> nodes;
};
