#pragma once
#include <memory>
#include <utility>
#include "../components/CoordSystemR2.h"
#include "../components/SizeR2.h"
#include "../utilities/AdapterScreenResolution.h""

class RandomValueGenerator;

class PlatformMovingNode
{
public:
    PlatformMovingNode(std::shared_ptr<double> gravitationSpeed, AdapterScreenResolution screen_resolution, SizeR2 size, std::shared_ptr<CoordSystemR2> coord,
        std::shared_ptr<RandomValueGenerator> platformXCordRandomValueGenerator,
        std::shared_ptr<RandomValueGenerator> platformYCordRandomValueGenerator)
        : gravitationSpeed(std::move(gravitationSpeed)),
          screenResolution(screen_resolution),
          size(size),
          coord(std::move(coord)),
          platformXCordRandomValueGenerator(std::move(platformXCordRandomValueGenerator)),
          platformYCordRandomValueGenerator(std::move(platformYCordRandomValueGenerator)){}
    
    std::shared_ptr<double> getGravitationSpeed() const
    {
        return gravitationSpeed;
    }

    AdapterScreenResolution getScreenResolution() const
    {
        return screenResolution;
    }

    SizeR2 getSize() const
    {
        return size;
    }

    std::shared_ptr<CoordSystemR2> getCoord() const
    {
        return coord;
    }

    void setCoord(double x, double y)
    {
        this->coord->setXCor(x);
        this->coord->setYCor(y);
    }

    std::shared_ptr<RandomValueGenerator> getPlatformXCordRandomValueGenerator() const
    {
        return platformXCordRandomValueGenerator;
    }

    std::shared_ptr<RandomValueGenerator> getPlatformYCordRandomValueGenerator() const
    {
        return platformYCordRandomValueGenerator;
    }

private:
    std::shared_ptr<double> gravitationSpeed;
    AdapterScreenResolution screenResolution;
    SizeR2 size;
    std::shared_ptr<CoordSystemR2> coord;
    std::shared_ptr<RandomValueGenerator> platformXCordRandomValueGenerator;
    std::shared_ptr<RandomValueGenerator> platformYCordRandomValueGenerator;
};
