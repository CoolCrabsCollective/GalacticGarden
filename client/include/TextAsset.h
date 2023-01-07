//
// Created by william on 06/01/23.
//

#ifndef LD52_CLIENT_TEXTASSET_H
#define LD52_CLIENT_TEXTASSET_H

#include <SFML/Graphics.hpp>
#include <string>
#include <utility>
#include <WIZ/asset/Asset.h>

class TextAsset : public wiz::Asset<std::string> {
protected:
    const std::string path;
public:
    explicit TextAsset(std::string path);
    void* load() const override;
    const std::string& getName() const override;

};

#endif //LD52_CLIENT_TEXTASSET_H
