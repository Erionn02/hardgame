#include "CollisionObject.hpp"


class RectangleCollisionObject : public CollisionObject {
public:
    sf::Vector2f calculateDistanceToBorder(MovementRequest *movement_request) override;

    bool willColide(MovementRequest *movement_request) override;

    void adjustPositionIfCollided(MovementRequest *movement_request) override;
};