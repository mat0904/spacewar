#include "../../include/prototype.hpp"

Ship::Ship(void)
{
    move_vector = sf::Vector2f(0, 0);
    angle = 0;

    body = sf::RectangleShape(sf::Vector2f(20, 20));
    booster = sf::RectangleShape(sf::Vector2f(10, 20));
    left_booster = sf::RectangleShape(sf::Vector2f(5, 5));
    right_booster = sf::RectangleShape(sf::Vector2f(5, 5));

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

    left_booster.setFillColor(sf::Color::Yellow);
    left_booster.setOutlineThickness(0);
    left_booster.setOrigin(sf::Vector2f(-7, 17));
    left_booster.setPosition(sf::Vector2f(100, 100));

    right_booster.setFillColor(sf::Color::Yellow);
    right_booster.setOutlineThickness(0);
    right_booster.setOrigin(sf::Vector2f(-7, -12));
    right_booster.setPosition(sf::Vector2f(100, 100));
}

void Ship::rotate(void)
{
    booster.setRotation(angle);
    left_booster.setRotation(angle);
    right_booster.setRotation(angle);
    body.setRotation(angle);
}

void Ship::move(void)
{
    booster.move(move_vector);
    left_booster.move(move_vector);
    right_booster.move(move_vector);
    body.move(move_vector);
}

void Ship::set_position(sf::Vector2f position)
{
    booster.setPosition(position);
    left_booster.setPosition(position);
    right_booster.setPosition(position);
    body.setPosition(position);
}

void Ship::display(sf::RenderWindow *window, Player *player)
{
    window->draw(body);
    if (player->z_button == true)
        window->draw(booster);
    if (player->q_button == true)
        window->draw(right_booster);
    if (player->d_button == true)
        window->draw(left_booster);
}
