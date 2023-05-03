#pragma once

#include <memory>
#include <utility>
#include <vector>
#include "../components/SizeR2.h"
#include "../entities/EnemyObject.h"
#include "../entities/PlatformObject.h"
#include "../utilities/RandomValueGenerator.h"

class EnemyGeneratorNode
{
public:
    EnemyGeneratorNode(Sprite* const sprite, const double probability, SizeR2 enemySize,
        std::shared_ptr<RandomValueGenerator> randomValueGenerator, std::shared_ptr<std::vector<EnemyObject>> enemies,
        std::shared_ptr<double> gravitationSpeed, AdapterScreenResolution screenResolution,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::shared_ptr<CoordSystemR2> doodleCoord, SizeR2 doodleSize,
        std::shared_ptr<bool> isGameOver)
        : sprite(sprite),
          probability(probability),
          enemySize(enemySize),
          randomValueGenerator(std::move(randomValueGenerator)),
          enemies(std::move(enemies)),
          gravitationSpeed(std::move(gravitationSpeed)),
          screenResolution(screenResolution),
          removingUUID(std::move(removingUUID)),
          doodleCoord(std::move(doodleCoord)),
          doodleSize(doodleSize),
          isGameOver(std::move(isGameOver)){}

    double getProbability()
    {
        return probability;
    }

    SizeR2 getEnemySize()
    {
        return enemySize;
    }

    std::shared_ptr<RandomValueGenerator> getRandomValueGenerator()
    {
        return randomValueGenerator;
    }

    std::shared_ptr<std::vector<EnemyObject>> getEnemies()
    {
        return enemies;
    }

    Sprite* getSprite()
    {
        return sprite;
    }

    std::shared_ptr<double> getGravitationSpeed() const
    {
        return gravitationSpeed;
    }

    AdapterScreenResolution getScreenResolution() const
    {
        return screenResolution;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID() const
    {
        return removingUUID;
    }

    std::shared_ptr<CoordSystemR2> getDoodleCoord()
    {
        return doodleCoord;
    }

    SizeR2 getDoodleSize()
    {
        return doodleSize;
    }

    std::shared_ptr<bool> IsGameOver()
    {
        return isGameOver;
    }

private:
    Sprite* sprite;
    double probability;
    SizeR2 enemySize;
    std::shared_ptr<RandomValueGenerator> randomValueGenerator;
    std::shared_ptr<std::vector<EnemyObject>> enemies;
    std::shared_ptr<double> gravitationSpeed;
    AdapterScreenResolution screenResolution;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::shared_ptr<CoordSystemR2> doodleCoord;
    SizeR2 doodleSize;
    std::shared_ptr<bool> isGameOver;
};
