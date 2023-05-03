#pragma once
#include <algorithm>
#include <chrono>
#include "../systems/System.h"
#include <unordered_map>

class EnemyMovingSystem : System<EnemyMovingNode>
{
public:
    EnemyMovingSystem(std::unordered_map<std::string, EnemyMovingNode> nodes)
        : nodes(std::move(nodes)){}

    void addNodeEmplace(std::string&& uuid, EnemyMovingNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process()
    {
        std::ranges::for_each(nodes, [this](std::pair<const std::string, EnemyMovingNode> pair)
            {
            auto coord = pair.second.getCoord();
            pair.second.setCoord(coord->getXCor(), coord->getYCor() - *pair.second.getGravitationSpeed());
            if(coord->getYCor() > pair.second.getScreenResolution().height)
            {
                pair.second.getRemovingUUID()->emplace(pair.second.getRemovingUUID()->begin(), pair.second.getUUID());
            }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::unordered_map<std::string, EnemyMovingNode> nodes;
};

