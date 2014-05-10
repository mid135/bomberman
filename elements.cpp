
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "elements.h"

Element::Element(sf::RenderWindow *win_) {
    this->win = win_;
}

Player::Player(sf::RenderWindow *win_, string name_, size_t x_, size_t y_):Element(win_) {
    this->name = name_;
    this->x = x_;
    this->y = y_;
    this->image = new sf::RectangleShape(sf::Vector2f(10,10));
    this->image->setPosition(sf::Vector2f(x_,y_));
    this->image->setFillColor(sf::Color::Green);

}

void Player::timer() {
    //keypress handler
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true) {
        this->y -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true) {
        this->y += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true) {
        this->x += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true) {
        this->x -= 1;
    }
    this->image->setPosition(sf::Vector2f(this->x,this->y));
}

void Player::purge() {

}


void Player::draw(size_t param) {

    this->win->draw(*this->image);
}

bool Player::move(size_t a, size_t b) {
    return true;
}

/*
void Bomb::purge() {

}



void Bomb::draw(size_t param) {

}

bool Bomb::move(size_t a, size_t b) {
    return true;
}

void Explosion::purge() {

}



void Explosion::draw(size_t param) {

}

bool Explosion::move(size_t a, size_t b) {
    return true;
}

void Bonus::purge() {

}


void Bonus::draw(size_t param) {

}

bool Bonus::move(size_t a, size_t b) {
    return true;
}
*/
