#include <SFML/Graphics.hpp>

#include "grid.hpp"
#include "ant.hpp"

int main()
{
    const int grid_size{400};
    // const float cell_size{4.f};

    Grid grid(100, 100, sf::Vector2u(4, 4));
    Ant ant(50, 50);

    sf::RenderWindow window(sf::VideoMode(grid_size, grid_size), "Langton's ant");

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

        ant.move(grid);
    }

    return 0;
}