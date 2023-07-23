#pragma once

#include <SFML/Graphics/Shape.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Sprite.hpp>


struct MovementRequest;

class CollisionObject {
public:
    virtual ~CollisionObject() = default;
    virtual sf::Vector2f calculateDistanceToBorder(MovementRequest* movement_request) = 0;
    virtual bool willColide(MovementRequest* movement_request) = 0;
    virtual sf::IntRect getArea() = 0;
    virtual const sf::Drawable & getDrawable() = 0;
    virtual void adjustMovementRequest(MovementRequest* movement_request) = 0;
};


