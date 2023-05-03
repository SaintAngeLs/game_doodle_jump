#pragma once
#include <utility>

#include "../utilities/RandomValueGenerator.h"
#include "../components/CoordSystemR2.h"

class SharedComponentsHolder
{
public:
    SharedComponentsHolder(std::shared_ptr<CoordSystemR2> doodleCoord, std::shared_ptr<CoordSystemR2> mouseCoord,
        std::shared_ptr<FRKey> pressedKey, std::shared_ptr<FRMouseButton> pressedMouseButton,
        AdapterScreenResolution screenResolution, std::shared_ptr<double> gravitation,
        std::shared_ptr<std::vector<PlatformObject>> platforms,
        std::shared_ptr<RandomValueGenerator> platformXCordRandomValueGenerator,
        std::shared_ptr<RandomValueGenerator> platformYCordRandomValueGenerator,
        std::shared_ptr<RandomValueGenerator> enemyRandomValueGenerator,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::shared_ptr<double> score, std::shared_ptr<double> lastScore,
        std::shared_ptr<int> jumpCounter, std::shared_ptr<bool> isGameOver, std::shared_ptr<std::vector<EnemyObject>> enemies)
        : doodleCoord(std::move(doodleCoord)),
        mouseCoord(std::move(mouseCoord)),
        pressedKey(std::move(pressedKey)),
        pressedMouseButton(std::move(pressedMouseButton)),
        screenResolution(screenResolution),
        gravitation(std::move(gravitation)),
        platforms(std::move(platforms)),
        platformXCordRandomValueGenerator(std::move(platformXCordRandomValueGenerator)),
        platformYCordRandomValueGenerator(std::move(platformYCordRandomValueGenerator)),
        enemyRandomValueGenerator(std::move(enemyRandomValueGenerator)),
        removingUUID(std::move(removingUUID)),
        score(std::move(score)),
        lastScore(std::move(lastScore)),
        jumpCounter(std::move(jumpCounter)),
        isGameOver(std::move(isGameOver)),
        enemies(std::move(enemies)){}

    std::shared_ptr<CoordSystemR2> getBackgroundCoord()
    {
        return BackgroundCoord;
    }

    std::shared_ptr<CoordSystemR2> getDoodleCoord()
    {
        return doodleCoord;
    }

    std::shared_ptr<CoordSystemR2> getMouseCoord()
    {
        return mouseCoord;
    }

    std::shared_ptr<FRKey> getPressedKey()
    {
        return pressedKey;
    }

    std::shared_ptr<FRMouseButton> getPressedMouseButton()
    {
        return pressedMouseButton;
    }

    AdapterScreenResolution getScreenResolution()
    {
        return screenResolution;
    }

    std::shared_ptr<double> getGravitation()
    {
        return gravitation;
    }

    std::shared_ptr<std::vector<PlatformObject>> getPlatforms()
    {
        return platforms;
    }

    std::shared_ptr<RandomValueGenerator> getPlatformXCordRandomValueGenerator()
    {
        return platformXCordRandomValueGenerator;
    }

    std::shared_ptr<RandomValueGenerator> getPlatformYCordRandomValueGenerator()
    {
        return platformYCordRandomValueGenerator;
    }

    std::shared_ptr<RandomValueGenerator> getEnemyRandomValueGenerator()
    {
        return enemyRandomValueGenerator;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID()
    {
        return removingUUID;
    }

    std::shared_ptr<double> getScore()
    {
        return score;
    }

    std::shared_ptr<double> getLastScore()
    {
        return lastScore;
    }

    std::shared_ptr<int> getJumpCounter()
    {
        return jumpCounter;
    }

    std::shared_ptr<bool> IsGameOver()
    {
        return isGameOver;
    }

    std::shared_ptr<std::vector<EnemyObject>> getEnemies()
    {
        return enemies;
    }

private:
    std::shared_ptr<CoordSystemR2> BackgroundCoord;
    std::shared_ptr<CoordSystemR2> doodleCoord;
    std::shared_ptr<CoordSystemR2> mouseCoord;
    std::shared_ptr<FRKey> pressedKey;
    std::shared_ptr<FRMouseButton> pressedMouseButton;
    AdapterScreenResolution screenResolution;
    std::shared_ptr<double> gravitation;
    std::shared_ptr<std::vector<PlatformObject>> platforms;
    std::shared_ptr<RandomValueGenerator> platformXCordRandomValueGenerator;
    std::shared_ptr<RandomValueGenerator> platformYCordRandomValueGenerator;
    std::shared_ptr<RandomValueGenerator> enemyRandomValueGenerator;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::shared_ptr<double> score;
    std::shared_ptr<double> lastScore;
    std::shared_ptr<int> jumpCounter;
    std::shared_ptr<bool> isGameOver;
    std::shared_ptr<std::vector<EnemyObject>> enemies;
};
