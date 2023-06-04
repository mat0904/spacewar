#include "include.hpp"

#ifndef GAME_HPP_
    #define GAME_HPP_

    class Player {
        public:
            float accel;
            float gravity_factor;
            float rotation;
            bool is_boosting;
            sf::RectangleShape body;
            sf::RectangleShape booster;

            Player(void);
            void Display(sf::RenderWindow *window);
    };

    class Game {
        public:
            sf::RenderWindow *window;
            Player *player;

            Game(void);
    };

#endif //GAME_HPP_
