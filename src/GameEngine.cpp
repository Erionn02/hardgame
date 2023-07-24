#include "GameEngine.hpp"

#include <math.h>

GameEngine::GameEngine(std::vector<std::unique_ptr<Movable>> movable_objects,
                       std::vector<std::unique_ptr<CollisionObject>> collision_objects) : collision_objects(
        std::move(collision_objects)),
                                                                                          movable_objects(std::move(
                                                                                                  movable_objects)) {

}

void GameEngine::update(sf::Time elapsed_time, std::vector<sf::Keyboard::Key> pressed_keys) {
    for (auto &movable: movable_objects) {
         for(auto key: pressed_keys) {
            if(key == sf::Keyboard::Key::D) {
                movable->onRightClicked();
            }

            if(key == sf::Keyboard::Key::A) {
                movable->onLeftClicked();
            }

            if(key == sf::Keyboard::Key::Space) {
                movable->onJumpClicked();
            }
        }

        auto movement_request = movable->tryMove(elapsed_time);
        for (auto &collision: collision_objects) {
            if (collision->willColide(&movement_request)) {
                collision->adjustMovementRequest(&movement_request);
            }
        }
//
        movable->move(movement_request);
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

const std::vector<std::unique_ptr<CollisionObject>> &GameEngine::getCollisionObjects() const {
    return collision_objects;
}

const std::vector<std::unique_ptr<Movable>> &GameEngine::getMovableObjects() const {
    return movable_objects;
}
