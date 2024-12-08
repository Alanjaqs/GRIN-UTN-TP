#include "PickableItem.h"
PickableItem::PickableItem(const std::string &filename) {
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
}