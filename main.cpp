#include "mainwindow.h"
#include <QApplication>
#include  "elements.h"
#include <time.h>
#include <SFML/Graphics.hpp>
#include <arena.h>
int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    Arena* ar = new Arena(10,10,&window);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    int i = 0;
    while (window.isOpen())
    {
    sf::Event event;
    while (window.pollEvent(event) ||
           (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        if (event.type == sf::Event::Closed)
        window.close();
    }
    ar->timer();

    ar->draw();

   // window.clear();
    //window.draw(shape);
    //window.display();
    }

    return 0;


    /*QApplication a(argc, argv);
    MainWindow win;
    win.show();
    Player *p = new Player();   
    return a.exec();
    */
}
