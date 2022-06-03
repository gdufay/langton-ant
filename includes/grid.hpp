#ifndef GRID_HPP
#define GRID_HPP

#include <SFML/Graphics.hpp>

class Grid : public sf::Drawable, public sf::Transformable
{
public:
    Grid(unsigned int width, unsigned int height, sf::Vector2u cellSize);

    // toggle cell color at position (i,j)
    void toggle(unsigned int i, unsigned int j);
    // get color of the cell
    sf::Color getColor(unsigned int i, unsigned int j) const;

private:
    // draw the grid
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::VertexArray _cells;
    unsigned int _width;
    unsigned int _height;
};

#endif