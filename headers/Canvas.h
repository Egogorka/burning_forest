//
// Created by Meevere on 5/5/2021.
//

#ifndef BURNING_FOREST_CANVAS_H
#define BURNING_FOREST_CANVAS_H

#include <SFML/Graphics.hpp>

class Canvas {
protected:
    sf::Drawable* drawables;
public:
    Canvas();
    ~Canvas();

};


#endif //BURNING_FOREST_CANVAS_H
