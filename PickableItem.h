#ifndef PICKABLEITEM_H
#define PICKABLEITEM_H

#include <SFML/Graphics.hpp>
#include <string>
class PickableItem {
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    bool visible = true;
    bool hasBeenPicked = false;
public:
    // Constructor
    PickableItem(const std::string& filename);
    // Setters
    void setVisible(bool v) { visible = v; }
    void setHasBeenPicked(bool v) { hasBeenPicked = v; }
    // Getters
    bool getVisible() { return visible; }
    bool getHasBeenPicked() { return hasBeenPicked; }
    sf::Sprite& getSprite() { return sprite; }
};

#endif  // PICKABLEITEM_H
