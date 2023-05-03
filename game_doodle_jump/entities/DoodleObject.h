#pragma once

#include "../nodes/RenderNode.h"
#include "../nodes/ConstantXMoveNode.h"
#include "../nodes/GravitationNode.h"
#include "../nodes/HeightMonitoringNode.h"


class DoodleObject
{
public:
    DoodleObject(std::string uuid, RenderNode renderNode, ConstantXMoveNode constantXMoveNode, GravitationNode gravitationNode,
        HeightMonitoringNode heightMonitoringNode)
        : uuid(std::move(uuid)),
          renderNode(std::move(renderNode)),
          constantXMoveNode(std::move(constantXMoveNode)),
          gravitationNode(std::move(gravitationNode)),
          heightMonitoringNode(std::move(heightMonitoringNode)){}

    std::string getUUID()
    {
        return uuid;
    }

    RenderNode& getRenderNode()
    {
        return renderNode;
    }

    ConstantXMoveNode& getConstantXMoveNode()
    {
        return constantXMoveNode;
    }

    GravitationNode& getGravitationNode()
    {
        return gravitationNode;
    }

    HeightMonitoringNode& getHeightMonitoringNode()
    {
        return heightMonitoringNode;
    }


private:
    std::string uuid;
    RenderNode renderNode;
    ConstantXMoveNode constantXMoveNode;
    GravitationNode gravitationNode;
    HeightMonitoringNode heightMonitoringNode;
};
