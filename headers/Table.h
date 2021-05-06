//
// Created by Meevere on 5/5/2021.
//

#ifndef BURNING_FOREST_TABLE_H
#define BURNING_FOREST_TABLE_H

#include <SFML/Graphics.hpp>
using sf::Vector2i, sf::Vector2f;
using sf::RenderTarget, sf::RenderStates;

#include "containers/cyclic_array.h"
using namespace containers;
using array::CyclicArray;

class Table : public sf::Drawable {
protected:
    CyclicArray<CyclicArray<int>> cells;

    int size;
    Vector2f position;

    const int CELL_SIZE = 30;
    const int CELL_MARGIN = 3;

    void draw_cell(RenderTarget &target, Vector2i index) const;

public:
    Table();
    explicit Table(int size);
    explicit Table(CyclicArray<CyclicArray<int>>& cells);

    [[nodiscard]] Vector2f getSize() const;

    void setPosition(Vector2f pos);
    void centerAt(Vector2f pos);

    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /**
     *
     * @param f - function of (i,j,data)
     */
    void map( int (*f)(int, int, int, CyclicArray<CyclicArray<int>>&) );
};


#endif //BURNING_FOREST_TABLE_H
