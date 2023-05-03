#pragma once

#include "../entities/DoodleObject.h"
#include "../entities/BackgroundObject.h"
#include "../entities/UserInputTracker.h"
#include "../entities/ObjectEntitiesGenerator.h"
#include "../entities/BeyondBondaryMovingEntity.h"
#include "../entities/GameOverChecker.h"

class EntityManagerComponent
{
public:
    EntityManagerComponent(BackgroundObject background, DoodleObject doodle, UserInputTracker tracker, ObjectEntitiesGenerator entitiesGenerator,
        BeyondBondaryMovingEntity beyondBondaryMovingEntity, GameOverChecker gameOverChecker)
        : background(std::move(background)),
        doodle(std::move(doodle)),
        userInputTracker(std::move(tracker)),
        entitiesGenerator(std::move(entitiesGenerator)),
        beyondBondaryMovingEntity(std::move(beyondBondaryMovingEntity)),
        gameOverChecker(std::move(gameOverChecker)) {}


    BackgroundObject getBackground()
    {
        return background;
    }
    DoodleObject getDoodle()
    {
        return doodle;
    }

    UserInputTracker getUserInputTracker()
    {
        return userInputTracker;
    }

    ObjectEntitiesGenerator getPlatformGenerator()
    {
        return entitiesGenerator;
    }

    BeyondBondaryMovingEntity getBeyondBondaryMovingEntity()
    {
        return beyondBondaryMovingEntity;
    }

    ObjectEntitiesGenerator getEntitiesGenerator()
    {
        return entitiesGenerator;
    }

    GameOverChecker getGameOverChecker() const
    {
        return gameOverChecker;
    }

private:
    BackgroundObject  background;
    DoodleObject doodle;
    UserInputTracker userInputTracker;
    ObjectEntitiesGenerator entitiesGenerator;
    BeyondBondaryMovingEntity beyondBondaryMovingEntity;
    GameOverChecker gameOverChecker;
};
