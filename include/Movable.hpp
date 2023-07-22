#pragma once

#include "MovementRequest.hpp"
#include "CollisionObject.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include <optional>

class Movable {
public:
    MovementRequest tryMove(sf::Time elapsed_time);

    void move(sf::Vector2f velocity_transformation, sf::Time elapsed_time_till_collision, sf::Time left_time);
    void move(sf::Time elapsed_time);
    std::optional<sf::IntRect> calculateCollisionArea(sf::IntRect area);
    sf::IntRect getArea();
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