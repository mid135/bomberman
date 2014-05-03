#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <QObject>
using namespace std;

class Element: public virtual QObject {
Q_OBJECT
public:
    Element();
    virtual void draw(size_t) = 0;
    size_t get_x() {return x_;}
    size_t get_y() {return y_;}
    size_t get_hight() {return hight_;}
    size_t get_width() {return width_;}
    size_t get_direction() {return direction_;}
    float get_speed() {return speed_;}
    float get_acceleration() {return acceleration_;}
    bool move(size_t,size_t);//принимает на сколько он должен сдвинуться и куда

protected:
    void set_x(size_t x) { x_ = x;}
    void set_y(size_t y) { y_ = y;;}
    void set_hight(size_t h) { hight_ = h;}
    void set_width(size_t w) { width_ = w;}
    void set_direction(size_t d) { direction_ = d;}
    void set_speed(float s) { speed_ = s;}
    void set_acceleration(float a) { acceleration_ = a;}
private:
    size_t x_;//нижнее подчеркивание указывает на приватность - да, это обязательно.
    size_t y_;
    size_t hight_;
    size_t width_;
    float speed_;
    float acceleration_;
    size_t direction_;
    void purge();//эта функция должна удалить рисовку объекта

};


/*
class Bomb:Element {
private:
    size_t liveTime;
    size_t power;
    void explode();//пока непонятно, толи эта функция сама будет изменять поле, толи генерировать событие
};

class Bonus:Element {
public:
    Bonus();//непонятно, надо продумать над структурой бонуса
private:
    size_t bonusType_;
};

class Explosion:Element {
public:
    Explosion(size_t liveTime) {liveTime_ = liveTime;}
private:
    size_t liveTime_;
};
*/
class Player:public Element {
    Q_OBJECT
public:
    Player();
    string name;
public slots:
    virtual void timer() = 0;//эта функция по идее должна обрабатывать собыите перехлода на следующий квант времени
};

#endif // ELEMENTS_H
