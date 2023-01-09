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

    text.setString(first_string);
    text.setScale({0.9f, 0.9f});
    text.setPosition({200.0f, 620.0f - 30.0f});
    text.setOutlineColor(sf::Color::Black);
    text.setFillColor(sf::Color::Black);
    target.draw(text);

    text.setPosition({200.0f, 620.0f});
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

    speakerText.setString(this->names.at(dialogIndex));
    target.draw(speakerText);

    target.draw(transmissionText);
}

PictureDialogBox::PictureDialogBox(sf::Font *font1, sf::Texture *background)
        : DialogBox(font1, background) {
    text.setFont(*font);
    text.setCharacterSize(45);
    
    speakerText.setFont(*font);
    speakerText.setCharacterSize(30);
    speakerText.setScale({0.8f, 0.8f});
    speakerText.setPosition({140.0f, 1000.0f});
    speakerText.setOutlineColor(sf::Color::Black);
    speakerText.setFillColor(sf::Color::Black);
    
    transmissionText.setFont(*font);
    
    transmissionText.setString("Incoming Transmission (SPACE to continue, ESC to skip)");
    transmissionText.setScale({0.8f, 0.8f});
    transmissionText.setPosition({125.0f, 1035.0f});
    transmissionText.setOutlineColor(sf::Color::Black);
    transmissionText.setFillColor(sf::Color::White);
}

void PictureDialogBox::startDialog(std::vector<std::string> lines, std::vector<std::string> names,
                                   std::vector<sf::Texture *> textures, std::function<void()> callback) {
    DialogBox::startDialog(lines, callback);
    this->names = names;
    this->textures = textures;
}

void PictureDialogBox::update(float delta) {
    DialogBox::update(delta);

    float dialog_ratio = currentTextProgressTime / currentMaximumProgressTime;
    if (dialog_ratio >= 1.0f)
        nextAcc += delta;

    if (nextAcc - 1000 >= 0) {
        nextAcc = 0;
        interact();
    }
}

int PictureDialogBox::getMaxCharsPerLine() const {
    return 62;
}

void PictureDialogBox::startDialog(const std::vector<std::string> &lines, std::function<void()> callback) {
    DialogBox::startDialog(lines, callback);
}

bool PictureDialogBox::isInProgress() const {
    return DialogBox::isInProgress();
}

void PictureDialogBox::interact() {
    DialogBox::interact();
    nextAcc = 0;
}

void PictureDialogBox::kill() {
    this->dialogIndex = dialog.size() + 69;
}
