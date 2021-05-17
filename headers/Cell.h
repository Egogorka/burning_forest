//
// Created by Meevere on 5/17/2021.
//

#ifndef BURNING_FOREST_CELL_H
#define BURNING_FOREST_CELL_H

struct Cell{
public:
    int state;
    int x;
    int y;

    Cell(int _x, int _y, int _state){
        x = _x; y = _y; state = _state;
    };

    Cell(){
        x = y = state = 0;
    }
};

#endif //BURNING_FOREST_CELL_H
