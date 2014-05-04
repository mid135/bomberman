#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <QObject>
//#include <elements.cpp>
using namespace std;

class action_interface {
public:
    virtual void draw(size_t) = 0;
    virtual bool move(size_t,size_t) = 0;//принимает на сколько он должен сдвинуться и куда
    virtual void purge() = 0;//эта функция должна удалить рисовку объекта
};

class Element: public QObject {
Q_OBJECT
public:
    Element(){}

    size_t get_x() {return x_;}
    size_t get_y() {return y_;}
    size_t get_hight() {return hight_;}
    size_t get_width() {return width_;}
    size_t get_direction() {return direction_;}
    float get_speed() {return speed_;}
    float get_acceleration() {return acceleration_;}


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

};



class Bomb:public Element,public action_interface {
    Q_OBJECT
public:
    virtual void draw(size_t);
    virtual bool move(size_t a, size_t b);
    virtual void purge();
private:
    size_t liveTime;
    size_t power;
    void explode();//пока непонятно, толи эта функция сама будет изменять поле, толи генерировать
public slots:
    void timer();
};

class Bonus:public Element,public action_interface {
    Q_OBJECT
public:
    Bonus();//непонятно, надо продумать над структурой бонуса
    virtual void draw(size_t);
    virtual bool move(size_t a, size_t b);
    virtual void purge();
private:
    size_t bonusType_;
public slots:
    void timer();
};

class Explosion:public Element,public action_interface {
    Q_OBJECT
public:
    Explosion(size_t liveTime) {liveTime_ = liveTime;}
    virtual void draw(size_t);
    virtual bool move(size_t a, size_t b);
    virtual void purge();
private:
    size_t liveTime_;
public slots:
    void timer();

};

class Player:public Element,public action_interface {
Q_OBJECT
public:
    Player(){}
    string name;
    virtual void draw(size_t);
    virtual bool move(size_t a, size_t b);
    virtual void purge();
public slots:
    void timer();


};

#endif // ELEMENTS_H
