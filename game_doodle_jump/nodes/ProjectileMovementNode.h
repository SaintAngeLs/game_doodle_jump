#pragma once
#include "../components/Speed.h"

class ProjectileMovementNode
{
public:
    ProjectileMovementNode(std::shared_ptr<CoordSystemR2> coord, std::shared_ptr<Speed> speed)
        : coord(std::move(coord)), speed(std::move(speed)){}

    CoordSystemR2 getCoord()
    {
        return *coord;
    }

    Speed getSpeed()
    {
        return *speed;
    }

    void shiftCoord(double x, double y)
    {
        this->coord->setXCor(coord->getXCor() + x);
        this->coord->setYCor(coord->getYCor() + y);
    }

    void shiftSpeed(double x, double y)
    {
        this->speed->setX(speed->getX() + x*100);
        this->speed->setY(speed->getY() + y);
    }

private:
    std::shared_ptr<CoordSystemR2> coord;
    std::shared_ptr<Speed> speed;
};

