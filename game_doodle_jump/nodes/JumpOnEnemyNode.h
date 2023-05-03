#pragma once
#include <memory>
#include <utility>

class JumpOnEnemyNode
{
public:
    JumpOnEnemyNode(std::shared_ptr<CoordSystemR2> doodleCoord, std::shared_ptr<CoordSystemR2> enemyCoord,
        std::shared_ptr<double> gravitationSpeed, SizeR2 doodleSize, SizeR2 enemySize, std::shared_ptr<bool> isGameOver,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::string enemyUUID)
        : doodleCoord(std::move(doodleCoord)),
          enemyCoordinates(std::move(enemyCoord)),
          gravitationSpeed(std::move(gravitationSpeed)),
          doodleSize(doodleSize),
          enemySize(enemySize),
          isGameOver(std::move(isGameOver)),
          removingUUID(std::move(removingUUID)),
          enemyUUID(std::move(enemyUUID)){}

    std::shared_ptr<CoordSystemR2> getDoodleCoord()
    {
        return doodleCoord;
    }

    void setEnemyCoord(double x, double y)
    {
        this->enemyCoordinates->setXCor(x);
        this->enemyCoordinates->setYCor(y);
    }

    std::shared_ptr<CoordSystemR2> getEnemyCoord()
    {
        return enemyCoordinates;
    }

    std::shared_ptr<double> getGravitationSpeed()
    {
        return gravitationSpeed;
    }

    SizeR2 getDoodleSize()
    {
        return doodleSize;
    }

    SizeR2 getEnemySize()
    {
        return enemySize;
    }

    std::shared_ptr<bool> IsGameOver()
    {
        return isGameOver;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID() const
    {
        return removingUUID;
    }

    std::string getEnemyUUID() const
    {
        return enemyUUID;
    }

private:
    std::shared_ptr<CoordSystemR2> doodleCoord;
    std::shared_ptr<CoordSystemR2> enemyCoordinates;
    std::shared_ptr<double> gravitationSpeed;
    SizeR2 doodleSize;
    SizeR2 enemySize;
    std::shared_ptr<bool> isGameOver;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::string enemyUUID;
};
