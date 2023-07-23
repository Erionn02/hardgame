#include "RectangleCollisionObject.hpp"
#include "MovementRequest.hpp"
#include "Movable.hpp"


RectangleCollisionObject::RectangleCollisionObject(sf::Texture texture, sf::Vector2f position)
        : texture(std::move(texture)) {
    shape.setTexture(&this->texture);
    shape.setPosition(position);
}

sf::Vector2f RectangleCollisionObject::calculateDistanceToBorder(MovementRequest *movement_request) {
    (void) movement_request;
    return {};
}

bool RectangleCollisionObject::willColide(MovementRequest *movement_request) {
    auto future_area = movement_request->movable->getArea();
    future_area.top += static_cast<int>((movement_request->future_position - movement_request->current_position).y);
    future_area.left += static_cast<int>((movement_request->future_position - movement_request->current_position).x);
    return shape.getTextureRect().intersects(future_area);
}

void RectangleCollisionObject::adjustMovementRequest(MovementRequest *movement_request) {
    auto my_rect = shape.getTextureRect();
    movement_request->future_position.y = static_cast<float>(movement_request->movable->velocity.y > 0 ? my_rect.top : my_rect.top + my_rect.height);
    movement_request->movable->velocity.y=0;
}

sf::IntRect RectangleCollisionObject::getArea() {
    return shape.getTextureRect();
}

const sf::Drawable & RectangleCollisionObject::getDrawable() {
    return shape;
}

