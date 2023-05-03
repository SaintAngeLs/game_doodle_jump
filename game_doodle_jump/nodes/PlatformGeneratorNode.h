#pragma once

#include <memory>
#include <utility>
#include <vector>
#include "../components/SizeR2.h"
#include "../components/CoordSystemR2.h"
#include "../entities/PlatformObject.h"
#include "Framework.h"
#include "../utilities/AdapterScreenResolution.h"
#include "../utilities/RandomValueGenerator.h"

class PlatformGeneratorNode
{
public:
    PlatformGeneratorNode(Sprite* sprite, SizeR2 platformSize, SizeR2 doodleSize,
        AdapterScreenResolution screenResolution, std::shared_ptr<std::vector<PlatformObject>> platforms, const int platformAmount,
        std::shared_ptr<double> gravitationSpeed,
        std::shared_ptr<RandomValueGenerator> platformXCordRandomValueGenerator,
        std::shared_ptr<RandomValueGenerator> platformYCordRandomValueGenerator,
        std::shared_ptr<CoordSystemR2> doodleCoord, double jumpForce, std::shared_ptr<double> score, std::shared_ptr<double> lastScore,
        std::shared_ptr<int> jumpCounter)
        : sprite(std::move(sprite)),
          platformSize(platformSize),
          doodleSize(doodleSize),
          screenResolution(screenResolution),
          platforms(std::move(platforms)),
          platformAmount(platformAmount),
          gravitationSpeed(std::move(gravitationSpeed)),
          platformXCordRandomValueGenerator(std::move(platformXCordRandomValueGenerator)),
          platformYCordRandomValueGenerator(std::move(platformYCordRandomValueGenerator)),
          doodleCoord(std::move(doodleCoord)),
          jumpForce(jumpForce),
          score(std::move(score)),
          lastScore(std::move(lastScore)),
          jumpCounter(std::move(jumpCounter)){}

    Sprite* getSprite()
    {
        return sprite;
    }

    SizeR2 getPlatformSize()
    {
        return platformSize;
    }

    SizeR2 getDoodleSize()
    {
        return doodleSize;
    }

    AdapterScreenResolution getScreenResolution()
    {
        return screenResolution;
    }

    std::shared_ptr<std::vector<PlatformObject>> getPlatforms()
    {
        return platforms;
    }

    int getPlatformAmount()
    {
        return platformAmount;
    }

    std::shared_ptr<double> getGravitationSpeed()
    {
        return gravitationSpeed;
    }

    std::shared_ptr<RandomValueGenerator> getPlatformXCordRandomValueGenerator()
    {
        return platformXCordRandomValueGenerator;
    }

    std::shared_ptr<RandomValueGenerator> getPlatformYCordRandomValueGenerator()
    {
        return platformYCordRandomValueGenerator;
    }

    std::shared_ptr<CoordSystemR2> getDoodleCoord()
    {
        return doodleCoord;
    }

    double getJumpForce()
    {
        return jumpForce;
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

private:
    Sprite* sprite;
    SizeR2 platformSize;
    SizeR2 doodleSize;
    AdapterScreenResolution screenResolution;
    std::shared_ptr<std::vector<PlatformObject>> platforms;
    int platformAmount;
    std::shared_ptr<double> gravitationSpeed;
    std::shared_ptr<RandomValueGenerator> platformXCordRandomValueGenerator;
    std::shared_ptr<RandomValueGenerator> platformYCordRandomValueGenerator;
    std::shared_ptr<CoordSystemR2> doodleCoord;
    double jumpForce;
    std::shared_ptr<double> score;
    std::shared_ptr<double> lastScore;
    std::shared_ptr<int> jumpCounter;
};
