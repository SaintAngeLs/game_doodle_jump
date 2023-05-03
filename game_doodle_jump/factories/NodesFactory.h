#pragma once

#include <memory>

#include "Framework.h"
#include "../components/CoordSystemR2.h"
#include "../components/SizeR2.h"
#include "../nodes/AbilityGeneratorNode.h"
#include "../nodes/PlatformGeneratorNode.h"
#include "../nodes/MouseTrackNode.h"
#include "../nodes/PressedKeyTrackNode.h"
#include "../nodes/ConstantXMoveNode.h"
#include "../nodes/BeyondBondaryMovingNode.h"
#include "../nodes/GravitationNode.h"
#include "../nodes/HeightMonitoringNode.h"
#include "../nodes/EnemyGeneratorNode.h"
#include "../nodes/GameOverCheckerNode.h"
#include "../nodes/JumpOnEnemyNode.h"
#include "../nodes/PressedMouseButtonTrackNode.h"
#include "../nodes/ProjectileGeneratorNode.h"
#include "../nodes/ProjectileMovementNode.h"
#include "../nodes/ShootingEnemyNode.h"
#include "../nodes/AbilityNode.h"
#include "../nodes/PickUpAbilityNode.h"
#include "../entities/EnemyObject.h"
#include "../nodes/PlatformMovingNode.h"
#include "../nodes/JumpNode.h"

class NodesFactory
{
public:
    static RenderNode makeRenderNode(Sprite* sprite, std::shared_ptr<CoordSystemR2> coord, SizeR2 size)
    {
        return { std::move(sprite), std::move(coord), size };
    }

    static RenderNode makeBackgroundRenderNode(Sprite* sprite, std::shared_ptr<CoordSystemR2> coord, SizeR2 size)
    {
        return { std::move(sprite), std::move(coord), size };
    }

    static MouseTrackNode makeMouseTrackNode(std::shared_ptr<CoordSystemR2> coord)
    {
        return {coord};
    }

    static PressedKeyTrackNode makePressedKeyNode(std::shared_ptr<FRKey> key)
    {
        return {key};
    }

    static PressedMouseButtonTrackNode makePressedMouseButtonTrackNode(std::shared_ptr<FRMouseButton> mouseButton)
    {
        return {mouseButton};
    }

    static PlatformGeneratorNode makePlatformGeneratorNode(Sprite* sprite, SizeR2 platformSize, SizeR2 doodleSize,
        AdapterScreenResolution screenResolution, std::shared_ptr<std::vector<PlatformObject>> platforms, const int platformAmount,
        std::shared_ptr<double> gravitationSpeed,
        std::shared_ptr<RandomValueGenerator> platformXCordRandomValueGenerator,
        std::shared_ptr<RandomValueGenerator> platformYCordRandomValueGenerator,
        std::shared_ptr<CoordSystemR2> doodleCoord, double jumpForce, std::shared_ptr<double> score, std::shared_ptr<double> lastScore,
        std::shared_ptr<int> jumpCounter)
    {
        return {
            std::move(sprite), platformSize, doodleSize, screenResolution, std::move(platforms), platformAmount,
            std::move(gravitationSpeed), std::move(platformXCordRandomValueGenerator),
            std::move(platformYCordRandomValueGenerator),std::move(doodleCoord), jumpForce, std::move(score),
            std::move(lastScore), std::move(jumpCounter)
        };
    }

    static ConstantXMoveNode makeConstantXMoveNode(std::shared_ptr<CoordSystemR2> coord, std::shared_ptr<int> moveDistance,
    std::shared_ptr<FRKey> pressedKey)
    {
        return {std::move(coord), std::move(moveDistance), std::move(pressedKey)};
    }

    static BeyondBondaryMovingNode makeBeyondBondaryMovingNode(std::shared_ptr<CoordSystemR2> doodleCoord, AdapterScreenResolution screenResolution, SizeR2 doodleSize)
    {
        return {std::move(doodleCoord), screenResolution, doodleSize};
    }

    static GravitationNode makeGravitationNode(std::shared_ptr<CoordSystemR2> subjectCoord, std::shared_ptr<double> gravitationSpeed)
    {
        return {std::move(subjectCoord), std::move(gravitationSpeed)};
    }

    static HeightMonitoringNode makeHeightMonitoringNode(std::shared_ptr<CoordSystemR2> coord, double maxHeight,
        std::shared_ptr<double> score, AdapterScreenResolution screenResolution, std::shared_ptr<bool> isGameOver)
    {
        return {std::move(coord), maxHeight, std::move(score), screenResolution, std::move(isGameOver)};
    }

    static PlatformMovingNode makePlatformMovingNode(std::shared_ptr<double> gravitationSpeed,
    AdapterScreenResolution screenResolution, SizeR2 size, std::shared_ptr<CoordSystemR2> coord,
    std::shared_ptr<RandomValueGenerator> platformXCordRandomValueGenerator,
    std::shared_ptr<RandomValueGenerator> platformYCordRandomValueGenerator)
    {
        return {std::move(gravitationSpeed), screenResolution, size, std::move(coord), std::move(platformXCordRandomValueGenerator),
            std::move(platformYCordRandomValueGenerator)
        };
    }

    static JumpNode makeJumpNode(std::shared_ptr<CoordSystemR2> doodleCoord, std::shared_ptr<CoordSystemR2> platformCoord,
        std::shared_ptr<double> gravitationSpeed, SizeR2 doodleSize, SizeR2 platformSize, double jumpForce,
         std::shared_ptr<double> score, std::shared_ptr<double> lastScore, std::shared_ptr<int> jumpCounter)
    {
        return {std::move(doodleCoord), std::move(platformCoord), std::move(gravitationSpeed), doodleSize, platformSize,
            jumpForce, std::move(score), std::move(lastScore), std::move(jumpCounter)
        };
    }

