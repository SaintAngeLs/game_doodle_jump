#pragma once

#include <../include/json.hpp>

using nlohmann::json;

namespace config {
    struct BackgroundConfiguration
    {
        std::string spriteFilePath;
        double width;
        double height;
        
    };

    void to_json(json& j, BackgroundConfiguration& setting)
    {
        j = json{ {"spriteFilePath", setting.spriteFilePath},
        
        {"width", setting.width}, {"height", setting.height} };
    }

    void from_json(const json& j, BackgroundConfiguration& setting)
    {
        j.at("spriteFilePath").get_to(setting.spriteFilePath);
        
        j.at("width").get_to(setting.width);
        j.at("height").get_to(setting.height);
        
    }
}
