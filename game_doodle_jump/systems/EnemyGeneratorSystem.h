#pragma once
#include <algorithm>
#include <unordered_map>
#include <utility>
#include "EnemyMovingSystem.h"
#include "JumpOnEnemySystem.h"
#include "RenderSystem.h"
#include "../components/SizeR2.h"
#include "../entities/PlatformObject.h"
#include "../factories/SharedComponentsFactory.h"
#include "../utilities/RandomValueGenerator.h"
#include "../utilities/UUID.h"

class EnemyGeneratorSystem : InputSystem<EnemyGeneratorNode, CoordSystemR2>
{
public:
    EnemyGeneratorSystem(std::shared_ptr<RenderSystem> renderSystem, std::shared_ptr<EnemyMovingSystem> enemyMovingSystem,
        std::shared_ptr<JumpOnEnemySystem> jumpOnEnemySystem,  std::unordered_map<std::string, EnemyGeneratorNode> nodes)
        : renderSystem(std::move(renderSystem)),
        enemyMovingSystem(std::move(enemyMovingSystem)),
        jumpOnEnemySystem(jumpOnEnemySystem),
        nodes(std::move(nodes)){}

    void addNodeEmplace(std::string&& uuid, EnemyGeneratorNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process(CoordSystemR2 platformCoord)
    {
        std::ranges::for_each(nodes, [this, &platformCoord](std::pair<const std::string, EnemyGeneratorNode> pair)
            {
                if( pair.second.getRandomValueGenerator()->generateRandomInt() / pair.second.getProbability() < 1)
                {
                    auto enemySize = pair.second.getEnemySize();
                    auto enemyCoord = std::make_shared<CoordSystemR2>(CoordSystemR2(platformCoord.getXCor(), platformCoord.getYCor() - enemySize.getHeigth()));

                    auto enemyUUID = UUID::generate();
                    RenderNode renderNode = NodesFactory::makeRenderNode(pair.second.getSprite(),
                        enemyCoord, enemySize);
                    EnemyMovingNode enemyMovingNode = NodesFactory::makeEnemyMovingNode(pair.second.getGravitationSpeed(),
                        pair.second.getScreenResolution(), enemyCoord, pair.second.getRemovingUUID(), enemyUUID);
                    JumpOnEnemyNode jumpOnEnemyNode(NodesFactory::makeJumpOnEnemyNode(pair.second.getDoodleCoord(), enemyCoord,
                        pair.second.getGravitationSpeed(), pair.second.getDoodleSize(), enemySize, pair.second.IsGameOver(),
                        pair.second.getRemovingUUID(), enemyUUID));
                    
                    renderSystem->addNodeEmplace(enemyUUID.c_str(), renderNode);
                    enemyMovingSystem->addNodeEmplace(enemyUUID.c_str(), enemyMovingNode);
                    jumpOnEnemySystem->addNodeEmplace(enemyUUID.c_str(), jumpOnEnemyNode);
                    
                    pair.second.getEnemies()->emplace(pair.second.getEnemies()->begin(), enemyUUID.c_str(), renderNode, enemyMovingNode, jumpOnEnemyNode);
                }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::shared_ptr<RenderSystem> renderSystem;
    std::shared_ptr<EnemyMovingSystem> enemyMovingSystem;
    std::shared_ptr<JumpOnEnemySystem> jumpOnEnemySystem;
    std::unordered_map<std::string, EnemyGeneratorNode> nodes;
};
