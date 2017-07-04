#include "snake.hpp"

Snake::Snake(int init_size, int pdot_size, sf::Vector2f& pmap) :
    dot_size(pdot_size),
    map(pmap),
    direction(Direction::up),
    Cooldown(sf::milliseconds(100))
{
    for (int i = 0; i < init_size; ++i)
    {
        snake.push_back(sf::CircleShape(dot_size / 2));
        if (i == 0) snake.back().setFillColor(sf::Color::Blue);
        else snake.back().setFillColor(sf::Color::Green);
        int x_temp = (map.x / 2);
        int y_temp = (map.y / 2) + (i * dot_size);
        snake.back().setPosition(x_temp, y_temp);
    }
}

void Snake::move(sf::Time& elapsed)
{
    Cooldown -= elapsed;
    if (Cooldown <= sf::Time::Zero)
    {
        for (int i = snake.size() - 1; i >= 1; --i)
        {
            if (i == 1)
            {
                snake.at(i).setPosition(snake.at(i - 1).getPosition().x, snake.at(i - 1).getPosition().y);
            }
            else snake.at(i) = snake.at(i - 1);
        }
        if (direction == Direction::up)
        {
            snake.front().move(0, -(dot_size));
        }
        else if (direction == Direction::down)
        {
            snake.front().move(0, dot_size);
        }
        else if (direction == Direction::left)
        {
            snake.front().move(-(dot_size), 0);
        }
        else if (direction == Direction::right)
        {
            snake.front().move(dot_size, 0);
        }
        Cooldown = sf::milliseconds(100);
    }
}

void Snake::check_apple(Apple& apple)
{
    if (snake.front().getGlobalBounds().intersects(apple.getShape().getGlobalBounds()))
    {
        snake.push_back(sf::CircleShape());
        apple.rellocate();
    }
}

bool Snake::check_collision()
{
    if ((snake.front().getPosition().x < 0) || (snake.front().getPosition().x >= map.x)) return true;
    else if ((snake.front().getPosition().y < 0) || (snake.front().getPosition().y >= map.y)) return true;
    for (int i = 1; i < snake.size(); ++i)
    {
        if (snake.front().getGlobalBounds().intersects(snake.at(i).getGlobalBounds())) return true;
    }
    return false;
}

void Snake::action()
{
    if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (direction != Direction::down) ) direction = Direction::up;
    else if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (direction != Direction::up)) direction = Direction::down;
    else if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (direction != Direction::right)) direction = Direction::left;
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (direction != Direction::left)) direction = Direction::right;
}

std::vector<sf::CircleShape>& Snake::getSnake()
{
    return snake;
}
