#include "CollisionObject.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>


class RectangleCollisionObject : public CollisionObject {
public:
    explicit RectangleCollisionObject(sf::Texture texture, sf::Vector2f position);

    sf::Vector2f calculateDistanceToBorder(MovementRequest *movement_request) override;

    sf::IntRect getArea() override;

    const sf::Drawable& getDrawable() override;

    bool willColide(MovementRequest *movement_request) override;

    void adjustMovementRequest(MovementRequest *movement_request) override;

private:
    sf::Texture texture{};
    sf::RectangleShape shape{};
};