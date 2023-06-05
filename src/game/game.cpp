#include "../../include/prototype.hpp"
#include <SFML/System/Vector2.hpp>

Game::Game()
{
    sf::VideoMode videomode = {1920, 1080, 32};
    window = new sf::RenderWindow(videomode, "spacewar", sf::Style::Default);
    window->setFramerateLimit(240);
    player = new Player();
    star = sf::CircleShape(10);
    star.setOrigin(sf::Vector2f(5, 5));
    star.setPosition(sf::Vector2f(500, 500));
    star.setFillColor(sf::Color::Yellow);
    star.setOutlineThickness(0);
}
