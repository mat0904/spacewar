#include "../../include/prototype.hpp"

Player::Player(void)
{
    af = 0;
    gf = 0;
    rotation = 0;
    body = sf::RectangleShape(sf::Vector2f(20, 20));
    booster = sf::RectangleShape(sf::Vector2f(20, 10));

    body.setFillColor(sf::Color::Transparent);
    body.setOutlineColor(sf::Color::Green);
    body.setOutlineThickness(2);
    body.setOrigin(sf::Vector2f(10, 10));
    body.setPosition(sf::Vector2f(100, 100));

    booster.setFillColor(sf::Color::Transparent);
    booster.setOutlineColor(sf::Color::Yellow);
    booster.setOutlineThickness(2);
    booster.setOrigin(sf::Vector2f(10, -12));
    booster.setPosition(sf::Vector2f(100, 100));
}

void Player::display(sf::RenderWindow *window)
{
    window->draw(body);
    if (z_button == true)
        window->draw(booster);
}

void Player::set_speed(void)
{
    if (z_button == true && s_button == true)
        return;
    if (z_button == true) {
        af += (af >= 10) ? 0 : 1;
    }
    if (s_button == true) {
        af -= (af <= -10) ? 0 : 1;
    }
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
    booster.setRotation(rotation);
    body.setRotation(rotation);
}
