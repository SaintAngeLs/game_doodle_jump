#pragma once
#include <../include/json.hpp>
using nlohmann::json;

namespace config {
    struct DoodleConfiguration
    {
        std::string spriteFilePath;
        double coordinateX;
        double coordinateY;
        double width;
        double height;
        double moveDistance;
        double gravitation;
        double maxHeight;
        double jumpForce;
    };

    void to_json(json& j, DoodleConfiguration& setting) 
    {
        j = json{ {"spriteFilePath", setting.spriteFilePath},
        {"x", setting.coordinateX}, {"y", setting.coordinateY},
        {"width", setting.width}, {"height", setting.height},
        {"moveDistance", setting.moveDistance}, {"gravitation", setting.gravitation},
        {"maxHeight", setting.maxHeight}, {"jumpForce", setting.jumpForce}
        };
    }

    void from_json(const json& j, DoodleConfiguration& setting) 
    {
        j.at("spriteFilePath").get_to(setting.spriteFilePath);
        j.at("x").get_to(setting.coordinateX);
        j.at("y").get_to(setting.coordinateY);
        j.at("width").get_to(setting.width);
        j.at("height").get_to(setting.height);
        j.at("moveDistance").get_to(setting.moveDistance);
        j.at("gravitation").get_to(setting.gravitation);
        j.at("maxHeight").get_to(setting.maxHeight);
        j.at("jumpForce").get_to(setting.jumpForce);
    }
}
