#include "../../include/prototype.hpp"

Hud::Hud(void)
{
    font = sf::Font();
    if (!font.loadFromFile("./assets/FFFFORWA.TTF"))
        printf("Error\n");
    speed = sf::Text();
    speed.setPosition(sf::Vector2f(0, 0));
    speed.setCharacterSize(24);
    speed.setFont(this->font);

    angle = sf::Text();
    angle.setPosition(sf::Vector2f(0, 24));
    angle.setCharacterSize(24);
    angle.setFont(font);
    return;
}

void Hud::update(float angle_input, float speed_input, sf::View *view)
{
    sf::Vector2f corner = view->getCenter();
    corner.x -= (view->getSize().x / 2);
    corner.y -= (view->getSize().y / 2);
    speed.setPosition(corner);
    corner.y += 40;
    angle.setPosition(corner);
    speed.setString(to_string(speed_input));
    angle.setString(to_string(angle_input));
}

void Hud::display(sf::RenderWindow *window)
{
    window->draw(speed);
    window->draw(angle);
}
