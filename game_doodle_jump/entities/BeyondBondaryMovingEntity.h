#pragma once
#include <string>
#include "../nodes/BeyondBondaryMovingNode.h"

class BeyondBondaryMovingEntity
{
public:
    // Constructor that initializes the BeyondBondaryMovingEntity with a UUID and a BeyondBondaryMovingNode.
    BeyondBondaryMovingEntity(std::string uuid, BeyondBondaryMovingNode beyondBondaryMovingNode)
        : uuid(std::move(uuid)),
        beyondBondaryMovingNode(beyondBondaryMovingNode) {}

    // Getter function for the UUID of the BeyondBondaryMovingEntity.
    std::string getUUID()
    {
        return uuid;
    }

    // Getter function for the BeyondBondaryMovingNode of the BeyondBondaryMovingEntity.
    BeyondBondaryMovingNode& getPlatformGeneratorNode()
    {
        return beyondBondaryMovingNode;
    }

private:
    // UUID of the BeyondBondaryMovingEntity, used as a unique identifier.
    std::string uuid;
    // BeyondBondaryMovingNode object that stores the properties and behavior of the entity.
    BeyondBondaryMovingNode beyondBondaryMovingNode;
};
