#pragma once

#include <SFML/Window.hpp>

class Movable;

struct MovementRequest {
    sf::Vector2f current_position;
    sf::Vector2f size;
    sf::Vector2f future_position;
    sf::Vector2f future_velocity;
    sf::Time requested_movement_time;
    Movable* movable;
};