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
    angle.setPosition(sf::Vector2f(0, 0));
    angle.setCharacterSize(24);
    angle.setFont(font);
    return;
}

void Hud::update(float angle_input, float speed_input)
{
    speed.setString(to_string(speed_input));
    angle.setString(to_string(angle_input));
}

void Hud::display(sf::RenderWindow *window)
{
    return;
    window->draw(speed);
    window->draw(angle);
}
