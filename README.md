# Doodle Jump Game Clone

This is a project for creating a clone of the famous mobile game, Doodle Jump. The project is implemented using the provided `Framework.h` header file. 

## Framework 

The `Framework.h` header file provides a set of classes and functions that are used to create the game. In this project, we use the following classes:

* `Framework`: This is an abstract base class that provides the interface for creating a game. We create a subclass of this class and implement its virtual methods to create our game.

* `SystemManagerComponent`: This class manages the game's systems. It contains methods to add and remove systems.

* `EntityManagerComponent`: This class manages the game's entities. It contains methods to add and remove entities.

* `RemovingManagerComponent`: This class manages the removal of nodes from systems. It contains methods to add and remove nodes.

* `AdapterScreenResolution`: This class is used to adapt the game to different screen resolutions.

* `HoldersComponentFactory`: This class is used to create holders for configurations and shared components.

* `ManagersComponentFactory`: This class is used to create managers for entities and removing nodes.

## Implementation

The implementation of the game is done in the `MyFramework` class, which is a subclass of the `Framework` class. The class contains the following members:

* `initBackground`: This member is a shared pointer to the game's background object.

* `initSystemManager`: This member is a shared pointer to the game's system manager component.

* `initScreenResolution`: This member is a shared pointer to the game's screen resolution adapter.

* `initEntityManager`: This member is a shared pointer to the game's entity manager component.

* `initRemovingManager`: This member is a shared pointer to the game's removing manager component.

### `PreInit` method

The `PreInit` method is called before the game is initialized. It sets the default screen resolution to 800x600 and initializes the `initScreenResolution` member.

### `Init` method

The `Init` method is called to initialize the game. It creates holders for configurations and shared components, and initializes the `initEntityManager`, `initSystemManager`, and `initRemovingManager` members. It adds the necessary nodes to the game's systems to create the game's functionality.

### `Close` method

The `Close` method is called when the game is closed. It does nothing in this implementation.

### `Tick` method

The `Tick` method is called every frame to update the game's state. It calls the game's systems to process the entities and their components. It also removes any nodes that need to be removed from the game's systems. If the game is over, it restarts the game.

### Input methods

The input methods handle user input for the game. The `onMouseMove` method updates the game's mouse tracker system. The `onMouseButtonClick` method updates the game's pressed mouse button tracker system and projectile generator system. The `onKeyPressed` method updates the game's pressed key tracker system and constant x-move system. The `onKeyReleased` method does nothing in this implementation.

### `GetTitle` method

The `GetTitle` method returns the title of the game, which is "DoodleJump".

### `restart` method

The `restart` method restarts the game by calling the `Init` method.

## Conclusion

This project implements a clone of the Doodle Jump mobile game using the `Framework.h` header file. The game is created using a subclass of the `Framework` class and the necessary systems and entities are added to create the
gameplay functionality. The input methods handle user input and the game's state is updated every frame using the Tick method. The project demonstrates the use of the Framework.h header file to create a game and the implementation of game systems and entities using modern C++ features.
