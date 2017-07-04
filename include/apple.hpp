#ifndef APPLE_HPP_INCLUDED
#define APPLE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Apple
{
private :
    sf::CircleShape shape;
    const int dot_size;
    const sf::Vector2f map;
public :
    Apple(int dot_size, sf::Vector2f& map);
    void rellocate();
    sf::Shape& getShape();
};

#endif // APPLE_HPP_INCLUDED
