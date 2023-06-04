#include "include.hpp"

#ifndef GAME_HPP_
    #define GAME_HPP_

    class Player {
        public:
            bool z_button;
            bool s_button;
            bool q_button;
            bool d_button;
            float af;
            float gf;
            float rotation;
            sf::RectangleShape body;
            sf::RectangleShape booster;

            Player(void);
            void display(sf::RenderWindow *window);
            void set_rotation(void);
            void set_speed(void);
    };

    class Game {
        public:
            sf::RenderWindow *window;
            Player *player;

            Game(void);
    };

#endif //GAME_HPP_
