#pragma once

#include <memory>
#include <memory>

#include "NodesFactory.h"
#include "EntitiesComponentFactory.h"
#include "Framework.h"
#include"../components/SizeR2.h"
#include "../managers/SystemManagerComponent.h"
#include "../systems/RenderSystem.h"
#include "../systems/MouseTrackSystem.h"
#include "../systems/PressedKeyTrackSystem.h"
#include "../nodes/PressedKeyTrackNode.h"
#include "../managers/EntityManagerComponent.h"
#include "../holders/SharedComponentHolder.h"
#include "../holders/ConfigsHolder.h"
#include "../managers/RemovingManagerComponent.h"
#include "../systems/PressedMouseButtonTrackSystem.h"
#include "../utilities/UUID.h"

class ManagersComponentFactory
{
public:
    static std::shared_ptr<EntityManagerComponent> makeEntityManagerComponent(std::shared_ptr<config::ConfigurationsHolder> configsHolder,
        std::shared_ptr<SharedComponentsHolder> sharedComponentHolder)
    {


        auto backgroundConfig = configsHolder->getBackgroundConfig();
        auto doodleConfig = configsHolder->getDoodleConfig();
        auto platformConfig = configsHolder->getPlatformConfig();
        auto enemyConfig = configsHolder->getEnemyConfig();
        auto abilityConfig = configsHolder->getAbilityConfig();
        auto projectileConfig = configsHolder->getProjectileConfig();


        auto backgroundSize = SizeR2(backgroundConfig.width, backgroundConfig.height);
        auto doodleSize = SizeR2(doodleConfig.width, doodleConfig.height);
        auto platformSize = SizeR2(platformConfig.width, platformConfig.height);
        auto enemySize = SizeR2(enemyConfig.width, enemyConfig.height);
        auto abilitySize = SizeR2(abilityConfig.width, abilityConfig.height);
        auto projectileSize = SizeR2(projectileConfig.width, projectileConfig.height);
        
        Sprite* backgorundSprite(createSprite(backgroundConfig.spriteFilePath.c_str()));
        Sprite* doodleSprite(createSprite(doodleConfig.spriteFilePath.c_str()));
        
        Sprite* platformSprite(createSprite(platformConfig.spriteFilePath.c_str()));
        Sprite* enemySprite(createSprite(enemyConfig.spriteFilePath.c_str()));
        Sprite* abilitySprite(createSprite(abilityConfig.spriteFilePath.c_str()));
        Sprite* projectileSprite(createSprite(projectileConfig.spriteFilePath.c_str()));


        auto backgroundRenderNode = NodesFactory::makeBackgroundRenderNode(backgorundSprite, sharedComponentHolder->getBackgroundCoord(), backgroundSize);
        auto doodleRenderNode = NodesFactory::makeRenderNode(doodleSprite, sharedComponentHolder->getDoodleCoord(), doodleSize);
        auto doodleConstantXMoveNode = NodesFactory::makeConstantXMoveNode(
            sharedComponentHolder->getDoodleCoord(), std::make_shared<int>(doodleConfig.moveDistance), sharedComponentHolder->getPressedKey());
        auto doodleGraviatationNode = NodesFactory::makeGravitationNode(sharedComponentHolder->getDoodleCoord(), sharedComponentHolder->getGravitation());
        auto doodleHeightMonitoringNode = NodesFactory::makeHeightMonitoringNode(
        sharedComponentHolder->getDoodleCoord(), doodleConfig.maxHeight, sharedComponentHolder->getScore(), sharedComponentHolder->getScreenResolution(), sharedComponentHolder->IsGameOver());

        auto beyondBondaryMovingNode = NodesFactory::makeBeyondBondaryMovingNode(sharedComponentHolder->getDoodleCoord(), sharedComponentHolder->getScreenResolution(), doodleSize);
        
        auto mouseTrackNode = NodesFactory::makeMouseTrackNode(sharedComponentHolder->getMouseCoord());
        auto pressedKeyNode = NodesFactory::makePressedKeyNode(sharedComponentHolder->getPressedKey());
        auto pressedMouseButtonTrackNode = NodesFactory::makePressedMouseButtonTrackNode(sharedComponentHolder->getPressedMouseButton());
        
        auto platformGeneratorNode = NodesFactory::makePlatformGeneratorNode(platformSprite, platformSize, doodleSize,
            sharedComponentHolder->getScreenResolution(), sharedComponentHolder->getPlatforms(), platformConfig.platformAmount,
            sharedComponentHolder->getGravitation(), sharedComponentHolder->getPlatformXCordRandomValueGenerator(),
            sharedComponentHolder->getPlatformYCordRandomValueGenerator(), sharedComponentHolder->getDoodleCoord(), doodleConfig.jumpForce,
            sharedComponentHolder->getScore(), sharedComponentHolder->getLastScore(), sharedComponentHolder->getJumpCounter());
        auto enemyGeneratorNode = NodesFactory::makeEnemyGeneratorNode(enemySprite, enemyConfig.probability, enemySize,
            sharedComponentHolder->getEnemyRandomValueGenerator(), sharedComponentHolder->getEnemies(),
            sharedComponentHolder->getGravitation(), sharedComponentHolder->getScreenResolution(), sharedComponentHolder->getRemovingUUID(),
            sharedComponentHolder->getDoodleCoord(), doodleSize, sharedComponentHolder->IsGameOver());
        auto abilityGeneratorNode = NodesFactory::makeAbilityGeneratorNode(abilitySprite, abilitySize, sharedComponentHolder->getPlatforms(),
            sharedComponentHolder->getGravitation(), sharedComponentHolder->getScreenResolution(), sharedComponentHolder->getRemovingUUID(),
            sharedComponentHolder->getJumpCounter(), abilityConfig.spawningJumpAmount, sharedComponentHolder->getDoodleCoord(),
            doodleSize, sharedComponentHolder->getEnemies(), sharedComponentHolder->getMouseCoord(), sharedComponentHolder->getPressedMouseButton());
        auto projectileGeneratorNode = NodesFactory::makeProjectileGeneratorNode(projectileSize, projectileSprite,
            sharedComponentHolder->getMouseCoord(), sharedComponentHolder->getDoodleCoord(),
            std::make_shared<double>(projectileConfig.moveDistance),
            sharedComponentHolder->getPressedMouseButton(), doodleSize, sharedComponentHolder->getEnemies(), sharedComponentHolder->getRemovingUUID());
        



        GameOverCheckerNode gameOverCheckerNode(sharedComponentHolder->IsGameOver());

        
        BackgroundObject backgroundObject(EntitiesComponentFactory::makeBackgroundEntity(UUID::generate(), backgroundRenderNode));
        DoodleObject doodle(EntitiesComponentFactory::makeDoodleEntity(
            UUID::generate(), doodleRenderNode, doodleConstantXMoveNode, doodleGraviatationNode, doodleHeightMonitoringNode));
        UserInputTracker userInputTracker(EntitiesComponentFactory::makeUserInputTrackerEntity(
            UUID::generate(), mouseTrackNode, pressedKeyNode, pressedMouseButtonTrackNode));
        ObjectEntitiesGenerator entitiesGenerator(EntitiesComponentFactory::makeEntitiesGenerator(
            UUID::generate(), platformGeneratorNode, enemyGeneratorNode, abilityGeneratorNode, projectileGeneratorNode));
        BeyondBondaryMovingEntity beyondBondaryMovingEntity(
            EntitiesComponentFactory::makeBeyondBondaryMovingEntity(UUID::generate(), beyondBondaryMovingNode));
        GameOverChecker gameOverChecker(EntitiesComponentFactory::makeGameOverChecker(UUID::generate(), gameOverCheckerNode));
        
        // == updateing the backgoround section 
        // =====================================
        // Get the render system from the SystemManagerComponent
        auto systemManager = makeSystemManagerComponent();
        auto renderSystem = std::static_pointer_cast<RenderSystem>(systemManager->getRenderSystem());

        // Add the background entity to the render system
        renderSystem->addNodeEmplace(backgroundObject.getUUID(), backgroundObject.getRenderNode());
        // =====================================

        EntityManagerComponent entityManager(backgroundObject, doodle, userInputTracker, entitiesGenerator, beyondBondaryMovingEntity, gameOverChecker);
        

        return std::make_shared<EntityManagerComponent>(entityManager);
    }

