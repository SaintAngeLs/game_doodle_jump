#pragma once

#include <memory>
#include "../components/CoordSystemR2.h"

class GravitationNode
{
public:
    GravitationNode(std::shared_ptr<CoordSystemR2> subjectCoord, std::shared_ptr<double> gravitationSpeed)
        : subjectCoord(std::move(subjectCoord)),
          gravitationSpeed(gravitationSpeed){}

    CoordSystemR2 getSubjectCoord()
    {
        return *subjectCoord;
    }

    void shiftCoord(double x, double y)
    {
        this->subjectCoord->setXCor(subjectCoord->getXCor() + x);
        this->subjectCoord->setYCor(subjectCoord->getYCor() + y);
    }

    std::shared_ptr<double> getGravitationSpeed()
    {
        return gravitationSpeed;
    }
    
private:
    std::shared_ptr<CoordSystemR2> subjectCoord;
    std::shared_ptr<double> gravitationSpeed;
};
