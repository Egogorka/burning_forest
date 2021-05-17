//
// Created by Meevere on 5/17/2021.
//

#ifndef BURNING_FOREST_AUTOMATON_H
#define BURNING_FOREST_AUTOMATON_H

#include "containers/array.h"
#include "Cell.h"

class Rules;
#include "Rules.h"

using containers::array::Array;

class Automaton{
protected:
    Array<Array<Cell>> map;
public:
    [[nodiscard]] Cell& getAt(int x, int y) const;
    void setAt(int x, int y, Cell& cell);
    void setAt(Cell& cell);

    void update(Rules rules);
};

#endif //BURNING_FOREST_AUTOMATON_H
