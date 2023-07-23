#include "Game.hpp"
#include "GameEngine.hpp"
#include "RectangleCollisionObject.hpp"

#include <SFML/Graphics/Shape.hpp>

#include <thread>


int main() {
    std::vector<std::unique_ptr<CollisionObject>> collision_objects{};
    std::vector<std::unique_ptr<Movable>> movable_objects{};

    sf::Texture floor_texture{};
    sf::Texture texture{};

    if (!texture.loadFromFile(ASSETS_DIR"/jump_king.png")) {
        throw std::runtime_error("Error during loading hero.");
    }

    if (!floor_texture.loadFromFile(ASSETS_DIR"/floor.png")) {
        throw std::runtime_error("Error during loading floor_texture.");
    }

    sf::Sprite player{texture};
    player.scale({0.3f, 0.3f});
    movable_objects.push_back(std::make_unique<Movable>(std::move(player)));

    sf::Vector2f position{400,350};

    collision_objects.push_back(std::make_unique<RectangleCollisionObject>(std::move(floor_texture), position));

    auto game_engine = std::make_unique<GameEngine>(std::move(movable_objects),
                                                    std::move(collision_objects));

    Game game{800, 600, "Hello world",std::move(game_engine)};
    game.run();


    return 0;
}
