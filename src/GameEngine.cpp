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
            if (collision->willColide(&movement_request)) {

                collision->adjustMovementRequest(&movement_request);
            }
//            movable->move()
        }

    }

}

// s_n=s.0 + V.0t + a*t*t/2

sf::Time GameEngine::calculateElapsedTimeTillCollision(MovementRequest &movement_request, sf::IntRect collision_area) {
    auto velocity = movement_request.movable->velocity;
    (void) velocity;
    collision_area.getPosition();

//    (void)displacement_movement;

    return sf::Time();
}
