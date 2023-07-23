#pragma once

#include "CollisionObject.hpp"
#include "MovementRequest.hpp"
#include "Movable.hpp"

#include <SFML/Graphics/Sprite.hpp>

#include <vector>
#include <memory>

class GameEngine {
public:
    explicit GameEngine(std::vector<std::unique_ptr<Movable>> movable_objects, std::vector<std::unique_ptr<CollisionObject>> collision_objects);

    void update(sf::Time elapsed_time, std::vector<sf::Keyboard::Key> pressed_keys);

    const std::vector<std::unique_ptr<CollisionObject>> &getCollisionObjects() const;

    const std::vector<std::unique_ptr<Movable>> &getMovableObjects() const;

private:
    sf::Time calculateElapsedTimeTillCollision(MovementRequest &movement_request, sf::IntRect collision_area);

    std::vector<std::unique_ptr<CollisionObject>> collision_objects;
    std::vector<std::unique_ptr<Movable>> movable_objects;
};


