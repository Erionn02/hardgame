#pragma once

#include "MovementRequest.hpp"
#include "CollisionObject.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include <optional>

class Movable {
public:
    MovementRequest tryMove(sf::Time elapsed_time) {
        return {.current_position = position,
                .size = size,
                .future_position =  position + elapsed_time.asSeconds() * velocity +
                                    0.5f * elapsed_time.asSeconds() * elapsed_time.asSeconds() * acceleration,
                .requested_movement_time = elapsed_time,
                .movable = this};
    }

    void move(sf::Vector2f velocity_transformation, sf::Time elapsed_time_till_collision, sf::Time left_time) {
        move(elapsed_time_till_collision);
        velocity = sf::Vector2f{velocity.x * velocity_transformation.x, velocity.y * velocity_transformation.y};
        move(left_time);
    }

    void move(sf::Time elapsed_time) {
        position = position + elapsed_time.asSeconds() * velocity +
                   0.5f * elapsed_time.asSeconds() * elapsed_time.asSeconds() * acceleration;
        velocity += acceleration*elapsed_time.asSeconds();
    }


    std::optional<sf::IntRect> calculateCollisionArea(sf::IntRect area) {
        sf::IntRect collision_area{};

        if(sprite.getTextureRect().intersects(area, collision_area)){
            return collision_area;
        }
        return std::nullopt;
    }


private:
//
//
//    void correctForCollision(std::optional<sf::Vector2f> vertical_collision_line, std::optional<sf::Vector2f> horizontal_collision_line) {
//
//    }

    sf::Sprite sprite;
public:
    sf::Vector2f acceleration;
    sf::Vector2f velocity;
    sf::Vector2f position;
    sf::Vector2f size;
};