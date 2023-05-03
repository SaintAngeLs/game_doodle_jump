#pragma once
#include <memory>
#include <utility>
#include "../components/CoordSystemR2.h"
#include "../utilities/AdapterScreenResolution.h"



class HeightMonitoringNode
{
public:
    HeightMonitoringNode(std::shared_ptr<CoordSystemR2> coord, double maxHeight, std::shared_ptr<double> score,
        AdapterScreenResolution screenResolution, std::shared_ptr<bool> isGameOver)
        : coord(std::move(coord)),
          maxHeight(maxHeight),
          score(std::move(score)),
          screenResolution(screenResolution),
          isGameOver(std::move(isGameOver)){}

    CoordSystemR2 getCoord()
    {
        return *coord;
    }

    void setCoord(double x, double y)
    {
        this->coord->setXCor(x);
        this->coord->setYCor(y);
    }

    double getMaxHeight()
    {
        return maxHeight;
    }

    std::shared_ptr<double> getScore() const
    {
        return score;
    }

    AdapterScreenResolution getScreenResolution() const
    {
        return screenResolution;
    }

    std::shared_ptr<bool> IsGameOver() const
    {
        return isGameOver;
    }

private:
    std::shared_ptr<CoordSystemR2> coord;
    double maxHeight;
    std::shared_ptr<double> score;
    AdapterScreenResolution screenResolution;
    std::shared_ptr<bool> isGameOver;
};
