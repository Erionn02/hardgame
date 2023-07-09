#include <iostream>
#include <string>
#include <memory>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>


int f(int x){
    return x;
}


std::string f(std::string x){
    return x;
}

int main() {
    sf::RenderWindow window{sf::VideoMode{800,600}, "Hello world", sf::Style::Close | sf::Style::Resize};

    sf::RectangleShape player{sf::Vector2f{100.f,100.f}};

    player.setFillColor(sf::Color::Magenta);
    float start_factor{1.f};
    float factor{start_factor};


    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed: {
                    window.close();
                }
                default: {

                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Equal)){
                if(factor<10*start_factor){
                    factor+=start_factor;
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Dash)){
                if(factor>start_factor){
                    factor-=start_factor;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                player.move(factor*sf::Vector2f{0,-1});
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                player.move(factor*sf::Vector2f{0,1});
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                player.move(factor*sf::Vector2f{-1,0});
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                player.move(factor*sf::Vector2f{1,0});
            }

            window.clear();
            window.draw(player);
            window.display();
        }
    }




    return 0;
}
