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

    void update(sf::Time elapsed_time);
private:
    sf::Time calculateElapsedTimeTillCollision(MovementRequest &movement_request, sf::IntRect collision_area);

    std::vector<std::unique_ptr<CollisionObject>> collision_objects;
    std::vector<std::unique_ptr<Movable>> movable_objects;
};


