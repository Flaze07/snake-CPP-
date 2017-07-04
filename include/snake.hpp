#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include "apple.hpp"
#include <vector>

class Snake
{
private :
    std::vector<sf::CircleShape> snake;
    const int dot_size;
    const sf::Vector2f map;
    enum class Direction {up, down, left, right};
    Direction direction;
    sf::Time Cooldown;
public :
    Snake(int init_size, int pdot_size, sf::Vector2f& pmap);
    void move(sf::Time& elapsed);
    void action();
    void check_apple(Apple& apple);
    bool check_collision();
    std::vector<sf::CircleShape>& getSnake();
};

#endif // SNAKE_HPP_INCLUDED
