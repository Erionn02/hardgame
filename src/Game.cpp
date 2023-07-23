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

    while (window.isOpen()) {
        processEvents();
        time_since_last_update += clock.restart();
        while (time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;
            processEvents();
            auto pressed_keys = getPressedKeys();
            game_engine->update(time_per_frame, std::move(pressed_keys));
        }
        render();
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

std::vector<sf::Keyboard::Key> Game::getPressedKeys() {
    std::vector<sf::Keyboard::Key> pressed_keys{};

    for (auto pressed_key: {sf::Keyboard::Key::W, sf::Keyboard::Key::S, sf::Keyboard::Key::A, sf::Keyboard::Key::D,
                            sf::Keyboard::Key::Space}) {
        if (sf::Keyboard::isKeyPressed(pressed_key)) {
            pressed_keys.push_back(pressed_key);
        }
    }

    return pressed_keys;
}


void Game::render() {
    window.clear();
    for (const auto &collision_object: game_engine->getCollisionObjects()) {
        window.draw(collision_object->getDrawable());
    }
    for (const auto &movable_object: game_engine->getMovableObjects()) {
        window.draw(movable_object->getDrawable());
    }
    window.display();
}

