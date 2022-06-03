#include <SFML/Graphics.hpp>
#include <vector>

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

int main()
{
    const int grid_size{400};
    // const float cell_size{4.f};

    Grid grid(100, 100, sf::Vector2u(4, 4));

    sf::RenderWindow window(sf::VideoMode(grid_size, grid_size), "Langton's ant");

    grid.toggle(0, 0);
    grid.toggle(2, 0);
    grid.toggle(2, 2);
    grid.toggle(25, 25);
    grid.toggle(99, 99);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(grid);
        window.display();
    }

    return 0;
}