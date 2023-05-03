#pragma once
#include <algorithm>
#include "../systems/System.h"
#include <unordered_map>
#include "../nodes/JumpNode.h"
#include "../utilities/Collider.h"

class JumpSystem : System<JumpNode>
{
public:
    JumpSystem(std::unordered_map<std::string, JumpNode> nodes)
        : nodes(std::move(nodes)){}

    void addNodeEmplace(std::string&& uuid, JumpNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process()
    {
        std::ranges::for_each(nodes, [this](std::pair<const std::string, JumpNode> pair)
            {
            auto doodleCoord = pair.second.getDoodleCoord();
            auto platformCood = pair.second.getPlatformCoord();
            auto doodleSize = pair.second.getDoodleSize();
            auto platformSize = pair.second.getPlatformSize();

            double a1x = doodleCoord->getXCor();
            double a2x = doodleCoord->getXCor() + doodleSize.getWidth();
            double a2y = doodleCoord->getYCor() + doodleSize.getHeigth();
            double b1x = platformCood->getXCor();
            double b2x = platformCood->getXCor() + platformSize.getWidth();
            double b1y = platformCood->getYCor();
            double b2y = platformCood->getYCor() + platformSize.getHeigth();
            
                if(Collider::isCollideBelowLeftRight(a1x, a2x, a2y, b1x, b2x, b1y, b2y) && * pair.second.getGravitationSpeed() > 0)
                {
                    if(pair.second.getLastScore() < pair.second.getScore())
                    {
                        *pair.second.getJumpCounter() += 1;
                    }
                    *pair.second.getGravitationSpeed() = pair.second.getJumpForce() * -1;
                }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::unordered_map<std::string, JumpNode> nodes;
};
