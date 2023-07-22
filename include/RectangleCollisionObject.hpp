#include "CollisionObject.hpp"

#include <SFML/Graphics/RectangleShape.hpp>


class RectangleCollisionObject : public CollisionObject {
public:
    explicit RectangleCollisionObject(sf::RectangleShape shape);

    sf::Vector2f calculateDistanceToBorder(MovementRequest *movement_request) override;

    bool willColide(MovementRequest *movement_request) override;

    void adjustMovementRequest(MovementRequest *movement_request) override;

private:
    sf::RectangleShape shape;
};