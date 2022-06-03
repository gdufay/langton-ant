#ifndef ANT_HPP
# define ANT_HPP

# include <SFML/Graphics.hpp>

# include "grid.hpp"

enum class Direction {
    LEFT,
    UP,
    RIGHT,
    DOWN,
};

class Ant
{
    public:
    Ant();
    Ant(unsigned int x, unsigned int y);
    Ant(sf::Vector2u pos);

    void rotate(sf::Color color);
    void proceed();
    void move(Grid &grid);

    public:
        sf::Vector2u _pos;
        enum Direction _dir;
};

#endif