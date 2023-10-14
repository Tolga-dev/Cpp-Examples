#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#define MS_PER_UPDATE 16 //m sec (1/(60 fps))

auto GetTime()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

    return now;
}

int main()
{

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    sf::Texture texture;
    if(!texture.loadFromFile("/home/xamblot/CLionProjects/CppExamplePractices/Pattern/Textures/Man.png"))
    {
        std::cout << " Could Not Found! " << std::endl;
        return 0;
    }

    sf::Sprite EnemySprite;
    EnemySprite.setTexture(texture);
    sf::Vector2f movement(0.f, 0.f);

    auto pre = GetTime();
    double lag = 0.0;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) movement.y += 1.f/10; //Here we should add 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) movement.y -= 1.f/10; //Here we should substract 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) movement.x -= 1.f/10;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) movement.x += 1.f/10;
        EnemySprite.setPosition(movement);


        // render
        window.clear();
        window.draw(EnemySprite);
        window.display();
    }

}