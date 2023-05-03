#pragma once
#include "BackgroundConfiguration.h"
#include "AbilityConfiguration.h"
#include "EnemyConfiguration.h"
#include "PlatformConfiguration.h"
#include "ProjectileConfiguration.h"
#include "../utilities/AdapterScreenResolution.h"

namespace config
{
    class ConfigResolutionAdjuster
    {
    public:
        ConfigResolutionAdjuster(AdapterScreenResolution resolution) : resolution(resolution) {}

        BackgroundConfiguration getAdjustedBockgroundConfig(BackgroundConfiguration&& config)
        {
            return BackgroundConfiguration(config.spriteFilePath, adjustByWidthRes(config.width), adjustByHeightRes(config.height));
        }

        DoodleConfiguration getAdjustedDoodleConfig(DoodleConfiguration&& config)
        {
            return DoodleConfiguration( config.spriteFilePath,
                adjustByWidthRes(config.coordinateX), adjustByHeightRes(config.coordinateY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
            adjustByWidthRes(config.moveDistance), adjustByHeightRes(config.gravitation),
            adjustByHeightRes(config.maxHeight), adjustByHeightRes(config.jumpForce));
        }

        PlatformConfiguration getAdjustedPlatformConfig(PlatformConfiguration&& config)
        {
            return PlatformConfiguration( config.spriteFilePath,
                adjustByWidthRes(config.coordinateX), adjustByHeightRes(config.coordinateY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                config.platformAmount);
        }

        EnemyConfiguration getAdjustedEnemyConfig(EnemyConfiguration&& config)
        {
            return EnemyConfiguration( config.spriteFilePath,
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                config.probability);
        }

        AbilityConfiguration getAdjustedAbilityConfig(AbilityConfiguration&& config)
        {
            return AbilityConfiguration( config.spriteFilePath,
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                config.spawningJumpAmount);
        }

        ProjectileConfiguration getAdjustedProjectileConfig(ProjectileConfiguration&& config)
        {
            return ProjectileConfiguration( config.spriteFilePath,
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                adjustByHeightRes(config.moveDistance));
        }

    private:
        AdapterScreenResolution resolution;

        template<class T>
        T adjustByWidthRes(T& percentFromResolution)
        {
            return percentFromResolution * resolution.width / 100.0;
        }

        template<class T>
        int adjustByHeightRes(T& percentFromResolution)
        {
             return percentFromResolution * resolution.height / 100.0;
        }
    };
}
