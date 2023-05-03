#pragma once
#include "../components/SizeR2.h"
#include "../utilities/AdapterScreenResolution.h"

class BeyondBondaryMovingNode
{
public:
    BeyondBondaryMovingNode(std::shared_ptr<CoordSystemR2> doodleCoord, AdapterScreenResolution screenResolution, SizeR2 size)
        : doodleCoord(doodleCoord),
          screenResolution(screenResolution),
          size(size){}

    CoordSystemR2 getDoodleCoord()
    {
        return *doodleCoord;
    }

    void setDoodleCoord(double x, double y)
    {
        this->doodleCoord->setXCor(x);
        this->doodleCoord->setYCor(y);
    }
    
    AdapterScreenResolution getScreenResolution()
    {
        return screenResolution;
    }

    SizeR2 getSize()
    {
        return size;
    }
    
private:
    std::shared_ptr<CoordSystemR2> doodleCoord;
    AdapterScreenResolution screenResolution;
    SizeR2 size;
};
