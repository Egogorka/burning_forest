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
    Array<Array<int>> temp(map.get_size(), Array<int>(map[0].get_size()));
    rules.bind_automaton(*this);
    for(auto& sub_map : map)
        for(auto& cell : sub_map){
            temp[cell.x][cell.y] = rules.new_state(cell);
        }

    for(auto& sub_map : map)
        for(auto& cell : sub_map){
            cell.state = temp[cell.x][cell.y];
        }
}

void Automaton::setFrom(Array<Array<int>> cells) {
    Array<Array<Cell>> temp(cells.get_size(), Array<Cell>(cells[0].get_size(), Cell(0,0,0)));
    map = temp;
    for (int i = 0; i < cells.get_size(); ++i) {
        for (int j = 0; j < cells[0].get_size(); ++j) {
            map[i][j] = Cell(i,j,cells[i][j]);
        }
    }
}

