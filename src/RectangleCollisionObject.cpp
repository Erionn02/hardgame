#include "RectangleCollisionObject.hpp"
#include "MovementRequest.hpp"
#include "Movable.hpp"

sf::Vector2f RectangleCollisionObject::calculateDistanceToBorder(MovementRequest *movement_request) {

}

bool RectangleCollisionObject::willColide(MovementRequest *movement_request) {

    return false;
}

void RectangleCollisionObject::adjustPositionIfCollided(MovementRequest *movement_request) {
    movement_request->movable->move()


}
