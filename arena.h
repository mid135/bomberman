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


#include <elements.h>
#include <coordinator.h>
#include <SFML/Graphics.hpp>

class Arena{

public:
    Arena(size_t,size_t,sf::RenderWindow*);//
    bool setElement(size_t,size_t,size_t);//принимает координаты и тип статического элемента.
    void draw();//функция перерисовыает все
    void timer();//функция призвана вызывать timer в всех подчиненных ей объектов. там провождится проверка нажатий на клавиши в том числе.
    //Coordinator coordinator;

    //add methods to create dynamic objects?
private:
    sf::RenderWindow* win;
    size_t hight;//in BLOCKS??
    size_t width;//in BLOCKS??
    std::vector<Player> player;
    //std::vector<Bomb> bomb;
    //std::vector<Bonus> bonus;
    //std::vector<Explosion> explosion;
    sf::RectangleShape* staticElementArray;//массив из статических элементов

};



#endif /* ARENA_H_ */
