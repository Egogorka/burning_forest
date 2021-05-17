// Created by Meevere on 5/17/2021.
//

#include "Automaton.h"

Cell& Automaton::getAt(int x, int y) const{
    return map[x][y];
}

void Automaton::setAt(int x, int y, Cell &cell) {
    map[x][y] = cell;
}

void Automaton::setAt(Cell &cell) {
    map[cell.x][cell.y] = cell;
}

void Automaton::update(Rules rules) {
    Array<Array<Cell>> temp;
    rules.bind_automaton(*this);
    for(auto& sub_map : map)
        for(auto& cell : sub_map){
            temp[cell.x][cell.y].state = rules.new_state(cell);
        }

    for(auto& sub_map : map)
        for(auto& cell : sub_map){
            cell.state = temp[cell.x][cell.y].state;
        }
}

