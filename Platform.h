#pragma once
#include <SFML/Graphics.hpp>

class Platform : public sf::Drawable
{
private:
    sf::Texture platTexture1;
    sf::Sprite platSprite1;

    // Lados de plataformas
    sf::FloatRect hitbox;
    float platformTop;
    float platformBottom;
    float platformLeft;
    float platformRight;

public:
    Platform();
    sf::Sprite& getPlatform(int tipoPlataforma);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setPlatPosition(float x, float y);
    void updateHitbox();
    sf::FloatRect getHitbox();
    float getPlatTop();
    float getPlatBottom();
    float getPlatLeft();
    float getPlatRight();
    

};