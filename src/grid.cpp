#include "grid.hpp"

Grid::Grid(unsigned int width, unsigned int height, sf::Vector2u cellSize)
{
    _cells.setPrimitiveType(sf::Quads);
    _cells.resize(width * height * 4);

    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            sf::Vertex *quad = &_cells[(i + j * width) * 4];

            quad[0].position = sf::Vector2f(i * cellSize.x, j * cellSize.y);
            quad[1].position = sf::Vector2f((i + 1) * cellSize.x, j * cellSize.y);
            quad[2].position = sf::Vector2f((i + 1) * cellSize.x, (j + 1) * cellSize.y);
            quad[3].position = sf::Vector2f(i * cellSize.x, (j + 1) * cellSize.y);
        }

    _width = width;
    _height = height;
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    states.texture = NULL;

    target.draw(_cells, states);
}

void Grid::toggle(unsigned int i, unsigned int j)
{
    sf::Vertex *quad = &_cells[(i + j * _width) * 4];
    sf::Color new_color =
        quad[0].color == sf::Color::White ? sf::Color::Black : sf::Color::White;

    for (unsigned int i = 0; i < 4; ++i)
        quad[i].color = new_color;
}

sf::Color Grid::getColor(unsigned int i, unsigned int j) const
{
    return _cells[i + j * _width].color;
}