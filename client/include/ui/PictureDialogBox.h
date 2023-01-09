//
// Created by adrien on 07/01/23.
//

#ifndef LD52_CLIENT_PICTUREDIALOGBOX_H
#define LD52_CLIENT_PICTUREDIALOGBOX_H

#include "WIZ/ui/DialogBox.h"

class PictureDialogBox : public wiz::DialogBox {
    std::vector<std::string> names;
    std::vector<sf::Texture *> textures;

    mutable sf::Sprite speakerSprite;
    mutable sf::Text speakerText;
    mutable sf::Text transmissionText;

    float nextAcc = 0;

public:
    PictureDialogBox(sf::Font *font1, sf::Texture *background);


    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;

    void startDialog(std::vector<std::string> lines, std::vector<std::string> names, std::vector<sf::Texture*> textures, std::function<void()> callback);

    void update(float delta) override;

    void startDialog(const std::vector<std::string> &lines, std::function<void()> callback) override;

    bool isInProgress() const override;

    void interact() override;

    void kill();

protected:
    int getMaxCharsPerLine() const override;
};


#endif //LD52_CLIENT_PICTUREDIALOGBOX_H
