#pragma once

#include <algorithm>
#include <unordered_map>

#include "InputSystem.h"
#include "System.h"
#include "../nodes/PressedKeyTrackNode.h"

class PressedKeyTrackingSystem : InputSystem<PressedKeyTrackNode, FRKey>
{
public:
    PressedKeyTrackingSystem(std::unordered_map<std::string, PressedKeyTrackNode> nodes)
        : nodesSet(std::move(nodes)) {}

    void addNodeEmplace(std::string&& uuid, PressedKeyTrackNode& node)
    {
        nodesSet.emplace(std::make_pair(uuid, node));
    }

    void process(FRKey key)
    {
        std::ranges::for_each(nodesSet, [&](std::pair<const std::string, PressedKeyTrackNode>& pair)
            {
                pair.second.setPressedKey(key);
            });
    }

    void removeNode(std::string key)
    {
        nodesSet.erase(key);
    }

private:
    std::unordered_map<std::string, PressedKeyTrackNode> nodesSet;
};
