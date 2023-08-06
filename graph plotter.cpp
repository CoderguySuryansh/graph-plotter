#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Graph Plotter");

    // Sample data for plotting (y = x^2)
    vector<sf::Vector2f> points;
    for (float x = -10.0f; x <= 10.0f; x += 0.1f) {
        float y = x * x;
        points.push_back(sf::Vector2f(x, -y)); // Negate y to invert the graph (SFML's y-axis is inverted)
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // Draw x-axis and y-axis
        sf::Vertex x_axis[] = {sf::Vertex(sf::Vector2f(0, windowHeight / 2)), sf::Vertex(sf::Vector2f(windowWidth, windowHeight / 2))};
        sf::Vertex y_axis[] = {sf::Vertex(sf::Vector2f(windowWidth / 2, 0)), sf::Vertex(sf::Vector2f(windowWidth / 2, windowHeight))};
        window.draw(x_axis, 2, sf::Lines);
        window.draw(y_axis, 2, sf::Lines);

        // Draw the graph
        sf::VertexArray graph(sf::LineStrip);
        for (const sf::Vector2f& point : points) {
            graph.append(sf::Vertex(sf::Vector2f(windowWidth / 2 + point.x * 20, windowHeight / 2 + point.y * 20), sf::Color::Black));
        }
        window.draw(graph);

        window.display();
    }

    return 0;
}
