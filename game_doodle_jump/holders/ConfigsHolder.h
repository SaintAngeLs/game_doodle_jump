#pragma once
#include "../conf/DoodleConfiguration.h"
#include "../conf/ConfigurationLoader.h"

namespace config
{
    class ConfigurationsHolder
    {
    public:
        ConfigurationsHolder(ConfigurationLoader configLoader) : configLoader(configLoader) {}


        BackgroundConfiguration getBackgroundConfig()
        {
            if (backgroundConfig == nullptr)
            {
                backgroundConfig = std::make_unique<BackgroundConfiguration>(configLoader.loadBackgroundConfig());
            }
            return *backgroundConfig;
        }


        DoodleConfiguration getDoodleConfig()
        {
            if (doodleConfig == nullptr)
            {
                doodleConfig = std::make_unique<DoodleConfiguration>(configLoader.loadDoodleConfig());
            }
            return *doodleConfig;
        }

        PlatformConfiguration getPlatformConfig()
        {
            if (platformConfig == nullptr)
            {
                platformConfig = std::make_unique<PlatformConfiguration>(configLoader.loadPlatformConfig());
            }
            return *platformConfig;
        }

        EnemyConfiguration getEnemyConfig()
        {
            if (enemyConfig == nullptr)
            {
                enemyConfig = std::make_unique<EnemyConfiguration>(configLoader.loadEnemyConfig());
            }
            return *enemyConfig;
        }

        AbilityConfiguration getAbilityConfig()
        {
            if (abilityConfig == nullptr)
            {
                abilityConfig = std::make_unique<AbilityConfiguration>(configLoader.loadAbilityConfig());
            }
            return *abilityConfig;
        }

        ProjectileConfiguration getProjectileConfig()
        {
            if (projectileConfig == nullptr)
            {
                projectileConfig = std::make_unique<ProjectileConfiguration>(configLoader.loadProjectileConfig());
            }
            return *projectileConfig;
        }

    private:
        ConfigurationLoader configLoader;
        std::unique_ptr<BackgroundConfiguration> backgroundConfig;
        std::unique_ptr<DoodleConfiguration> doodleConfig;
        std::unique_ptr<PlatformConfiguration> platformConfig;
        std::unique_ptr<EnemyConfiguration> enemyConfig;
        std::unique_ptr<AbilityConfiguration> abilityConfig;
        std::unique_ptr<ProjectileConfiguration> projectileConfig;
    };
}
