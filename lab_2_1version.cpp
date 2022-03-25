#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#define PI 3.14159265

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "2 laboratoria z Podstaw Grafiki koputerowej"); //1 szerokość, 2 wysokość
    sf::Clock clock;
    //ilość uruchomień programu na sekundę
    window.setFramerateLimit(60);
    sf::Time time = sf::Time::Zero;
    unsigned int FPS = 0 , frame_counter = 0;
    int x_pos = 300, y_pos = 300;
    int x, y;

    /*
    sf::Vertex line[]=
    {
        sf::Vertex(sf::Vector2f(45,100)), sf::Vertex(sf::Vector2f(200, 400))
    };*/

    //inicjalizacja 
    clock.restart().asMilliseconds();
    window.clear(sf::Color::White);
    while (window.isOpen())
    {
        sf::Event event;

    while (window.pollEvent(event))
    {
        // zdarzenia
        //rgb
        int N = 10;
        sf::VertexArray trianglesFan(sf:: TriangleFan, N);

        trianglesFan[0].position = sf::Vector2f(300, 300);
        trianglesFan[0].color =  sf::Color(0,0,0);

        for (int a = 1; a < N; a++)
        {
            x = 300 + sin(a*10*PI/180);
            y = 300 + cos(a*10*PI/180);
            trianglesFan[a].position = sf::Vector2f(x, y);
            trianglesFan[a].color =  sf::Color(0,56,0);
        }
            
        window.draw(trianglesFan);

    }
    //tu wyrysować wszystko na ekran
    
    //tu wypisać na ekran wartość FPS
    if (clock.getElapsedTime().asSeconds() >= 1.0f)
    {
    FPS = (unsigned int)((float)frame_counter / clock.getElapsedTime().asSeconds());
    clock.restart();
    frame_counter = 0;
    }
    frame_counter++;
    if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
        window.close();
    window.display();
    }
    return 0;
}

//make file