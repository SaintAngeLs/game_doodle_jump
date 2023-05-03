#pragma once
#include <memory>
#include "../components/CoordSystemR2.h"
#include "../components/SizeR2.h"

class RenderNode
{
public:
    RenderNode(Sprite* sprite, std::shared_ptr<CoordSystemR2> coord, SizeR2 size)
        : sprite(std::move(sprite)),
        coord(std::move(coord)),
        size(size) {}

    Sprite* getSprite() const
    {
        return sprite;
    }

    CoordSystemR2 getCoord()
    {
        return *coord;
    }

    SizeR2 getSize() const
    {
        return size;
    }
    
private:
    Sprite* sprite;
    std::shared_ptr<CoordSystemR2> coord;
    SizeR2 size;
};
