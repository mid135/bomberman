#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

//#include <elements.cpp>
using namespace std;



class Element {

public:
    Element(sf::RenderWindow* win_);
    virtual void draw(size_t) = 0;
    virtual bool move(size_t,size_t) = 0;//принимает на сколько он должен сдвинуться и куда
    virtual void purge() = 0;//эта функция должна удалить рисовку объекта
    virtual void timer() = 0;
    size_t get_x() {return x;}
    size_t get_y() {return y;}
    size_t get_hight() {return hight;}
    size_t get_width() {return width;}
    size_t get_direction() {return direction;}
    float get_speed() {return speed;}
    float get_acceleration() {return acceleration;}


protected:
    void set_x(size_t x_) { x = x_;}
    void set_y(size_t y_) { y = y_;}
    void set_hight(size_t h_) { hight = h_;}
    void set_width(size_t w_) { width = w_;}
    void set_direction(size_t d_) { direction = d_;}
    void set_speed(float s_) { speed = s_;}
    void set_acceleration(float a_) { acceleration = a_;}
//private:
    size_t x;
    size_t y;
    size_t hight = 20;
    size_t width = 20;
    float speed;
    float acceleration;
    size_t direction;

    sf::RenderWindow* win;


};

/*

class Bomb:public Element,public action_interface {

public:
    virtual void draw(size_t);
    virtual bool move(size_t a, size_t b);
    virtual void purge();
private:
    size_t liveTime;
    size_t power;

    void explode();//пока непонятно, толи эта функция сама будет изменять поле, толи генерировать

};

class Bonus:public Element,public action_interface {

public:
    Bonus();//непонятно, надо продумать над структурой бонуса
    virtual void draw(size_t);
    virtual bool move(size_t a, size_t b);
    virtual void purge();
private:
    size_t bonusType_;

};

class Explosion:public Element,public action_interface {

public:
    Explosion(size_t liveTime) {liveTime_ = liveTime;}
    virtual void draw(size_t);
    virtual bool move(size_t a, size_t b);
    virtual void purge();
private:
    size_t liveTime_;


};*/

class Player:public Element {

public:
    Player(sf::RenderWindow* win_, string, size_t x_, size_t);
    sf::RectangleShape *image;
    string name;
    void draw(size_t);
    bool move(size_t a, size_t b);
    void purge();
    void timer();


};

#endif // ELEMENTS_H
