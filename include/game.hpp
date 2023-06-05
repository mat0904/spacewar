#include "include.hpp"
#include <SFML/Graphics/CircleShape.hpp>

#ifndef GAME_HPP_
    #define GAME_HPP_

    class Player;

    class Ship {
        public:
            sf::RectangleShape body;
            sf::RectangleShape booster;
            sf::RectangleShape left_booster;
            sf::RectangleShape right_booster;

            Ship(void);
            void move(sf::Vector2f move_ship);
            void rotate(float angle);
            void display(sf::RenderWindow *window, Player *player);
            void set_position(sf::Vector2f position);
    };

    class Input {
        public:
            bool z_button;
            bool s_button;
            bool q_button;
            bool d_button;
            bool space_button;

            Input(void);
    };

    class Player : public Input {
        public:
            float rotation;
            Ship ship;
            sf::View view;

            sf::Vector2f move_vector;

            Player(void);
            void display(sf::RenderWindow *window);
            void set_rotation(void);
            void calcul_gravity_vector(void);
            void calcul_move_vector(void);
            void booster_break(void);
    };

    class Game {
        public:
            sf::RenderWindow *window;
            sf::CircleShape star;
            sf::Clock movement_clock;
            Player *player;

            Game(void);
    };

#endif //GAME_HPP_
