//
// Created by Meevere on 5/17/2021.
//

#include "Rules.h"

void Rules::bind_automaton(Automaton &automaton) {
    _automaton = &automaton;
}

void Rules::apply_to_neighbors(Cell& cell, const std::function<void(Cell,int)>& func ) {
    for( int i=-moore_size; i<=moore_size; i++){
        for( int j=-moore_size; j<=moore_size; j++){
            try {
                if( i==0 and j==0) continue;
                auto cur_cell = _automaton->getAt(cell.x+i,cell.y+j);
                int index = i+moore_size + (j+moore_size)*(2*moore_size+1);
                func(cur_cell, index);
            } catch (std::out_of_range &err) {}
        }
    }
}

int Rules::new_state(Cell &cell) {
    int weight = 0;
    auto that = this;
    apply_to_neighbors(cell, [&weight, &that](Cell _cell, int index){
        weight += that->weighter(_cell.state, index);
    });
    return processor(weight, cell.state);
}


