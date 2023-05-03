#pragma once

#include <memory>
#include "Framework.h"
#include "../components/CoordSystemR2.h"

class ConstantXMoveNode
{
public:
    ConstantXMoveNode(std::shared_ptr<CoordSystemR2> coord, std::shared_ptr<int> moveDistance, std::shared_ptr<FRKey> pressedKey)
        : coord(std::move(coord)), moveDistance(std::move(moveDistance)), pressedKey(std::move(pressedKey)){}

    CoordSystemR2 getCoord()
    {
        return *coord;
    }

    void shiftCoord(double x, double y)
    {
        this->coord->setXCor(coord->getXCor() + x);
        this->coord->setYCor(coord->getYCor() + y);
    }

    int getMoveDistance()
    {
        return *moveDistance;
    }

    FRKey getpressedKey()
    {
        return *pressedKey;
    }
    
private:
    std::shared_ptr<CoordSystemR2> coord;
    std::shared_ptr<int> moveDistance;
    std::shared_ptr<FRKey> pressedKey;
};
