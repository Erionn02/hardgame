#include "Movable.hpp"

MovementRequest Movable::tryMove(sf::Time elapsed_time) {
    return {.current_position = position,
            .size = size,
            .future_position =  position + elapsed_time.asSeconds() * velocity +
                                0.5f * elapsed_time.asSeconds() * elapsed_time.asSeconds() * acceleration,
            .requested_movement_time = elapsed_time,
            .movable = this};
}

void Movable::move(sf::Vector2f velocity_transformation, sf::Time elapsed_time_till_collision, sf::Time left_time) {
    move(elapsed_time_till_collision);
    velocity = sf::Vector2f{velocity.x * velocity_transformation.x, velocity.y * velocity_transformation.y};
    move(left_time);
}

void Movable::move(sf::Time elapsed_time) {
    position = position + elapsed_time.asSeconds() * velocity +
               0.5f * elapsed_time.asSeconds() * elapsed_time.asSeconds() * acceleration;
    velocity += acceleration*elapsed_time.asSeconds();
    sprite.setPosition(position);
}

std::optional<sf::IntRect> Movable::calculateCollisionArea(sf::IntRect area) {
    sf::IntRect collision_area{};

    if(sprite.getTextureRect().intersects(area, collision_area)){
        return collision_area;
    }
    return std::nullopt;
}

sf::IntRect Movable::getArea() {
    return sprite.getTextureRect();
}
