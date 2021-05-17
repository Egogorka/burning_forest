//
// Created by Meevere on 5/17/2021.
//

#ifndef BURNING_FOREST_RULES_H
#define BURNING_FOREST_RULES_H

#include <functional>

class Automaton;
#include "Automaton.h"

class Rules{
protected:
    // Pointer to automaton it's assigned to
    Automaton* _automaton = nullptr;

    // size of Moore neighborhood (usually 2 or 1)
    int moore_size;

    // in general sense we need this kind of function
    //std::function<int(Array<Cell>&)> process;
    // but it's better to have at least some structure


    /**
     * Function that gets the weight of current neighbour depending on it's position
     * and state
     */
    std::function<int(int, int)>* weighter;


    /**
     * Function that returns the new state that depends on the sum of the weights
     */
    std::function<int(int)>* processor;


    /**
     * Function that applies other function to each cell
     * @param cell - current cell
     * @param f - function that takes the Cell and the index of it;
     */
    void apply_to_neighbors(Cell& cell, std::function<void(Cell, int)> func );

public:

    Rules( int _moore_size, std::function<int(int, int)> _weighter, std::function<int(int)> _processor){
        moore_size = _moore_size; weighter = &_weighter; processor = &_processor;
    }

    void bind_automaton(Automaton& automaton);

    // updating one cell, returns the next state of given cell
    int new_state(Cell& cell);
};

#endif //BURNING_FOREST_RULES_H
