#include "../../include/prototype.hpp"

Game::Game()
{
    sf::VideoMode videomode = {1920, 1080, 32};
    window = new sf::RenderWindow(videomode, "spacewar", sf::Style::Default);
    window->setFramerateLimit(240);
    player = new Player();
    movement_clock = sf::Clock();
    this->create_background("./assets/bg.png");
}

void Game::create_background(std::string texture_path)
{
    sf::Texture texture;
    texture.loadFromFile(texture_path);
    pattern.create(10000, 10000);
    pattern.setActive(true);
    sf::Sprite sprite(texture);
    for (int x = 0; x < 10000; x += texture.getSize().x) {
        for (int y = 0; y < 10000; y += texture.getSize().y) {
            sprite.setPosition(x, y);
            pattern.draw(sprite);
        }
    }
    pattern.setActive(false);
    background = sf::Sprite(pattern.getTexture());
}

void Game::draw_background(void)
{
    sf::Vector2f position = player->ship.body.getPosition();

    sf::Vector2f start;
    start.x = position.x - ((int)position.x % 10000) - 10000;
    start.y = position.y - ((int)position.y % 10000) - 10000;
    sf::Vector2f tmp = start;
    for (int i = 0; i < 3; i++) {
        tmp.x = start.x;
        for (int j = 0; j < 3; j++) {
            background.setPosition(tmp);
            window->draw(background);
            tmp.x += 10000;
        }
        tmp.y += 10000;
    }
}
