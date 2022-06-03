#include "ant.hpp"

Ant::Ant() : Ant(0, 0) {}

Ant::Ant(unsigned int x, unsigned int y) : Ant(sf::Vector2u(x, y)) {}

Ant::Ant(sf::Vector2u pos) : _pos(pos), _dir(Direction::LEFT) {}

void Ant::rotate(sf::Color color)
{
    if (color == sf::Color::White)
        _dir = static_cast<Direction>((static_cast<int>(_dir) + 1) % 4);
    else
        _dir = static_cast<Direction>((static_cast<int>(_dir) + 3) % 4);
}

void Ant::proceed()
{
    switch (_dir)
    {
    case Direction::LEFT:
        _pos.x -= 1;
        break;
    case Direction::RIGHT:
        _pos.x += 1;
        break;
    case Direction::UP:
        _pos.y -= 1;
        break;
    case Direction::DOWN:
        _pos.y += 1;
        break;
    default:
        break;
    }

    if (_pos.x == 100)
        _pos.x = 0;
    if ((int)_pos.x == -1)
        _pos.x = 99;
    if (_pos.y == 100)
        _pos.y = 0;
    if ((int)_pos.y == -1)
        _pos.y = 99;
}

void Ant::move(Grid &grid)
{
    rotate(grid.getColor(_pos));
    grid.toggle(_pos);
    proceed();
}