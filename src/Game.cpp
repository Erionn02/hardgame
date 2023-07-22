#include "Game.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <thread>
#include <iostream>


Game::Game(unsigned int width, unsigned int height, const std::string &game_name,
           std::unique_ptr<GameEngine> game_engine) : window{sf::VideoMode{width, height},
                                                             game_name, sf::Style::Close | sf::Style::Resize},
                                                      game_engine(std::move(game_engine)) {

}


void Game::run() {
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    std::vector<sf::Sprite> game_objects{};

    sf::Texture texture{};

    if (!texture.loadFromFile(ASSETS_DIR"/jump_king.png")) {
        throw std::runtime_error("Error during loading hero.");
    }

    sf::Sprite player{texture};
    player.scale({0.3f, 0.3f});
    game_objects.push_back(std::move(player));

    while (window.isOpen()) {
        processEvents();
        time_since_last_update += clock.restart();
        while (time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;
            processEvents();
            update(game_objects.front());
        }
        render(game_objects);
        std::cout << "Player position, x: " << game_objects.front().getPosition().x << ", y: "
                  << game_objects.front().getPosition().y << std::endl;
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window.close();
            }
            default: {
            }
        }
    }
}

void Game::update(sf::Sprite &sprite) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        sprite.move(sf::Vector2f{0, -tick_movement});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        sprite.move(sf::Vector2f{0, tick_movement});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        sprite.move(sf::Vector2f{-tick_movement, 0});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        sprite.move(sf::Vector2f{tick_movement, 0});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        sprite.move(sf::Vector2f{0, -4 * tick_movement});
    }

}

void Game::render(const std::vector<sf::Sprite> &sprites) {
    window.clear();
    for (const auto &sprite: sprites) {
        window.draw(sprite);
    }
    window.display();
}
