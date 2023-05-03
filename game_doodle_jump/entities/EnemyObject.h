#pragma once
#include "../nodes/EnemyMovingNode.h"
#include "../nodes/JumpOnEnemyNode.h"


class EnemyObject
{
public:

    EnemyObject(std::string uuid, RenderNode renderNode, EnemyMovingNode enemyMovingNode, JumpOnEnemyNode jumpOnEnemyNode)
        : uuid(std::move(uuid)),
          renderNode(std::move(renderNode)),
          enemyMovingNode(std::move(enemyMovingNode)),
          jumpOnEnemyNode(std::move(jumpOnEnemyNode)){}

    std::string getUUID()
    {
        return uuid;
    }

    RenderNode& getRenderNode()
    {
        return renderNode;
    }

    EnemyMovingNode& getEnemyMovingNode()
    {
        return enemyMovingNode;
    }

    JumpOnEnemyNode getJumpOnEnemyNode() const
    {
        return jumpOnEnemyNode;
    }


private:
    std::string uuid;
    RenderNode renderNode;
    EnemyMovingNode enemyMovingNode;
    JumpOnEnemyNode jumpOnEnemyNode;
};
