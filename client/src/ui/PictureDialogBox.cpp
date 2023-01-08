//
// Created by adrien on 07/01/23.
//

#include "ui/PictureDialogBox.h"

void PictureDialogBox::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    // TODO: CRINGE -> CODE COPIED AND SLIGHTLY MODIFIED FROM DialogBox::draw
    if (!this->isInProgress())
        return;

    sf::View old = target.getView();

    // this dialog is made for 1280 x 720 viewports so we set the viewport and then
    // we undo it for whatever viewport the user is already using
    sf::Vector2f viewSize = {1280, 720};
    target.setView(sf::View({viewSize.x / 2.0f, viewSize.y / 2.0f}, viewSize));

    float dialog_ratio = currentTextProgressTime / currentMaximumProgressTime;
    if (dialog_ratio > 1.0f)
        dialog_ratio = 1.0f;

    std::string first_string = dialog[dialogIndex][0];
    std::string second_string = dialog[dialogIndex][1];

    int characters_to_show = (first_string.size() + second_string.size()) * dialog_ratio;

    if (characters_to_show < first_string.size()) {
        second_string.clear();
        first_string = first_string.substr(0, characters_to_show);
    } else {
        second_string = second_string.substr(0, characters_to_show - first_string.size());
    }

    sprite.setPosition({60.0f, 620.0f - 50.0f});
    sprite.setScale({1160.0f / sprite.getTexture()->getSize().x,
                     128.0f / sprite.getTexture()->getSize().y});
    target.draw(sprite);

    text.setFont(*font);
    text.setString(first_string);
    text.setScale({1.2f, 1.2f});
    text.setPosition({250.0f, 620.0f - 30.0f});
    text.setOutlineColor(sf::Color::Black);
    text.setFillColor(sf::Color::Black);
    target.draw(text);

    text.setPosition({250.0f, 620.0f});
    text.setString(second_string);
    target.draw(text);

    target.setView(old);
    // TODO: ENDCRINGE

    speakerSprite.setTexture(*textures.at(dialogIndex));
    speakerSprite.setOrigin({0.5f * speakerSprite.getTexture()->getSize().x, 0.5f * speakerSprite.getTexture()->getSize().y});
    speakerSprite.setPosition({200.0f, 950.0f - 10.0f});
    speakerSprite.setScale({128.0f / speakerSprite.getTexture()->getSize().x,
                            128.0f / speakerSprite.getTexture()->getSize().y});
    target.draw(speakerSprite);

    speakerText.setFont(*font);
    speakerText.setString(this->names.at(dialogIndex));
    speakerText.setScale({0.8f, 0.8f});
    speakerText.setPosition({150.0f, 1000.f});
    speakerText.setOutlineColor(sf::Color::Black);
    speakerText.setFillColor(sf::Color::Black);
    target.draw(speakerText);
}

PictureDialogBox::PictureDialogBox(sf::Font *font1, sf::Texture *background)
        : DialogBox(font1, background) {
}

void PictureDialogBox::startDialog(std::vector<std::string> lines, std::vector<std::string> names,
                                   std::vector<sf::Texture *> textures, std::function<void()> callback) {
    DialogBox::startDialog(lines);
    this->names = names;
    this->textures = textures;
}

void PictureDialogBox::update(float delta) {
    DialogBox::update(delta);
}

void PictureDialogBox::startDialog(const std::vector<std::string> &lines, std::function<void()> callback) {
    DialogBox::startDialog(lines, callback);
}

bool PictureDialogBox::isInProgress() const {
    return DialogBox::isInProgress();
}

void PictureDialogBox::interact() {
    DialogBox::interact();
}
