#include <SFML/Graphics.hpp>
#include "grid.hpp"

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