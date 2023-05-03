#pragma once

#include <../include/json.hpp>

using nlohmann::json;

namespace config {
    struct PlatformConfiguration
    {
        std::string spriteFilePath;
        double coordinateX;
        double coordinateY;
        double width;
        double height;
        int platformAmount; 
    };

    void to_json(json& j, PlatformConfiguration& setting) 
    {
        j = json{ {"spriteFilePath", setting.spriteFilePath},
        {"x", setting.coordinateX}, {"y", setting.coordinateY},
        {"width", setting.width}, {"height", setting.height},
        {"platformAmount", setting.platformAmount}};
    }

    void from_json(const json& j, PlatformConfiguration& setting) 
    {
        j.at("spriteFilePath").get_to(setting.spriteFilePath);
        j.at("x").get_to(setting.coordinateX);
        j.at("y").get_to(setting.coordinateY);
        j.at("width").get_to(setting.width);
        j.at("height").get_to(setting.height);
        j.at("platformAmount").get_to(setting.platformAmount);
    }
}
