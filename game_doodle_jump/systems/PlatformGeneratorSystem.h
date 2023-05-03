#pragma once
#include <algorithm>
#include "../systems/System.h"
#include <unordered_map>
#include <utility>
#include "EnemyGeneratorSystem.h"
#include "JumpSystem.h"
#include "PlatformMovingSystem.h"
#include "RenderSystem.h"
#include "../factories/SharedComponentsFactory.h"
#include "../utilities/UUID.h"

class PlatformGeneratorSystem : System<PlatformGeneratorNode>
{
public:
    PlatformGeneratorSystem(std::shared_ptr<JumpSystem> jumpSystem, std::shared_ptr<RenderSystem> renderSystem,
        std::shared_ptr<PlatformMovingSystem> platformMovingSystem, std::unordered_map<std::string, PlatformGeneratorNode> nodes)
        : jumpSystem(std::move(jumpSystem)),
          renderSystem(std::move(renderSystem)),
          platformMovingSystem(std::move(platformMovingSystem)),
          nodes(std::move(nodes)){}

    void addNodeEmplace(std::string&& uuid, PlatformGeneratorNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process()
    {
        std::ranges::for_each(nodes, [this](std::pair<const std::string, PlatformGeneratorNode> pair)
            {
                for (int i = 0; i < pair.second.getPlatformAmount(); i++)
                {
                    auto platformCoord = std::make_shared<CoordSystemR2>(pair.second.getPlatformXCordRandomValueGenerator()->generateRandomInt(), pair.second.getPlatformYCordRandomValueGenerator()->generateRandomInt());
                    RenderNode renderNode = NodesFactory::makeRenderNode(pair.second.getSprite(), platformCoord, pair.second.getPlatformSize());
                    PlatformMovingNode movingNode = NodesFactory::makePlatformMovingNode(pair.second.getGravitationSpeed(),
                        pair.second.getScreenResolution(), pair.second.getPlatformSize(), platformCoord, pair.second.getPlatformXCordRandomValueGenerator(),
                        SharedComponentsFactory::createRandomValueGenerator(0, 75));
                    JumpNode jumpNode = NodesFactory::makeJumpNode(pair.second.getDoodleCoord(), platformCoord,
                        pair.second.getGravitationSpeed(), pair.second.getDoodleSize(), pair.second.getPlatformSize(),
                        pair.second.getJumpForce(), pair.second.getScore(), pair.second.getLastScore(), pair.second.getJumpCounter());
                    
                    auto platformUUID = UUID::generate();
                    renderSystem->addNodeEmplace(platformUUID.c_str(), renderNode);
                    platformMovingSystem->addNodeEmplace(platformUUID.c_str(), movingNode);
                    jumpSystem->addNodeEmplace(platformUUID.c_str(), jumpNode);
                    pair.second.getPlatforms()->emplace(pair.second.getPlatforms()->begin(), platformUUID.c_str(), renderNode, movingNode, jumpNode);
                }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::shared_ptr<JumpSystem> jumpSystem;
    std::shared_ptr<RenderSystem> renderSystem;
    std::shared_ptr<PlatformMovingSystem> platformMovingSystem;
    std::shared_ptr<EnemyGeneratorSystem> enemyGeneratorSystem;
    std::unordered_map<std::string, PlatformGeneratorNode> nodes;
};
