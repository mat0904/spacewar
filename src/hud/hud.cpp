#include "../../include/prototype.hpp"

Hud::Hud(void)
{
    font = sf::Font();
    if (!font.loadFromFile("./assets/FFFFORWA.TTF"))
        printf("Error\n");
    info = sf::Text();
    info.setPosition(sf::Vector2f(0, 0));
    info.setCharacterSize(24);
    info.setFont(this->font);
    return;
}

void Hud::update(float angle_input, sf::Vector2f mv, sf::View *view)
{
    sf::Vector2f corner = view->getCenter();
    corner.x -= (view->getSize().x / 2);
    corner.y -= (view->getSize().y / 2);
    info.setPosition(corner);
    float speed = sqrt(pow(mv.x, 2) + pow(mv.y, 2));

    std::string info_string = "Angle: " + to_string(angle_input) +
        "\nSpeed: " + to_string(speed) + "\nX: " + to_string(mv.x) +
        "\nY: " + to_string(mv.y);

    info.setString(info_string);
    radar.update(angle_input, view);
}

void Hud::display(sf::RenderWindow *window)
{
    window->draw(info);
    radar.display(window);
}
