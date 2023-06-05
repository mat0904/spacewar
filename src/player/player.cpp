#include "../../include/prototype.hpp"

Player::Player(void)
{
    rotation = 0;
    ship = Ship();
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
    rotation = (int)rotation % 360;
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

void Player::detect_border(void)
{
    sf::Vector2f vector = ship.body.getPosition();
    if (vector.x >= 1920) {
        vector.x = 0;
    } else if (vector.x <= 0) {
        vector.x = 1920;
    }
    if (vector.y >= 1080) {
        vector.y = 0;
    } else if (vector.y <= 0) {
        vector.y = 1080;
    }
    ship.set_position(vector);
}