    static std::shared_ptr<SystemManagerComponent> makeSystemManagerComponent()
    {
        auto renderSystem = std::make_shared<RenderSystem>(RenderSystem(std::unordered_map<std::string, RenderNode>()));
        auto mouseTrackSystem = std::make_shared<MouseTrackSystem>(MouseTrackSystem(std::unordered_map<std::string, MouseTrackNode>()));
        auto pressedKeyTrackSystem = std::make_shared<PressedKeyTrackingSystem>(PressedKeyTrackingSystem(std::unordered_map<std::string, PressedKeyTrackNode>()));
        auto pressedMouseButtonTrackSystem = std::make_shared<PressedMouseButtonTrackSystem>(PressedMouseButtonTrackSystem(std::unordered_map<std::string, PressedMouseButtonTrackNode>()));
        auto constantXMoveSystem = std::make_shared<ConstantXMoveSystem>(ConstantXMoveSystem(std::unordered_map<std::string, ConstantXMoveNode>()));
        auto beyondBoundaryMovingSystem = std::make_shared<BeyondBoundaryMovingSystem>(BeyondBoundaryMovingSystem(std::unordered_map<std::string, BeyondBondaryMovingNode>()));
        auto gravitationSystem = std::make_shared<GravitationSystem>(GravitationSystem(std::unordered_map<std::string, GravitationNode>()));
        auto jumpSystem = std::make_shared<JumpSystem>(JumpSystem(std::unordered_map<std::string, JumpNode>()));
        auto enemyMovingSystem = std::make_shared<EnemyMovingSystem>(EnemyMovingSystem(std::unordered_map<std::string, EnemyMovingNode>()));
        auto jumpOnEnemySystem = std::make_shared<JumpOnEnemySystem>(JumpOnEnemySystem(std::unordered_map<std::string, JumpOnEnemyNode>()));
        auto enemyGeneratorSystem = std::make_shared<EnemyGeneratorSystem>(EnemyGeneratorSystem(renderSystem, enemyMovingSystem, jumpOnEnemySystem, std::unordered_map<std::string, EnemyGeneratorNode>()));
        auto projectileMovementSystem = std::make_shared<ProjectileMovementSystem>(ProjectileMovementSystem(std::unordered_map<std::string, ProjectileMovementNode>()));
        auto shootingEnemySystem = std::make_shared<ShootingEnemySystem>(ShootingEnemySystem(std::unordered_map<std::string, ShootingEnemyNode>()));
        auto projectileGeneratorSystem = std::make_shared<ProjectileGeneratorSystem>(ProjectileGeneratorSystem(renderSystem, projectileMovementSystem, shootingEnemySystem, std::unordered_map<std::string, ProjectileGeneratorNode>()));
        auto abilitySystem = std::make_shared<AbilitySystem>(AbilitySystem(projectileGeneratorSystem, std::unordered_map<std::string, AbilityNode>()));
        auto pickUpAbilitySystem = std::make_shared<PickUpAbilitySystem>(PickUpAbilitySystem(abilitySystem, std::unordered_map<std::string, PickUpAbilityNode>()));
        auto abilityGeneratorSystem = std::make_shared<AbilityGeneratorSystem>(AbilityGeneratorSystem(renderSystem, enemyMovingSystem, pickUpAbilitySystem, std::unordered_map<std::string, AbilityGeneratorNode>()));       
        auto platformMovingSystem = std::make_shared<PlatformMovingSystem>(PlatformMovingSystem(enemyGeneratorSystem, abilityGeneratorSystem, std::unordered_map<std::string, PlatformMovingNode>()));
        auto heightMonitoringSystem = std::make_shared<HeightMonitoringSystem>(HeightMonitoringSystem(platformMovingSystem, enemyMovingSystem, std::unordered_map<std::string, HeightMonitoringNode>()));
        auto platformGeneratorSystem = std::make_shared<PlatformGeneratorSystem>(PlatformGeneratorSystem(jumpSystem, renderSystem, platformMovingSystem, std::unordered_map<std::string, PlatformGeneratorNode>()));


        
        return std::make_shared<SystemManagerComponent>(SystemManagerComponent(renderSystem, mouseTrackSystem, pressedKeyTrackSystem,
            pressedMouseButtonTrackSystem, platformGeneratorSystem, constantXMoveSystem, beyondBoundaryMovingSystem,
            gravitationSystem, heightMonitoringSystem, platformMovingSystem, jumpSystem, enemyGeneratorSystem, enemyMovingSystem,
            abilityGeneratorSystem, projectileGeneratorSystem, projectileMovementSystem, jumpOnEnemySystem, shootingEnemySystem,
            pickUpAbilitySystem, abilitySystem));
    }

    static std::shared_ptr<RemovingManagerComponent> makeRemovingManagerComponent(std::shared_ptr<std::vector<std::string>> removingUUID,
        std::shared_ptr<std::vector<EnemyObject>> enemies, std::shared_ptr<SystemManagerComponent> systemManager)
    {
        return std::make_shared<RemovingManagerComponent>(removingUUID, enemies, systemManager);
    }
};
