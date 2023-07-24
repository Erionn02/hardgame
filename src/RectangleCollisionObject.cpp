#include "RectangleCollisionObject.hpp"
#include "MovementRequest.hpp"
#include "Movable.hpp"


RectangleCollisionObject::RectangleCollisionObject(sf::Texture texture, sf::Vector2f position)
        : texture(texture) {
    shape.setTexture(&this->texture);
    this->texture.loadFromFile(ASSETS_DIR"/floor.png");
    shape.setTexture(&this->texture);
    shape.setScale(0.3f,0.3f);
    shape.setPosition(position);
}

sf::Vector2f RectangleCollisionObject::calculateDistanceToBorder(MovementRequest *movement_request) {
    (void) movement_request;
    return {};
}

bool RectangleCollisionObject::willColide(MovementRequest *movement_request) {
    shape.setTexture(&this->texture);
    auto future_area = movement_request->movable->getArea();
    future_area.top += static_cast<int>((movement_request->future_position - movement_request->current_position).y);
    future_area.left += static_cast<int>((movement_request->future_position - movement_request->current_position).x);
    auto tmp = shape.getTextureRect();
    auto tmp2 = shape.getPosition();
    (void)tmp;
    (void)tmp2;
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

