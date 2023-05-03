#pragma once

#include <memory>
#include <utility>
#include <vector>
#include "../components/SizeR2.h"
#include "../entities/EnemyObject.h"
#include "../entities/PlatformObject.h"

class AbilityGeneratorNode
{
public:
    AbilityGeneratorNode(Sprite* sprite, SizeR2 size, std::shared_ptr<std::vector<PlatformObject>> platforms,
        std::shared_ptr<double> gravitationSpeed, AdapterScreenResolution screenResolution,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::shared_ptr<int> jumpCounter,
        const int spawningJumpAmount, std::shared_ptr<CoordSystemR2> doodleCoord, SizeR2 doodleSize,
        std::shared_ptr<std::vector<EnemyObject>> enemies, std::shared_ptr<CoordSystemR2> mouseCoord,
        std::shared_ptr<FRMouseButton> mouseButton)
        : sprite(sprite),
          size(std::move(size)),
          platforms(std::move(platforms)),
          gravitationSpeed(std::move(gravitationSpeed)),
          screenResolution(std::move(screenResolution)),
          removingUUID(std::move(removingUUID)),
          jumpCounter(std::move(jumpCounter)),
          spawningJumpAmount(spawningJumpAmount),
          doodleCoord(std::move(doodleCoord)),
          doodleSize(std::move(doodleSize)),
          enemies(std::move(enemies)),
          mouseCoord(std::move(mouseCoord)),
          mouseButton(std::move(mouseButton)){}

    Sprite* getSprite()
    {
        return sprite;
    }

    SizeR2 getSize()
    {
        return size;
    }

    std::shared_ptr<std::vector<PlatformObject>> getPlatforms()
    {
        return platforms;
    }

    std::shared_ptr<double> getGravitationSpeed()
    {
        return gravitationSpeed;
    }

    AdapterScreenResolution getScreenResolution()
    {
        return screenResolution;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID()
    {
        return removingUUID;
    }

    std::shared_ptr<int> getJumpCounter()
    {
        return jumpCounter;
    }

    int getSpawningJumpAmount()
    {
        return spawningJumpAmount;
    }

    std::shared_ptr<CoordSystemR2> getDoodleCoord()
    {
        return doodleCoord;
    }

    SizeR2 getDoodleSize()
    {
        return doodleSize;
    }

    std::shared_ptr<std::vector<EnemyObject>> getEnemies()
    {
        return enemies;
    }

    std::shared_ptr<CoordSystemR2> getMouseCoord()
    {
        return mouseCoord;
    }

    std::shared_ptr<FRMouseButton> getMouseButton()
    {
        return mouseButton;
    }

private:
    Sprite* sprite;
    SizeR2 size;
    std::shared_ptr<std::vector<PlatformObject>> platforms;
    std::shared_ptr<double> gravitationSpeed;
    AdapterScreenResolution screenResolution;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::shared_ptr<int> jumpCounter;
    int spawningJumpAmount;
    std::shared_ptr<CoordSystemR2> doodleCoord;
    SizeR2 doodleSize;
    std::shared_ptr<std::vector<EnemyObject>> enemies;
    std::shared_ptr<CoordSystemR2> mouseCoord;
    std::shared_ptr<FRMouseButton> mouseButton;
    
};
