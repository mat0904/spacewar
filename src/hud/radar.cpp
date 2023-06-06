#include "../../include/prototype.hpp"

Radar::Radar(void)
{
    background = sf::CircleShape(100);
    background.setFillColor(sf::Color(00, 88, 00, 255));
    background.setOutlineColor(sf::Color::Green);
    background.setOutlineThickness(2);
    lines = sf::VertexArray(sf::LinesStrip, 2);
    background.setOrigin(100, 100);
    balayeur_angle = 0;
    balayeur = sf::VertexArray(sf::LinesStrip, 2);
    balayeur[0].color = sf::Color::Green;
    balayeur[1].color = sf::Color::Green;

}

void Radar::update_balayeur(sf::View *view)
{
    sf::Vector2f middle = view->getCenter();
    sf::Vector2f size = view->getSize();
    sf::Vector2f position = sf::Vector2f(middle.x, middle.y + size.y / 2 - 150);
    balayeur[0].position = position;
    sf::Vector2f new_position;
    new_position.x = position.x + 100 * cos((balayeur_angle * (M_PI / 180)));
    new_position.y = position.y + 100 * sin((balayeur_angle * (M_PI / 180)));
    balayeur[1].position = new_position;

    balayeur_angle += 1;
    if (balayeur_angle == 360)
        balayeur_angle = 0;
}

void Radar::update(float rotation, sf::View *view)
{
    sf::Vector2f middle = view->getCenter();
    sf::Vector2f size = view->getSize();
    sf::Vector2f position = sf::Vector2f(middle.x, middle.y + size.y / 2 - 150);
    background.setPosition(position);
    lines[0].position = position;
    sf::Vector2f new_position;
    new_position.x = position.x + 100 * cos((rotation * (M_PI / 180)));
    new_position.y = position.y + 100 * sin((rotation * (M_PI / 180)));
    lines[1].position = new_position;
    this->update_balayeur(view);
}

void Radar::display(sf::RenderWindow *window)
{
    window->draw(background);
    window->draw(lines);
    window->draw(balayeur);
}
