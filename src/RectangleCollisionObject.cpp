#include "RectangleCollisionObject.hpp"
#include "MovementRequest.hpp"
#include "Movable.hpp"


RectangleCollisionObject::RectangleCollisionObject(sf::Texture texture, sf::Vector2f position)
        : texture(texture) {
    sprite.setTexture(this->texture);
    this->texture.loadFromFile(ASSETS_DIR"/floor.png");
    sprite.setTexture(this->texture);
    sprite.setScale(3.5, 1.0);
    sprite.setPosition(position);
}

sf::Vector2f RectangleCollisionObject::calculateDistanceToBorder(MovementRequest *movement_request) {
    (void) movement_request;
    return {};
}

bool RectangleCollisionObject::willColide(MovementRequest *movement_request) {
    auto collision_rect = getArea();
    collision_rect.left+= static_cast<int>(sprite.getPosition().x);
    collision_rect.top+=static_cast<int>(sprite.getPosition().y);
    auto area = movement_request->movable->getArea();
    (void)area;
    auto xd = sprite.getPosition();
    (void )xd;

    return collision_rect.intersects(movement_request->movable->getArea());
}

void RectangleCollisionObject::adjustMovementRequest(MovementRequest *movement_request) {
    auto my_rect = getArea();
    my_rect.left += static_cast<int>(sprite.getPosition().x);
    my_rect.top+=static_cast<int>(sprite.getPosition().y);
    if(movement_request->movable->velocity.y >  0) {
        movement_request->future_position.y = movement_request->current_position.y;
    }
    movement_request->movable->velocity.y=0;
}

sf::IntRect RectangleCollisionObject::getArea() {
    auto area = sprite.getTextureRect();
    auto scale = sprite.getScale();
    area.width= static_cast<int>(static_cast<float>(area.width)*scale.x);
    area.height= static_cast<int>(static_cast<float>(area.height)*scale.y);
    return area;
}

const sf::Drawable & RectangleCollisionObject::getDrawable() {
    return sprite;
}

