//
// Created by Meevere on 5/18/2021.
//

#ifndef BURNING_FOREST_AUTOMATONVIEW_H
#define BURNING_FOREST_AUTOMATONVIEW_H

#include "Automaton.h"

#include <SFML/Graphics.hpp>
using sf::Vector2i, sf::Vector2f;
using sf::RenderTarget, sf::RenderStates;

class AutomatonView: public sf::Drawable{
protected:
    Automaton* automaton = nullptr;

    Vector2f position;
    const int CELL_SIZE = 30;
    const int CELL_MARGIN = 3;

    void draw_cell(RenderTarget &target, Vector2i index) const;
//    Vector2i getClickedCell(Vector2f pos);


public:
    explicit AutomatonView(Automaton& _automaton);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    [[nodiscard]] Vector2f getSize() const;
    void setPosition(Vector2f pos);
    void centerAt(Vector2f pos);
//    void click(Vector2f pos);
};

#endif //BURNING_FOREST_AUTOMATONVIEW_H
