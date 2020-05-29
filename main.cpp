#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

sf::Font font;
sf::Text textX, textY;
sf::CircleShape circle(10.f);

sf::Vector2f location = sf::Vector2f(50, -200), velocity = sf::Vector2f(1, -1);

void update()
{
    location += velocity;
    cout << location.x << endl;
}


void draw(sf::RenderWindow& window)
{
    sf::Vector2i pixel_position = sf::Mouse::getPosition(window);
    sf::Vector2f mouse_position = window.mapPixelToCoords(pixel_position);

    sf::Vertex vertical[] = {sf::Vertex(sf::Vector2f(mouse_position.x, mouse_position.y-10)), sf::Vertex(sf::Vector2f(mouse_position.x, mouse_position.y+10))};
    sf::Vertex horizontal[] = {sf::Vertex(sf::Vector2f(mouse_position.x-10, mouse_position.y)), sf::Vertex(sf::Vector2f(mouse_position.x+10, mouse_position.y))};

    textX.setPosition(sf::Vector2f(mouse_position.x + 15, mouse_position.y + 10));
    textY.setPosition(sf::Vector2f(mouse_position.x + 15, mouse_position.y + 25));

    textX.setString("X: " + std::to_string(static_cast<int>(mouse_position.x)));
    textY.setString("Y: " + std::to_string(static_cast<int>(mouse_position.y)));

    circle.setFillColor(sf::Color(100, 250, 50));
    circle.setPosition(location);

    window.draw(vertical, 2, sf::Lines);
    window.draw(horizontal, 2, sf::Lines);
    window.draw(textX);
    window.draw(textY);
    window.draw(circle);
}

int main()
{
    sf::err().rdbuf(NULL);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Opa");
    sf::View view(sf::Vector2f(WIDTH/2, -HEIGHT/2), sf::Vector2f(WIDTH, HEIGHT));

    window.setView(view);

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;
    }

    textX.setFont(font);
    textY.setFont(font);

    textX.setCharacterSize(12);
    textY.setCharacterSize(12);

    textX.setFillColor(sf::Color::White);
    textY.setFillColor(sf::Color::White);

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
        update();
        draw(window);
        window.display();
    }
}
