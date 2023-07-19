#pragma once

#include <SFML/Graphics/Shape.hpp>
#include <SFML/System.hpp>


struct MovementRequest;

class CollisionObject {
public:
    CollisionObject(sf::Shape* shape) : shape(shape) {}
    virtual ~CollisionObject() = default;
    virtual sf::Vector2f calculateDistanceToBorder(MovementRequest* movement_request) = 0;
    virtual bool willColide(MovementRequest* movement_request) = 0;
    virtual sf::IntRect getArea() { return shape->getTextureRect();}
    virtual void adjustPositionIfCollided(MovementRequest* movement_request) = 0;

protected:
    sf::Shape* shape;
};


