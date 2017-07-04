#include <SFML/Graphics.hpp>
#include "include/apple.hpp"
#include "include/snake.hpp"

int main()
{
    const int init_size = 3;
    const int dot_size = 10;
    bool game_over = false;
    sf::Vector2f map_size{300, 300};
    sf::RenderWindow win{sf::VideoMode{map_size.x, map_size.y}, "snake", sf::Style::Close | sf::Style::Titlebar};
    Apple apple{dot_size, map_size};
    Snake snake{init_size, dot_size, map_size};
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/ariblk.ttf");
    sf::Text game_over_text;
    game_over_text.setFont(font);
    game_over_text.setCharacterSize(20);
    game_over_text.setString("game over");
    sf::Clock clock;
    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) win.close();
        }
        if (!game_over)
        {
            sf::Time elapsed = clock.restart();
            snake.check_apple(apple);
            if (snake.check_collision())
            {
                game_over = true;
            }
            snake.action();
            snake.move(elapsed);
            win.clear(sf::Color::Black);
            win.draw(apple.getShape());
            for (size_t i = 0; i < snake.getSnake().size(); ++i)
            {
                win.draw(snake.getSnake().at(i));
            }
            win.display();
        }
        else
        {
            win.clear(sf::Color::Black);
            win.draw(game_over_text);
            win.display();
        }
    }
}
