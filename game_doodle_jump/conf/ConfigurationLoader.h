#pragma once
#include "BackgroundConfiguration.h"
#include "DoodleConfiguration.h"
#include "ConfigDeserializer.h"
#include "ConfigResolutionAdjuster.h"
#include "PlatformConfiguration.h"

namespace config
{
    class ConfigurationLoader
    {
    public:
        
        inline static const char* BACKGROUND_CONFIG_FILE_PATH = "resources/conf/BackgroundConfiguration.json";
        inline static const char* DOODLE_CONFIG_FILE_PATH = "resources/conf/DoodleConfiguration.json";
        inline static const char* PLATFORM_CONFIG_FILE_PATH = "resources/conf/PlatformConfiguration.json";
        inline static const char* ENEMY_CONFIG_FILE_PATH = "resources/conf/EnemyConfiguration.json";
        inline static const char* ABILITY_CONFIG_FILE_PATH = "resources/conf/AbilityConfiguration.json";
        inline static const char* PROJECTILE_CONFIG_FILE_PATH = "resources/conf/ProjectileConfiguration.json";

        ConfigurationLoader(ConfigResolutionAdjuster adjuster) : resolutionAdjuster(adjuster) {}

        BackgroundConfiguration loadBackgroundConfig()
        {
            return resolutionAdjuster.getAdjustedBockgroundConfig(ConfigDeserializer::deserializeConfig<BackgroundConfiguration>(BACKGROUND_CONFIG_FILE_PATH));
        }

        DoodleConfiguration loadDoodleConfig()
        {
            return resolutionAdjuster.getAdjustedDoodleConfig(
                ConfigDeserializer::deserializeConfig<DoodleConfiguration>(DOODLE_CONFIG_FILE_PATH));
        }

        PlatformConfiguration loadPlatformConfig()
        {
            return resolutionAdjuster.getAdjustedPlatformConfig(
                ConfigDeserializer::deserializeConfig<PlatformConfiguration>(PLATFORM_CONFIG_FILE_PATH));
        }

        EnemyConfiguration loadEnemyConfig()
        {
            return resolutionAdjuster.getAdjustedEnemyConfig(
                ConfigDeserializer::deserializeConfig<EnemyConfiguration>(ENEMY_CONFIG_FILE_PATH));
        }

        AbilityConfiguration loadAbilityConfig()
        {
            return resolutionAdjuster.getAdjustedAbilityConfig(
                ConfigDeserializer::deserializeConfig<AbilityConfiguration>(ABILITY_CONFIG_FILE_PATH));
        }

        ProjectileConfiguration loadProjectileConfig()
        {
            return resolutionAdjuster.getAdjustedProjectileConfig(
                ConfigDeserializer::deserializeConfig<ProjectileConfiguration>(PROJECTILE_CONFIG_FILE_PATH));
        }

    private:
        ConfigResolutionAdjuster resolutionAdjuster;
    };
}
