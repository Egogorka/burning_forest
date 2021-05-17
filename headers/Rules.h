//
// Created by Meevere on 5/17/2021.
//

#ifndef BURNING_FOREST_RULES_H
#define BURNING_FOREST_RULES_H

#include <functional>
#include <utility>

class Automaton;
#include "Automaton.h"

class Rules{
protected:
    // Pointer to automaton it's assigned to
    Automaton* _automaton = nullptr;

    // size of Moore neighborhood (usually 2 or 1)
    int moore_size = 1;

    // in general sense we need this kind of function
    //std::function<int(Array<Cell>&)> process;
    // but it's better to have at least some structure


    /**
     * Function that gets the weight of current neighbour depending on it's position
     * and state: weighter(int state, int index)
     */
    std::function<int(int, int)> weighter;


    /**
     * Function that returns the new state that depends on the sum of the weights and current state:
     * processor(int weights, int state);
     */
    std::function<int(int, int)> processor;


    /**
     * Function that applies other function to each cell
     * @param cell - current cell
     * @param f - function that takes the Cell and the index of it;
     */
    void apply_to_neighbors(Cell& cell, const std::function<void(Cell,int)>& func );

public:

    Rules() = default;
    void set_processor(const std::function<int(int, int)>& _processor){
        processor = _processor;
    }
    void set_weighter(const std::function<int(int, int)>& _weighter){
        weighter = _weighter;
    }

    Rules( int _moore_size, const std::function<int(int, int)>& _weighter, const std::function<int(int, int)>& _processor){
        moore_size = _moore_size;
        set_processor(_processor); set_weighter(_weighter);
    }

    void bind_automaton(Automaton& automaton);

    // updating one cell, returns the next state of given cell
    int new_state(Cell& cell);
};

#endif //BURNING_FOREST_RULES_H
