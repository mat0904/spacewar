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
    rotation = 0;
    ship = Ship();
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
        rotation -= 1;
    }
    if (d_button == true) {
        rotation += 1;
    }
    if (q_button == true || d_button == true) {
        rotation = (int)rotation % 360;
    }
    ship.rotate(rotation);
}

void Player::calcul_gravity_vector(void)
{
    return;
    /*sf::Vector2f mid = {500, 500};
    sf::Vector2f pos = body.getPosition();
    sf::Vector2f distance = {mid.x - pos.x, mid.y - pos.y};
    distance.x *= 5;
    distance.y *= 5;
    move_vector.x += 1 / distance.x;
    move_vector.y += 1 / distance.y;*/
}

void Player::booster_break(void)
{
    if (space_button == true) {
        move_vector.x /= 1.01;
        move_vector.y /= 1.01;
    }
}

void Player::calcul_move_vector(void)
{
    if (z_button == true) {
        move_vector.x = move_vector.x + (cos(rotation * (M_PI / 180)) / 100);
        move_vector.y = move_vector.y + (sin(rotation * (M_PI / 180)) / 100);
    }
    this->calcul_gravity_vector();
    ship.move(move_vector);
}
