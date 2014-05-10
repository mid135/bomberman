
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <arena.h>
#include <SFML/Graphics.hpp>


Arena::Arena(size_t a, size_t b,sf::RenderWindow* win) {
    //HERE MUST BE A FUNCTION TO DOWNLOAD STATIC ELEMENTS AND MAP PARAMETERS FROM FILE
    this->hight = a;
    this->width = b;
    this->win = win;
    sf::Color c;
    Player* p = new Player(win,"dima",50,50);
    this->player.push_back(*p);
    this->staticElementArray = new sf::RectangleShape[100];
    for (size_t i = 0; i < 100; ++i) {
        if (i % 7 == 0) {
            c = sf::Color::Red;
        } else {
           c = sf::Color::Blue;
        }
        sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(10, 10));
        s->setPosition((i % 10) * 10, (i / 10) * 10);
        s->setFillColor(c);
        this->staticElementArray[i] = *s;
    }
    //THIS ARRAY DECLARATION IS TEMPORARY
}

void Arena::draw() {
    this->win->clear();

    //draw statics
    for (size_t i = 0; i < (this->hight * this->width); ++i) {
        this->win->draw(this->staticElementArray[i]);
    }

    //draw dynamics

    for (size_t i = 0; i < this->player.size(); ++i) {
        this->player[i].draw(0);
    }

    //finaly display

    this->win->display();
}

void Arena::timer() {
    for (size_t i = 0; i < this->player.size(); ++i) {
        this->player[i].timer();
    }
}