    static EnemyGeneratorNode makeEnemyGeneratorNode(Sprite* const sprite, const double probability, SizeR2 enemySize,
        std::shared_ptr<RandomValueGenerator> randomValueGenerator, std::shared_ptr<std::vector<EnemyObject>> enemies,
        std::shared_ptr<double> gravitationSpeed, AdapterScreenResolution screenResolution,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::shared_ptr<CoordSystemR2> doodleCoord, SizeR2 doodleSize,
        std::shared_ptr<bool> isGameOver)
    {
        return {std::move(sprite), probability, enemySize, std::move(randomValueGenerator), std::move(enemies),
            std::move(gravitationSpeed), screenResolution, std::move(removingUUID), std::move(doodleCoord), doodleSize,
            std::move(isGameOver)
        };
    }

    static AbilityGeneratorNode makeAbilityGeneratorNode(Sprite* sprite, SizeR2 size, std::shared_ptr<std::vector<PlatformObject>> platforms,
        std::shared_ptr<double> gravitationSpeed, AdapterScreenResolution screenResolution,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::shared_ptr<int> jumpCounter, int spawningJumpAmount,
        std::shared_ptr<CoordSystemR2> doodleCoord, SizeR2 doodleSize,
        std::shared_ptr<std::vector<EnemyObject>> enemies, std::shared_ptr<CoordSystemR2> mouseCoord,
        std::shared_ptr<FRMouseButton> mouseButton)
    {
        return {std::move(sprite), size, std::move(platforms), std::move(gravitationSpeed), screenResolution, std::move(removingUUID),
            std::move(jumpCounter), spawningJumpAmount, doodleCoord, doodleSize, enemies, mouseCoord, mouseButton};
    }

    static EnemyMovingNode makeEnemyMovingNode(std::shared_ptr<double> gravitationSpeed, AdapterScreenResolution screenResolution,
        std::shared_ptr<CoordSystemR2> coord, std::shared_ptr<std::vector<std::string>> removingUUID, std::string UUID)
    {
        return {std::move(gravitationSpeed), screenResolution, std::move(coord), std::move(removingUUID), std::move(UUID)
        };
    }

    static ProjectileGeneratorNode makeProjectileGeneratorNode(SizeR2 size, Sprite* sprite, std::shared_ptr<CoordSystemR2> mouseCoord,
        std::shared_ptr<CoordSystemR2> doodleCoord, std::shared_ptr<double> moveDistance,
        std::shared_ptr<FRMouseButton> pressedMouseButton, SizeR2 doodleSize, std::shared_ptr<std::vector<EnemyObject>> enemies,
        std::shared_ptr<std::vector<std::string>> removingUUID)
    {
        return {size, sprite, std::move(mouseCoord), std::move(doodleCoord), std::move(moveDistance),
            std::move(pressedMouseButton), doodleSize, std::move(enemies), std::move(removingUUID)
        };
    }

    static ProjectileMovementNode makeProjectileMovementNode(std::shared_ptr<CoordSystemR2> coord, std::shared_ptr<Speed> speed)
    {
        return {std::move(coord), std::move(speed)};
    }

    static GameOverCheckerNode makeGameOverCheckerNode(std::shared_ptr<bool> isGameOver)
    {
        return {std::move(isGameOver)};
    }

    static JumpOnEnemyNode makeJumpOnEnemyNode(std::shared_ptr<CoordSystemR2> doodleCoord, std::shared_ptr<CoordSystemR2> enemyCoord,
        std::shared_ptr<double> gravitationSpeed, SizeR2 doodleSize, SizeR2 enemySize, std::shared_ptr<bool> isGameOver,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::string enemyUUID)
    {
        return {std::move(doodleCoord), std::move(enemyCoord), std::move(gravitationSpeed), doodleSize, enemySize,
            std::move(isGameOver), std::move(removingUUID), std::move(enemyUUID)
        };
    }

    static ShootingEnemyNode makeShootingEnemyNode(std::shared_ptr<CoordSystemR2> projectileCoord, SizeR2 projectileSize,
        std::shared_ptr<std::vector<EnemyObject>> enemies, std::shared_ptr<std::vector<std::string>> removingUUID, std::string projectileUUID)
    {
        return {std::move(projectileCoord), projectileSize, std::move(enemies), std::move(removingUUID), std::move(projectileUUID)};
    }

    static AbilityNode makeAbilityNode(std::shared_ptr<std::vector<EnemyObject>> enemies, std::shared_ptr<CoordSystemR2> mouseCoord,
        std::shared_ptr<FRMouseButton> pressedMouseButton, std::shared_ptr<std::vector<std::string>> removingUUID,
        std::string enemyUUID)
    {
        return {std::move(enemies), std::move(mouseCoord), std::move(pressedMouseButton), std::move(removingUUID),
            std::move(enemyUUID)};
    }

    static PickUpAbilityNode makePickUpAbilityNode(std::shared_ptr<CoordSystemR2> doodleCoord, std::shared_ptr<CoordSystemR2> abilityCoord, SizeR2 doodleSize,
        SizeR2 abilitySize, std::shared_ptr<std::vector<std::string>> removingUUID, std::string abilityUUID,
        std::shared_ptr<std::vector<EnemyObject>> enemies, std::shared_ptr<CoordSystemR2> mouseCoord,
        std::shared_ptr<FRMouseButton> pressedMouseButton)
    {
        return {std::move(doodleCoord), std::move(abilityCoord), doodleSize, abilitySize, std::move(removingUUID),
            std::move(abilityUUID), std::move(enemies), std::move(mouseCoord), std::move(pressedMouseButton)
        };
    }
};
