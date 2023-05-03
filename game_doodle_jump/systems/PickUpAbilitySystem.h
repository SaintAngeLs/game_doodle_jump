#pragma once
#include <algorithm>
#include <unordered_map>
#include "../utilities/Collider.h"

class PickUpAbilitySystem : System<PickUpAbilityNode>
{
public:
    PickUpAbilitySystem(std::shared_ptr<AbilitySystem> abilitySystem,
        std::unordered_map<std::string, PickUpAbilityNode> nodes)
        : abilitySystem(std::move(abilitySystem)),
          nodes(std::move(nodes)){}

    void addNodeEmplace(std::string&& uuid, PickUpAbilityNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process()
    {
        std::ranges::for_each(nodes, [this](std::pair<const std::string, PickUpAbilityNode> pair)
            {
            auto doodleCoord = pair.second.getDoodleCoord();
            auto abilityCoord = pair.second.getAbilityCoord();
            auto doodleSize = pair.second.getDoodleSize();
            auto abilitySize = pair.second.getAbilitySize();

            double a1x = doodleCoord->getXCor();
            double a2x = doodleCoord->getXCor() + doodleSize.getWidth();
            double a1y = doodleCoord->getYCor();
            double a2y = doodleCoord->getYCor() + doodleSize.getHeigth();
            double b1x = abilityCoord->getXCor();
            double b2x = abilityCoord->getXCor() + abilitySize.getWidth();
            double b1y = abilityCoord->getYCor();
            double b2y = abilityCoord->getYCor() + abilitySize.getHeigth();

                if(Collider::isCollide(a1x, a2x, a1y, a2y, b1x, b2x, b1y, b2y))
                {
                    pair.second.getRemovingUUID()->emplace(pair.second.getRemovingUUID()->begin(), pair.second.getAbilityUUID());

                    auto UUID = UUID::generate();
                    auto abilityNode = AbilityNode(pair.second.getEnemies(), pair.second.getMouseCoord(),
                        pair.second.getPressedMouseButton(), pair.second.getRemovingUUID(), UUID);
                    abilitySystem->addNodeEmplace(UUID.c_str(), abilityNode);
                }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::shared_ptr<AbilitySystem> abilitySystem;
    std::unordered_map<std::string, PickUpAbilityNode> nodes;
};
