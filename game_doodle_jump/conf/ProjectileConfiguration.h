#pragma once

#include <../include/json.hpp>

using nlohmann::json;

namespace config {
    struct ProjectileConfiguration
    {
        std::string spriteFilePath;
        double width;
        double height;
        double moveDistance;
    };
    
    void to_json(json& j, ProjectileConfiguration& setting) {
        j = json{ {"spriteFilePath", setting.spriteFilePath},
        {"width", setting.width}, {"height", setting.height},
          {"moveDistance", setting.moveDistance},
        };
    }

    void from_json(const json& j, ProjectileConfiguration& setting) {
        j.at("spriteFilePath").get_to(setting.spriteFilePath);
        j.at("width").get_to(setting.width);
        j.at("height").get_to(setting.height);
        j.at("moveDistance").get_to(setting.moveDistance);
    }
}
