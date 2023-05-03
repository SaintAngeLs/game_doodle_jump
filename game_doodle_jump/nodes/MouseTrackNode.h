#pragma once

#include "../components/CoordSystemR2.h"
#include <memory>

class MouseTrackNode
{
public:
    MouseTrackNode(std::shared_ptr<CoordSystemR2> mouseCoord) : mouseCoord(std::move(mouseCoord)) {}

    CoordSystemR2 getCoord()
    {
        return *mouseCoord;
    }

    void setMouseCoord(double x, double y)
    {
        this->mouseCoord->setXCor(x);
        this->mouseCoord->setYCor(y);
    }

private:
    std::shared_ptr<CoordSystemR2> mouseCoord;
};
