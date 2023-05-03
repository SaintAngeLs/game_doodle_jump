#pragma once
#include <algorithm>
#include "../systems/System.h"
#include "../systems/AbilityGeneratorSystem.h"
#include "../systems/EnemyGeneratorSystem.h"
#include <unordered_map>

class PlatformMovingSystem : System<PlatformMovingNode>
{
public:
    PlatformMovingSystem(std::shared_ptr<EnemyGeneratorSystem> enemy_generation_system,
        std::shared_ptr<AbilityGeneratorSystem> ability_generation_system,
        std::unordered_map<std::string, PlatformMovingNode> nodes)
        : enemyGenerationSystem(std::move(enemy_generation_system)),
          abilityGenerationSystem(std::move(ability_generation_system)),
          nodes(std::move(nodes)){}

    void addNodeEmplace(std::string&& uuid, PlatformMovingNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process()
    {
        std::ranges::for_each(nodes, [this](std::pair<const std::string, PlatformMovingNode> pair)
            {
            auto coord = pair.second.getCoord();
            pair.second.setCoord(pair.second.getCoord()->getXCor(), coord->getYCor() - *pair.second.getGravitationSpeed());
            if(coord->getYCor() > pair.second.getScreenResolution().height)
            {
                CoordSystemR2 newCoord(pair.second.getPlatformXCordRandomValueGenerator()->generateRandomInt(),
                    pair.second.getPlatformYCordRandomValueGenerator()->generateRandomInt() * -1);
                pair.second.setCoord(newCoord.getXCor(), newCoord.getYCor());
                enemyGenerationSystem->process(newCoord);
                abilityGenerationSystem->process(newCoord);
            }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::shared_ptr<EnemyGeneratorSystem> enemyGenerationSystem;
    std::shared_ptr<AbilityGeneratorSystem> abilityGenerationSystem;
    std::unordered_map<std::string, PlatformMovingNode> nodes;
};

