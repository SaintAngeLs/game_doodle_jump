#pragma once
#include <memory>
#include <utility>

class PickUpAbilityNode
{
public:
    PickUpAbilityNode(std::shared_ptr<CoordSystemR2> doodleCoord, std::shared_ptr<CoordSystemR2> abilityCoord, SizeR2 doodleSize,
        SizeR2 abilitySize, std::shared_ptr<std::vector<std::string>> removingUUID, std::string abilityUUID,
        std::shared_ptr<std::vector<EnemyObject>> enemies, std::shared_ptr<CoordSystemR2> mouseCoord,
        std::shared_ptr<FRMouseButton> pressedMouseButton)
        : doodleCoord(std::move(doodleCoord)),
          abilityCoord(std::move(abilityCoord)),
          doodleSize(std::move(doodleSize)),
          abilitySize(std::move(abilitySize)),
          removingUUID(std::move(removingUUID)),
          abilityUUID(std::move(abilityUUID)),
          enemies(std::move(enemies)),
          mouseCoord(std::move(mouseCoord)),
          pressedMouseButton(std::move(pressedMouseButton)){}

    std::shared_ptr<CoordSystemR2> getDoodleCoord()
    {
        return doodleCoord;
    }

    std::shared_ptr<CoordSystemR2> getAbilityCoord()
    {
        return abilityCoord;
    }

    SizeR2 getDoodleSize()
    {
        return doodleSize;
    }

    SizeR2 getAbilitySize()
    {
        return abilitySize;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID()
    {
        return removingUUID;
    }

    std::string getAbilityUUID()
    {
        return abilityUUID;
    }

    std::shared_ptr<std::vector<EnemyObject>> getEnemies()
    {
        return enemies;
    }

    std::shared_ptr<CoordSystemR2> getMouseCoord()
    {
        return mouseCoord;
    }

    std::shared_ptr<FRMouseButton> getPressedMouseButton()
    {
        return pressedMouseButton;
    }

private:
    std::shared_ptr<CoordSystemR2> doodleCoord;
    std::shared_ptr<CoordSystemR2> abilityCoord;
    SizeR2 doodleSize;
    SizeR2 abilitySize;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::string abilityUUID;
    std::shared_ptr<std::vector<EnemyObject>> enemies;
    std::shared_ptr<CoordSystemR2> mouseCoord;
    std::shared_ptr<FRMouseButton> pressedMouseButton;
};
