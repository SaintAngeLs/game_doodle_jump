#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "../components/CoordSystemR2.h"
#include "../utilities/AdapterScreenResolution.h""

class EnemyMovingNode
{
public:
    EnemyMovingNode(std::shared_ptr<double> gravitationSpeed, AdapterScreenResolution screenResolution,
        std::shared_ptr<CoordSystemR2> coord, std::shared_ptr<std::vector<std::string>> removingUUID, std::string UUID)
        : gravitationSpeed(std::move(gravitationSpeed)),
          screenResolution(screenResolution),
          coord(std::move(coord)),
          removingUUID(std::move(removingUUID)),
          UUID(std::move(UUID)){}

    std::shared_ptr<double> getGravitationSpeed() const
    {
        return gravitationSpeed;
    }

    AdapterScreenResolution getScreenResolution() const
    {
        return screenResolution;
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

    std::shared_ptr<std::vector<std::string>> getRemovingUUID() const
    {
        return removingUUID;
    }

    std::string getUUID() const
    {
        return UUID;
    }

private:
    std::shared_ptr<double> gravitationSpeed;
    AdapterScreenResolution screenResolution;
    std::shared_ptr<CoordSystemR2> coord;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::string UUID;
};
