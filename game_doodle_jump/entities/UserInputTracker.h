#pragma once
#include <string>
#include "../nodes/MouseTrackNode.h"
#include "../nodes/PressedKeyTrackNode.h"
#include "../nodes/MouseTrackNode.h"
#include "../nodes/PressedMouseButtonTrackNode.h"

#include "../systems/MouseTrackSystem.h"

class UserInputTracker
{
public:
    UserInputTracker(std::string uuid, MouseTrackNode mouseTrackNode, PressedKeyTrackNode pressedKeyTrackNode,
        PressedMouseButtonTrackNode pressedMouseButtonTrackNode)
        : uuid(std::move(uuid)),
        mouseTrackNode(std::move(mouseTrackNode)),
        pressedKeyTrackNode(std::move(pressedKeyTrackNode)),
        pressedMouseButtonTrackNode(std::move(pressedMouseButtonTrackNode)) {}

    std::string getUUID()
    {
        return uuid;
    }

    MouseTrackNode& getMouseTrackNode()
    {
        return mouseTrackNode;
    }

    PressedKeyTrackNode& getPressedKeyTrackNode()
    {
        return pressedKeyTrackNode;
    }

    PressedMouseButtonTrackNode& getPressedMouseButtonTrackSystem()
    {
        return pressedMouseButtonTrackNode;
    }

private:
    std::string uuid;
    MouseTrackNode mouseTrackNode;
    PressedKeyTrackNode pressedKeyTrackNode;
    PressedMouseButtonTrackNode pressedMouseButtonTrackNode;
};
