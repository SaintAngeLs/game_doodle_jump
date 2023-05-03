#pragma once

#include <memory>
#include <utility>
#include "Framework.h"
#include "../components/CoordSystemR2.h"
#include "../entities/EnemyObject.h"

class ProjectileGeneratorNode
{
public:
    ProjectileGeneratorNode(SizeR2 size, Sprite* sprite, std::shared_ptr<CoordSystemR2> mouseCoord,
        std::shared_ptr<CoordSystemR2> doodleCoord, std::shared_ptr<double> moveDistance,
        std::shared_ptr<FRMouseButton> pressedMouseButton, SizeR2 doodleSize, std::shared_ptr<std::vector<EnemyObject>> enemies,
        std::shared_ptr<std::vector<std::string>> removingUUID)
        : size(std::move(size)),
          sprite(std::move(sprite)),
          mouseCoord(std::move(mouseCoord)),
          doodleCoord(std::move(doodleCoord)),
          moveDistance(std::move(moveDistance)),
          pressedMouseButton(std::move(pressedMouseButton)),
          doodleSize(doodleSize),
          enemies(std::move(enemies)),
          removingUUID(std::move(removingUUID)){}

    SizeR2 getSize()
    {
        return size;
    }

    Sprite* getSprite()
    {
        return sprite;
    }

    CoordSystemR2 getMouseCoord()
    {
        return *mouseCoord;
    }

    CoordSystemR2 getDoodleCoord()
    {
        return *doodleCoord;
    }

    double getMoveDistance()
    {
        return *moveDistance;
    }

    FRMouseButton getPressedMouseButton()
    {
        return *pressedMouseButton;
    }

    SizeR2 getDoodleSize()
    {
        return doodleSize;
    }

    std::shared_ptr<std::vector<EnemyObject>> getEnemies()
    {
        return enemies;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID() const
    {
        return removingUUID;
    }

private:
    SizeR2 size;
    Sprite* sprite;
    std::shared_ptr<CoordSystemR2> mouseCoord;
    std::shared_ptr<CoordSystemR2> doodleCoord;
    std::shared_ptr<double> moveDistance;
    std::shared_ptr<FRMouseButton> pressedMouseButton;
    SizeR2 doodleSize;
    std::shared_ptr<std::vector<EnemyObject>> enemies;
    std::shared_ptr<std::vector<std::string>> removingUUID;
};
