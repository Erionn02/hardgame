#pragma once
#include "Movable.hpp"
#include "GameEngine.hpp"

#include <SFML/Window.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <string>
#include <vector>


class Game {
public:
    Game(unsigned int width, unsigned int height, const std::string& game_name, std::unique_ptr<GameEngine> game_engine);

    void run();

private:
    void processEvents();
    void update(sf::Sprite &sprite);
    std::vector<sf::Keyboard::Key> getPressedKeys();
    void render();


    sf::RenderWindow window;
    std::unique_ptr<GameEngine> game_engine;
    float fps{60.0};
    float tick_movement{4};
    sf::Time time_per_frame{sf::seconds(1.f/fps)};
};


