//
// Created by Meevere on 5/18/2021.
//

#include "AutomatonView.h"

AutomatonView::AutomatonView(Automaton &_automaton) {
    automaton = &_automaton;
}

void AutomatonView::bind(Automaton &_automaton) {
    automaton = &_automaton;
}

void AutomatonView::draw_cell(RenderTarget &target, Vector2i index) const {
    Vector2f temp(CELL_SIZE, CELL_SIZE);
    sf::RectangleShape rect(temp);

    Vector2f real_position;
    real_position = position + Vector2f(index) * float(CELL_SIZE + CELL_MARGIN);
    rect.setPosition(real_position);

    switch (automaton->getAt(index.x,index.y).state) {
        case 0: rect.setFillColor(sf::Color::Green); break;
        case 1: rect.setFillColor(sf::Color::Red); break;
        default: rect.setFillColor(sf::Color::Cyan); break;
    }

    target.draw(rect);
}

void AutomatonView::draw(RenderTarget &target, sf::RenderStates states) const {
    for( auto& sub_map : automaton->map ) {
        for (auto& cell : sub_map) {
            draw_cell(target, Vector2i(cell.x, cell.y));
        }
    }
}

void AutomatonView::setPosition(Vector2f pos) {
    position = pos;
}

void AutomatonView::centerAt(Vector2f pos) {
    position = pos - getSize()/2.f;
}

Vector2f AutomatonView::getSize() const {
    auto temp = automaton->map.get_size()*(CELL_SIZE+CELL_MARGIN);
    return Vector2f(temp,temp);
}


