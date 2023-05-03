#pragma once

#include <string>
#include "../nodes/RenderNode.h"


class BackgroundObject
{
public:
    BackgroundObject(std::string uuid, RenderNode renderNode)
        : uuid(std::move(uuid)),
        renderNode(std::move(renderNode)) {}

    std::string getUUID()
    {
        return uuid;
    }

    RenderNode& getRenderNode()
    {
        return renderNode;
    }

private:
    std::string uuid;
    RenderNode renderNode;
};
