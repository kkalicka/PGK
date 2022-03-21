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
        trianglesFan[1].position = sf::Vector2f(500, 300);  //
        trianglesFan[1].color =  sf::Color(0,56,0);

        x = 141.4;
        y = 441.4;

        trianglesFan[2].position = sf::Vector2f(y, y);
        trianglesFan[2].color = sf::Color(0,113,0);

        trianglesFan[3].position = sf::Vector2f(300, 500); //
        trianglesFan[3].color =  sf::Color(0,169,0);

        trianglesFan[4].position = sf::Vector2f(300-x, y);
        trianglesFan[4].color =  sf::Color(0 ,225, 0);

        trianglesFan[5].position = sf::Vector2f(100, 300); //
        trianglesFan[5].color =  sf::Color(0,255,0);

        trianglesFan[6].position = sf::Vector2f(300-x, 300-x); 
        trianglesFan[6].color =  sf::Color(187,125,0);

        trianglesFan[7].position = sf::Vector2f(300, 100);
        trianglesFan[7].color =  sf::Color(255,0,0);

        trianglesFan[8].position = sf::Vector2f(y, 300-x); //
        trianglesFan[8].color =  sf::Color(125,0,0);
            
        trianglesFan[N-1].position = sf::Vector2f(500, 300);
        trianglesFan[N-1].color =  sf::Color(125,0,0);
            
        window.draw(trianglesFan);

        /*
        line[0].color = sf::Color::Red;
        line[0].position = sf::Vector2f(300,300);

        line[1].color = sf::Color::Green;
        line[2].position = sf::Vector2f(500,500);
        window.draw(line, 2, sf::Lines); */
/*
        for (int i = 0; i<20; i++)
        {
            line[0].color = sf::Color::Red;
            line[0].position = sf::Vector2f(300,300);

            line[1].color = sf::Color::Green;
            line[2].position = sf::Vector2f(200*sin(i),200*cos(i));
            window.draw(line, 2, sf::Lines);
        }
*/
        /* działa: zielone kółko
        sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
        for(int i=255; i>0; i--)
        {
            line.rotate((1/2)*45.f);
            line.setPosition(x_pos, y_pos);
            line.setFillColor(sf::Color(0,i,0)); 
            line.rotate(1.411);
            window.draw(line);
        }
        */
        /*
        int size =3;
        sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
        for (int j=0; j<255; j++)
        {
        if(j>125)
            size =10;
        line.setSize(sf::Vector2f(1+j, size));
        for(int i=255; i>0; i--)
        {
            line.rotate((1/2)*45.f);
            line.setPosition(x_pos, y_pos);
            line.setFillColor(sf::Color(j,i,0)); 
            line.rotate(1.411);
            window.draw(line);
        }
        }*/
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