#include <SFML/Graphics.hpp>
#include <vector>

class Grid
{
public:
    Grid(unsigned int size, unsigned int cell_size) : _grid(size, std::vector<bool>(size, false)), _cell_size(cell_size) {}

    // draw the grid
    void draw(sf::RenderWindow &window) const;
    // toggle cell color at position (x,y)
    void toggle(unsigned int x, unsigned int y);
    // get color of the cell
    bool getColor(unsigned int x, unsigned int y) const;

protected:
    std::vector<std::vector<bool>> _grid;
    unsigned int _cell_size;
};

void Grid::draw(sf::RenderWindow &window) const
{
    sf::RectangleShape rec(sf::Vector2f(_cell_size, _cell_size));

    rec.setFillColor(sf::Color::Black);
    for (std::size_t i = 0; i < _grid.size(); ++i)
    {
        for (std::size_t j = 0; j < _grid[i].size(); ++j)
        {
            if (_grid[i][j])
            {
                rec.setPosition(i * _cell_size, j * _cell_size);
                window.draw(rec);
            }
        }
    }
}

void Grid::toggle(unsigned int x, unsigned int y)
{
    _grid[x][y] = !_grid[x][y];
}

bool Grid::getColor(unsigned int x, unsigned int y) const
{
    return _grid[x][y];
}

int main()
{
    const int grid_size{400};
    const float cell_size{4.f};

    Grid grid(grid_size / cell_size, cell_size);

    sf::RenderWindow window(sf::VideoMode(grid_size, grid_size), "Langton's ant");

    grid.toggle(0, 0);
    grid.toggle(2, 0);
    grid.toggle(2, 2);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        grid.draw(window);
        window.display();
    }

    return 0;
}