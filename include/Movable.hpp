#pragma once


#include "MovementRequest.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>


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

private:
    sf::Vector2f acceleration;
    sf::Vector2f velocity;
    sf::Vector2f position;
    sf::Vector2f size;
};