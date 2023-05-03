#pragma once
#include "SharedComponentsFactory.h"
#include "../utilities/AdapterScreenResolution.h"
#include "../conf/ConfigurationLoader.h"
#include "../holders/ConfigsHolder.h"
#include "../holders/SharedComponentHolder.h"

using namespace config;

class HoldersComponentFactory
{
public:
    static ConfigurationsHolder createConfigHolder(AdapterScreenResolution resolution)
    {
        return { ConfigurationLoader(ConfigResolutionAdjuster(resolution))};
    }

    static SharedComponentsHolder createSharedComponentHolder(std::shared_ptr<ConfigurationsHolder> configsHolder, AdapterScreenResolution screenResolution)
    {
        return
        {
            SharedComponentsFactory::createBackgroundCord(configsHolder->getBackgroundConfig()),
            SharedComponentsFactory::createDoodleCoord(configsHolder->getDoodleConfig()),
            SharedComponentsFactory::createMouseCoord(),
            SharedComponentsFactory::createPressedKey(),
            SharedComponentsFactory::createPressedMouseButton(),
            screenResolution,
            SharedComponentsFactory::createGravitationSpeed(configsHolder->getDoodleConfig().gravitation),
            SharedComponentsFactory::createPlatformsVector(),
            SharedComponentsFactory::createRandomValueGenerator(0,screenResolution.width - configsHolder->getPlatformConfig().width),
            SharedComponentsFactory::createRandomValueGenerator(screenResolution.height * 0.2,screenResolution.height),
            SharedComponentsFactory::createRandomValueGenerator(0, 100),
            SharedComponentsFactory::createRemovingUUIDList(),
            SharedComponentsFactory::createScore(),
            SharedComponentsFactory::createLastScore(),
            SharedComponentsFactory::createJumpCounter(),
            SharedComponentsFactory::createGameOver(),
            SharedComponentsFactory::enemies()
        };
    }
};