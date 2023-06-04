#include "include.hpp"

#ifndef GAME_HPP_
    #define GAME_HPP_

    class Player {
        public:
            bool z_button;
            bool s_button;
            bool q_button;
            bool d_button;
            float accel;
            float gravity_factor;
            float rotation;
            sf::RectangleShape body;
            sf::RectangleShape booster;

            Player(void);
            void Display(sf::RenderWindow *window);
            void set_rotation(void);
    };

    class Game {
        public:
            sf::RenderWindow *window;
            Player *player;

            Game(void);
    };

#endif //GAME_HPP_
