#include "../entities/UserInputTracker.h"
#include "../entities/DoodleObject.h"
#include "../entities/ObjectEntitiesGenerator.h"
#include "../entities/BeyondBondaryMovingEntity.h"
#include "../entities/EnemyObject.h"
#include "../entities/GameOverChecker.h"
#include "../entities/ProjectileObject.h"
#include "../entities/PlatformObject.h"
#include "../nodes/PressedMouseButtonTrackNode.h"
#include "../nodes/ConstantXMoveNode.h"
#include "../nodes/HeightMonitoringNode.h"
#include "../nodes/GravitationNode.h"
#include "../nodes/PlatformGeneratorNode.h"
#include "../nodes/EnemyGeneratorNode.h"
#include "../nodes/AbilityGeneratorNode.h"
#include "../nodes/ProjectileMovementNode.h"
#include "../nodes/ShootingEnemyNode.h"
#include "../entities/BackgroundObject.h"

// EntitiesFabric class is responsible for creating various game entities.
class EntitiesComponentFactory
{
public:
    // Function to create a UserInputTracker entity.
    static UserInputTracker makeUserInputTrackerEntity(std::string uuid, MouseTrackNode mouseTrackNode,
        PressedKeyTrackNode pressedKeyTrackNode, PressedMouseButtonTrackNode pressedMouseButtonTrackNode)
    {
        return { std::move(uuid), std::move(mouseTrackNode), std::move(pressedKeyTrackNode), pressedMouseButtonTrackNode };
    }

    // Function to creat the BackgroundObject entity.
    static BackgroundObject makeBackgroundEntity(std::string uuid, RenderNode renderNode)
    {
        return { std::move(uuid), std::move(renderNode)};
    }

    // Function to create a DoodleObject entity.
    static DoodleObject makeDoodleEntity(std::string uuid, RenderNode renderNode, ConstantXMoveNode constantXMoveNode,
        GravitationNode gravitationNode, HeightMonitoringNode heightMonitoringNode)
    {
        return { std::move(uuid), std::move(renderNode), constantXMoveNode, gravitationNode, heightMonitoringNode };
    }

    // Function to create a PlatformObject entity.
    static PlatformObject makePlatformEntity(std::string uuid, RenderNode renderNode, PlatformMovingNode platformMovingNode,
        JumpNode jumpNode)
    {
        return { std::move(uuid), std::move(renderNode), std::move(platformMovingNode), jumpNode };
    }

    // Function to create an ObjectEntitiesGenerator entity.
    static ObjectEntitiesGenerator makeEntitiesGenerator(std::string uuid, PlatformGeneratorNode platformGeneratorNode,
        EnemyGeneratorNode enemyGeneratorNode, AbilityGeneratorNode abilityGeneratorNode,
        ProjectileGeneratorNode projectileGeneratorNode)
    {
        return { std::move(uuid), std::move(platformGeneratorNode) , std::move(enemyGeneratorNode), std::move(abilityGeneratorNode),
            std::move(projectileGeneratorNode)
        };
    }

    // Function to create a BeyondBondaryMovingEntity entity.
    static BeyondBondaryMovingEntity makeBeyondBondaryMovingEntity(std::string uuid, BeyondBondaryMovingNode beyondBondaryMovingNode)
    {
        return { std::move(uuid), std::move(beyondBondaryMovingNode) };
    }

    // Function to create an EnemyObject entity.
    static EnemyObject makeEnemyEntity(std::string uuid, RenderNode renderNode, EnemyMovingNode enemyMovingNode,
        JumpOnEnemyNode jumpOnEnemyNode)
    {
        return { std::move(uuid), std::move(renderNode), std::move(enemyMovingNode), std::move(jumpOnEnemyNode) };
    }

    // Function to create a ProjectileObject entity.
    static ProjectileObject makeProjectileEntity(std::string uuid, RenderNode renderNode,
        ProjectileMovementNode projectileMovementNode, ShootingEnemyNode shootingEnemyNode)
    {
        return { std::move(uuid), std::move(renderNode), std::move(projectileMovementNode), std::move(shootingEnemyNode) };
    }

    // Function to create a GameOverChecker entity.
    static GameOverChecker makeGameOverChecker(std::string uuid, GameOverCheckerNode gameOverCheckerNode)
    {
        return { std::move(uuid), std::move(gameOverCheckerNode) };
    }
};
