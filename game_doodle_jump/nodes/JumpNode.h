#pragma once
#include <memory>
#include "../components/CoordSystemR2.h"

class JumpNode
{
public:
    JumpNode(std::shared_ptr<CoordSystemR2> doodleCoord, std::shared_ptr<CoordSystemR2> platformCoord,
        std::shared_ptr<double> gravitationSpeed, SizeR2 doodleSize, SizeR2 platformSize, const double jumpForce,
        std::shared_ptr<double> score, std::shared_ptr<double> lastScore, std::shared_ptr<int> jumpCounter)
        : doodleCoordinates(std::move(doodleCoord)),
          platformCoordinates(std::move(platformCoord)),
          gravitationSpeed(std::move(gravitationSpeed)),
          doodleSize(doodleSize),
          platformSize(platformSize),
          jumpForce(jumpForce),
          score(std::move(score)),
          lastScoreObtained(std::move(lastScore)),
          jumpCounter(std::move(jumpCounter)){}

    std::shared_ptr<CoordSystemR2> getDoodleCoord()
    {
        return doodleCoordinates;
    }

    std::shared_ptr<CoordSystemR2> getPlatformCoord()
    {
        return platformCoordinates;
    }

    std::shared_ptr<double> getGravitationSpeed()
    {
        return gravitationSpeed;
    }

    SizeR2 getDoodleSize()
    {
        return doodleSize;
    }

    SizeR2 getPlatformSize()
    {
        return platformSize;
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
        return lastScoreObtained;
    }

    std::shared_ptr<int> getJumpCounter()
    {
        return jumpCounter;
    }

private:
    std::shared_ptr<CoordSystemR2> doodleCoordinates;
    std::shared_ptr<CoordSystemR2> platformCoordinates;
    std::shared_ptr<double> gravitationSpeed;
    SizeR2 doodleSize;
    SizeR2 platformSize;
    double jumpForce;
    std::shared_ptr<double> score;
    std::shared_ptr<double> lastScoreObtained;
    std::shared_ptr<int> jumpCounter;
};
