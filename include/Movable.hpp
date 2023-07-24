#pragma once

#include "MovementRequest.hpp"
#include "GameConfig.hpp"
#include "CollisionObject.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include <optional>

class Movable {
public:
    explicit Movable(sf::Sprite sprite);

    MovementRequest tryMove(sf::Time elapsed_time);

    void move(const MovementRequest& movement_request);
    void onRightClicked();
    void onLeftClicked();
    void onJumpClicked();
    std::optional<sf::IntRect> calculateCollisionArea(sf::IntRect area);
    sf::IntRect getArea();
    const sf::Drawable & getDrawable();
private:
//
//
//    void correctForCollision(std::optional<sf::Vector2f> vertical_collision_line, std::optional<sf::Vector2f> horizontal_collision_line) {
//
//    }

    sf::Sprite sprite;
public:
    sf::Vector2f acceleration{0,GameConfig::gravity};
    sf::Vector2f velocity{0,0};
    sf::Vector2f position{0,0};
    sf::Vector2f size;
};