#include <iostream>
#include "Framework.h"


#include "managers/EntityManagerComponent.h"
#include "managers/RemovingManagerComponent.h"
#include "managers/SystemManagerComponent.h"
#include "utilities/AdapterScreenResolution.h"
#include "factories/HoldersComponentFactory.h"
#include "factories/ManagersComponentFactory.h"



/* Testing Framework */
class MyFramework : public Framework 
{
public:

	std::shared_ptr<BackgroundObject> initBackground;

	std::shared_ptr<SystemManagerComponent> initSystemManager;

	std::shared_ptr<AdapterScreenResolution> initScreenResolution;

	std::shared_ptr<EntityManagerComponent> initEntityManager;

	std::shared_ptr<RemovingManagerComponent> initRemovingManager;

	//MyFramework(int width, int height) : screenWidth(width), screenHeight(height) {}

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		// default parameteres of the screen height and width
		initScreenResolution = std::make_shared<AdapterScreenResolution>(800, 600);

		width = initScreenResolution->width;

		height = initScreenResolution->height;

		fullscreen = false;

	}

	virtual bool Init()
	{
		
		auto configurationsHolder = std::make_shared<ConfigurationsHolder>(HoldersComponentFactory::createConfigHolder(*initScreenResolution));

		auto sharedComponentHolder = std::make_shared<SharedComponentsHolder>(HoldersComponentFactory::createSharedComponentHolder(configurationsHolder, *initScreenResolution));

		initBackground = std::make_shared<BackgroundObject>("./resources/sprites/background.png"); // Load the background image

		initSystemManager->getRenderSystem()->addNodeEmplace(initBackground->getUUID(), initBackground->getRenderNode()); // Add the background component to the RenderSystem

		initEntityManager = ManagersComponentFactory::makeEntityManagerComponent(configurationsHolder, sharedComponentHolder);

		initSystemManager = ManagersComponentFactory::makeSystemManagerComponent();

		initRemovingManager = ManagersComponentFactory::makeRemovingManagerComponent(sharedComponentHolder->getRemovingUUID(), sharedComponentHolder->getEnemies(), initSystemManager);

		initSystemManager->getRenderSystem()->addNodeEmplace(initEntityManager->getDoodle().getUUID(), initEntityManager->getDoodle().getRenderNode());

		initSystemManager->getMouseTrackSystem()->addNodeEmplace(initEntityManager->getUserInputTracker().getUUID(), initEntityManager->getUserInputTracker().getMouseTrackNode());

		initSystemManager->getPlatformGeneratorSystem()->addNodeEmplace(initEntityManager->getEntitiesGenerator().getUUID(), initEntityManager->getEntitiesGenerator().getPlatformGeneratorNode());

		initSystemManager->getPressedMouseButtonTrackSystem()->addNodeEmplace(initEntityManager->getUserInputTracker().getUUID(), initEntityManager->getUserInputTracker().getPressedMouseButtonTrackSystem());

		initSystemManager->getEnemyGeneratorSystem()->addNodeEmplace(initEntityManager->getEntitiesGenerator().getUUID(), initEntityManager->getEntitiesGenerator().getEnemyGeneratorNode());

		initSystemManager->getAbilityGeneratorSystem()->addNodeEmplace(initEntityManager->getEntitiesGenerator().getUUID(), initEntityManager->getEntitiesGenerator().getAbilityGeneratorNode());

		initSystemManager->getProjectileGeneratorSystem()->addNodeEmplace(initEntityManager->getEntitiesGenerator().getUUID(), initEntityManager->getEntitiesGenerator().getProjectileGeneratorNode());

		initSystemManager->getConstantXMoveSystem()->addNodeEmplace(initEntityManager->getDoodle().getUUID(), initEntityManager->getDoodle().getConstantXMoveNode());

		initSystemManager->getPressedKeyTrackSystem()->addNodeEmplace(initEntityManager->getUserInputTracker().getUUID(), initEntityManager->getUserInputTracker().getPressedKeyTrackNode());

		initSystemManager->getBeyondBoundaryMovingSystem()->addNodeEmplace(initEntityManager->getBeyondBondaryMovingEntity().getUUID(), initEntityManager->getBeyondBondaryMovingEntity().getPlatformGeneratorNode());

		initSystemManager->getGravitationSystem()->addNodeEmplace(initEntityManager->getDoodle().getUUID(), initEntityManager->getDoodle().getGravitationNode());

		initSystemManager->getHeightMonitoringSystem()->addNodeEmplace(initEntityManager->getDoodle().getUUID(), initEntityManager->getDoodle().getHeightMonitoringNode());

		initSystemManager->getPlatformGeneratorSystem()->process();

		return true;

	}

	virtual void Close() 
	{

	}

	virtual bool Tick() 
	{
		drawTestBackground();
		

		initSystemManager->getRenderSystem()->process();

		initSystemManager->getGravitationSystem()->process();

		initSystemManager->getPickUpAbilitySystem()->process();

		initSystemManager->getAbilitySystem()->process();

		initSystemManager->getJumpOnEnemySystem()->process();

		initSystemManager->getShootingEnemySystem()->process();

		initSystemManager->getJumpSystem()->process();

		initSystemManager->getHeightMonitoringSystem()->process();

		initSystemManager->getBeyondBoundaryMovingSystem()->process();

		initSystemManager->getProjectileMovementSystem()->process();

		initSystemManager->getRenderSystem()->process();

		initRemovingManager->removeNodes();

		if (*initEntityManager->getGameOverChecker().getGameOverCheckerNode().IsGameOver())
		{
			Init();
		}
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) 
	{

		initSystemManager->getMouseTrackSystem()->process(CoordSystemR2(x, y));

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) 
	{

		if (!isReleased)
		{
			initSystemManager->getPressedMouseButtonTrackSystem()->process(button);

			initSystemManager->getProjectileGeneratorSystem()->process();
		}

	}

	virtual void onKeyPressed(FRKey k) 
	{

		initSystemManager->getPressedKeyTrackSystem()->process(k);

		initSystemManager->getConstantXMoveSystem()->process();

	}

	virtual void onKeyReleased(FRKey k) 
	{

	}

	const char* GetTitle() override
	{

		return "DoodleJump";

	}

	void restart()
	{
		/*initSystemManager.reset();

		initScreenResolution.reset();

		initEntityManager.reset();

		initRemovingManager.reset();*/

		Init();

		
	}
//private:
//	int screenHeight;
//	int screenWidth;
};

int main(int argc, char* argv[])
{
	int screenWidth = 800;

	int screenHeight = 600;
	
	//// Parse command-line arguments
	//for (int i = 1; i < argc; i++) 
	//{
	//    std::string arg = argv[i];
	//    if (arg == "-window" && i + 1 < argc) 
	//	{
	//        std::string sizeString = argv[i + 1];
	//        std::stringstream ss(sizeString);
	//        char sep;
	//        ss >> screenWidth >> sep >> screenHeight;
	//        if (ss.fail() || sep != 'x') 
	//		{
	//            std::cerr << "Invalid window size: " << sizeString << std::endl;
	//            return 1;
	//        }
	//        i++;
	//    }
	//}
	//return run(new MyFramework(screenWidth,screenHeight));
	return run(new MyFramework());
}



