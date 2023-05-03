#pragma once

//#include "uuid_v4.h"
#include "../../Dependencies/game_doodle_jump/include/uuid_v4.h"

class UUID
{
public:
    static std::string generate()
    {
        return UUIDv4::UUIDGenerator<std::mt19937_64>().getUUID().str();
    }
};