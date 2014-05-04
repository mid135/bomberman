/*
 * arena.h
 *
 *  Created on: 25.04.2014
 *      Author: mid
 */

#ifndef ARENA_H_
#define ARENA_H_
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <QObject>

#include <elements.h>
class Arena : public QObject {
Q_OBJECT
public:
    Arena(size_t,size_t);//
    bool setElement(size_t,size_t,size_t);//принимает координаты и тип статического элемента.
    void draw();//функция перерисовыает все
private:
    size_t hight;
    size_t width;
    std::vector<Player> player;
    std::vector<Bomb> bomb;
    std::vector<Bonus> bonus;
    std::vector<Explosion> explosion;
    int* staticElementArray;//массив из статических элементов

};



#endif /* ARENA_H_ */
