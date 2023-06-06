#include "../../include/prototype.hpp"

Radar::Radar(void)
{
    background = sf::CircleShape(100);
    background.setFillColor(sf::Color(00, 88, 00, 255));
    background.setOutlineColor(sf::Color::Green);
    background.setOutlineThickness(2);
    lines = sf::VertexArray(sf::LinesStrip, 4);
    background.setOrigin(100, 100);
    direction = sf::CircleShape(2);
    direction.setFillColor(sf::Color::Yellow);
    direction.setOrigin(2, 2);
    reverse_direction = sf::CircleShape(2);
    reverse_direction.setFillColor(sf::Color::Blue);
    reverse_direction.setOrigin(2, 2);
}

sf::Vector2f Radar::get_circle_position(sf::Vector2f radar_pos, float angle,
    int distance)
{
    sf::Vector2f new_position;
    new_position.x = radar_pos.x + distance * cos((angle * (M_PI / 180)));
    new_position.y = radar_pos.y + distance * sin((angle * (M_PI / 180)));
    return new_position;
}

void Radar::update_direction(Ship *ship, sf::Vector2f radar_position)
{
    float angle = 0;
    angle = atan2(ship->move_vector.y, ship->move_vector.x) * (180 / M_PI);
    direction.setPosition(get_circle_position(radar_position, angle, 99));
    angle = atan2(0 - ship->move_vector.y, 0 - ship->move_vector.x) * (180 / M_PI);
    reverse_direction.setPosition(get_circle_position(radar_position, angle, 99));
}

void Radar::update(Ship *ship, sf::View *view)
{
    sf::Vector2f middle = view->getCenter();
    sf::Vector2f size = view->getSize();
    sf::Vector2f position = sf::Vector2f(middle.x, middle.y + size.y / 2 - 150);
    background.setPosition(position);
    lines[0].position = position;
    lines[1].position = this->get_circle_position(position, ship->angle, 100);
    lines[2].position = sf::Vector2f(position.x, position.y - 100);
    lines[3].position = sf::Vector2f(position);
    this->update_direction(ship, position);
}

void Radar::display(sf::RenderWindow *window)
{
    window->draw(background);
    window->draw(direction);
    window->draw(reverse_direction);
    window->draw(lines);
}
