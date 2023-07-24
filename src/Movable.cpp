#include "Movable.hpp"


Movable::Movable(sf::Sprite sprite): sprite(std::move(sprite)) {

}

MovementRequest Movable::tryMove(sf::Time elapsed_time) {
    return {.current_position = position,
            .size = size,
            .future_position =  position + elapsed_time.asSeconds() * velocity +
                                0.5f * elapsed_time.asSeconds() * elapsed_time.asSeconds() * acceleration,
            .future_velocity = velocity + acceleration*elapsed_time.asSeconds(),
            .requested_movement_time = elapsed_time,
            .movable = this};
}

void Movable::move(const MovementRequest &movement_request) {
    position = movement_request.future_position;
    velocity = movement_request.future_velocity;
    sprite.setPosition(position);
}


void Movable::onRightClicked() {
    velocity.x = GameConfig::vertical_velocity_tick;
}

void Movable::onLeftClicked() {
    velocity.x = -GameConfig::vertical_velocity_tick;
}

void Movable::onJumpClicked() {
    velocity.y = GameConfig::jump_velocity;
}

std::optional<sf::IntRect> Movable::calculateCollisionArea(sf::IntRect area) {
    sf::IntRect collision_area{};

    if (sprite.getTextureRect().intersects(area, collision_area)) {
        return collision_area;
    }
    return std::nullopt;
}

const sf::Drawable &Movable::getDrawable() {
    return sprite;
}

sf::IntRect Movable::getArea() {
    return sprite.getTextureRect();
}

