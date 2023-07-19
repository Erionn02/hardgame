#include "Game.hpp"
#include <SFML/Graphics/Shape.hpp>

#include <thread>


int main() {

    Game game{800,600,"Hello world",};
    game.run();



    return 0;
}
