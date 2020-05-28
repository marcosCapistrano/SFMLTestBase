#include <SFML/Graphics.hpp>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

void draw(sf::RenderWindow& window)
{
    sf::Vertex vertical[] = {sf::Vertex(sf::Vector2f(0, 50)), sf::Vertex(sf::Vector2f(0, -50))};
    sf::Vertex horizontal[] = {sf::Vertex(sf::Vector2f(50, 0)), sf::Vertex(sf::Vector2f(-50, 0))};

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(100, 250, 50));

    sf::Vector2i pixel_position = sf::Mouse::getPosition(window);
    sf::Vector2f mouse_position = window.mapPixelToCoords(pixel_position);

    std::cout << "X: " << mouse_position.x;
    std::cout << " | Y: " << mouse_position.y << std::endl;


    window.draw(vertical, 2, sf::Lines);
    window.draw(horizontal, 2, sf::Lines);
    window.draw(shape);
}

int main()
{
    sf::err().rdbuf(NULL);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Opa");
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(WIDTH, HEIGHT));

    window.setView(view);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i pixel_position {event.mouseMove.x, event.mouseMove.y};
                sf::Vector2f mouse_position = window.mapPixelToCoords(pixel_position);

                //USA A CORDENADA DO MOUSE SE QUISER
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        draw(window);
        window.display();
    }
}
