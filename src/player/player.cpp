#include "../../include/prototype.hpp"

Input::Input(void)
{
    z_button = false;
    q_button = false;
    d_button = false;
    s_button = false;
    space_button = false;
}

Player::Player(void) : Input()
{
    view = sf::View();
    view.setSize(sf::Vector2f(1920, 1080));
}

void Player::display(sf::RenderWindow *window)
{
    ship.display(window, this);
}

void Player::set_rotation(void)
{
    if (q_button == true && d_button == true)
        return;
    if (q_button == true) {
        ship.angle -= 1;
    }
    if (d_button == true) {
        ship.angle += 1;
    }
    ship.angle = (int)ship.angle % 360;
    ship.rotate();
}

void Player::booster_break(void)
{
    if (space_button == true) {
        ship.move_vector.x /= 1.01;
        ship.move_vector.y /= 1.01;
    }
}

void Player::calcul_move_vector(void)
{
    if (z_button == true) {
        ship.move_vector.x = ship.move_vector.x + (cos(ship.angle * (M_PI / 180)) / 100);
        ship.move_vector.y = ship.move_vector.y + (sin(ship.angle * (M_PI / 180)) / 100);
    }
    ship.move();
}
