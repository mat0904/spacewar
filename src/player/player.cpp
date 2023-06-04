#include "../../include/prototype.hpp"

Player::Player(void)
{
    af = 0;
    gf = 0;
    rotation = 0;
    body = sf::RectangleShape(sf::Vector2f(20, 20));
    booster = sf::RectangleShape(sf::Vector2f(10, 20));

    body.setFillColor(sf::Color::Transparent);
    body.setOutlineColor(sf::Color::Green);
    body.setOutlineThickness(2);
    body.setOrigin(sf::Vector2f(10, 10));
    body.setPosition(sf::Vector2f(100, 100));

    booster.setFillColor(sf::Color::Transparent);
    booster.setOutlineColor(sf::Color::Yellow);
    booster.setOutlineThickness(2);
    booster.setOrigin(sf::Vector2f(22, 10));
    booster.setPosition(sf::Vector2f(100, 100));
}

void Player::display(sf::RenderWindow *window)
{
    window->draw(body);
    if (z_button == true)
        window->draw(booster);
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
    booster.setRotation(rotation);
    body.setRotation(rotation);
}

void Player::calcul_move_vector(void)
{
    if (z_button == true) {
        move_vector.x = move_vector.x + (cos(rotation * (M_PI / 180)) / 100);
        move_vector.y = move_vector.y + (sin(rotation * (M_PI / 180)) / 100);
    }
    booster.move(move_vector);
    body.move(move_vector);
}

void Player::detect_border(void)
{
    sf::Vector2f vector = body.getPosition();
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
    body.setPosition(vector);
    booster.setPosition(vector);
}
