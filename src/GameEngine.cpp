#include "GameEngine.hpp"

#include <math.h>

GameEngine::GameEngine(std::vector<std::unique_ptr<Movable>> movable_objects,
                       std::vector<std::unique_ptr<CollisionObject>> collision_objects) : collision_objects(
        std::move(collision_objects)),
                                                                                          movable_objects(std::move(
                                                                                                  movable_objects)) {

}

void GameEngine::update(sf::Time elapsed_time) {

    for (auto &movable: movable_objects) {
        for (auto &collision: collision_objects) {
            auto movement_request = movable->tryMove(elapsed_time);

            if (auto collision_area = movable->calculateCollisionArea(
                        collision->getArea()); collision_area.has_value()) {
                sf::Time elapsed_time_till_collision = calculateElapsedTimeTillCollision(movement_request,
                                                                                         collision_area.value());



                movable->move({}, elapsed_time_till_collision, elapsed_time-elapsed_time_till_collision);
            } else {
                movable->move(elapsed_time);
            }
        }
    }
}

sf::Time GameEngine::calculateElapsedTimeTillCollision(MovementRequest &movement_request, sf::IntRect collision_area) {
    sf::Vector2f displacement_movement = movement_request.movable->position +
                                         sf::Vector2f{static_cast<float>(collision_area.width),
                                                      static_cast<float>(collision_area.height)};



    return sf::Time();
}
