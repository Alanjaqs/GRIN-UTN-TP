#ifndef PICKABLEITEM_H
#define PICKABLEITEM_H

#include <SFML/Graphics.hpp>

class PickableItem : public sf::Drawable {
protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

public:
    virtual ~PickableItem() {}
    virtual bool detectCollision() = 0;
};

#endif  // PICKABLEITEM_H
