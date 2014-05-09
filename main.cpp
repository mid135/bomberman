#include "mainwindow.h"
#include <QApplication>
#include  "elements.h"
#include <time.h>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
    sf::Event event;
    while (window.pollEvent(event))
    {
    if (event.type == sf::Event::Closed)
    window.close();
    }

    window.clear();
    window.draw(shape);
    window.display();
    }

    return 0;


    /*QApplication a(argc, argv);
    MainWindow win;
    win.show();
    Player *p = new Player();   
    return a.exec();
    */
}
