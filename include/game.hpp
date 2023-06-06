#include "include.hpp"
#include <SFML/Graphics/CircleShape.hpp>

#ifndef GAME_HPP_
    #define GAME_HPP_

    class Player;

    class Radar {
        public:
            sf::CircleShape background;
            sf::VertexArray lines;
            int balayeur_angle;
            sf::VertexArray balayeur;


            Radar(void);
            void display(sf::RenderWindow *window);
            void update(float rotation, sf::View *view);
            void update_balayeur(sf::View *view);
    };

    class Hud {
        public:
            sf::Font font;
            sf::Text info;
            Radar radar;

            Hud(void);
            void update(float angle_input, sf::Vector2f mv, sf::View *view);
            void display(sf::RenderWindow *window);
    };

    class Ship {
        public:
            sf::RectangleShape body;
            sf::RectangleShape booster;
            sf::RectangleShape left_booster;
            sf::RectangleShape right_booster;

            sf::Vector2f move_vector;
            float angle;

            Ship(void);
            void move(void);
            void rotate(void);
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
            Ship ship;
            Hud hud;
            sf::View view;

            Player(void);
            void display(sf::RenderWindow *window);
            void set_rotation(void);
            void calcul_move_vector(void);
            void booster_break(void);
    };

    class Game {
        public:
            sf::RenderTexture pattern;
            sf::Sprite background;
            sf::RenderWindow *window;
            sf::Clock movement_clock;
            Player *player;

            Game(void);
            void create_background(std::string texture_path);
            void draw_background(void);
    };

#endif //GAME_HPP_
