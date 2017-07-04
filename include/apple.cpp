#include <cstdio>
#include <ctime>
#include <cmath>
#include "apple.hpp"

Apple::Apple(int pdot_size, sf::Vector2f& pmap) :
    dot_size(pdot_size),
    map(pmap)
{
    srand(time(0));
    shape.setRadius(dot_size / 2);
    shape.setFillColor(sf::Color::Red);
    int temp_x = dot_size * (rand()% (int) (map.x / dot_size));
    rand();
    int temp_y = dot_size * (rand()% (int) (map.y/ dot_size));
    shape.setPosition(temp_x, temp_y);
}

void Apple::rellocate()
{
    int temp_x = dot_size * (rand()% (int) (map.x / dot_size));
    rand();
    int temp_y = dot_size * (rand()% (int) (map.y/ dot_size));
    shape.setPosition(temp_x, temp_y);
}

sf::Shape& Apple::getShape()
{
    return shape;
}
