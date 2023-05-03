#pragma once
#include <memory>
#include <utility>

class ShootingEnemyNode
{
public:
    ShootingEnemyNode(std::shared_ptr<CoordSystemR2> projectileCoord, SizeR2 projectileSize, std::shared_ptr<std::vector<EnemyObject>> enemies,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::string projectileUUID)
        : projectileCoord(std::move(projectileCoord)),
          projectileSize(projectileSize),
          enemies(std::move(enemies)),
          removingUUID(std::move(removingUUID)),
          projectileUUID(std::move(projectileUUID)){}

    std::shared_ptr<CoordSystemR2> getProjectileCoord()
    {
        return projectileCoord;
    }

    void setProjectileCoord(double x, double y)
    {
        this->projectileCoord->setXCor(x);
        this->projectileCoord->setYCor(y);
    }

    SizeR2 getProjectileSize()
    {
        return projectileSize;
    }

    std::shared_ptr<std::vector<EnemyObject>> getEnemies()
    {
        return enemies;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID()
    {
        return removingUUID;
    }

    std::string getProjectileUUID()
    {
        return projectileUUID;
    }

private:
    std::shared_ptr<CoordSystemR2> projectileCoord;
    SizeR2 projectileSize;
    std::shared_ptr<std::vector<EnemyObject>> enemies;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::string projectileUUID;
};
