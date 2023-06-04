#include "include.hpp"

#ifndef GAME_HPP_
    #define GAME_HPP_

    class Player {
        public:
            sf::RectangleShape hitbox;

            Player(void);
    };

    class Game {
        public:
            sf::RenderWindow *window;
            Player *player;

            Game(void);
    };

#endif //GAME_HPP_
