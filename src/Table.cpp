//
// Created by Meevere on 5/5/2021.
//

#include "Table.h"
#include <cmath>

Table::Table() {
    CyclicArray<CyclicArray<int>> temp;
    cells = temp;
    size = 0;
}

Table::Table(int _size) {
    size = _size;
    CyclicArray<CyclicArray<int>> temp(size, CyclicArray<int>(size));
    cells = temp;
}


Table::Table(CyclicArray<CyclicArray<int>> &cells) {
    this->cells = cells;
    size = cells.get_size();
}

Table::Table(Table &table):Table(table.cells){}
Table& Table::operator=(const Table& other) {
    this->cells = other.cells;
    this->position = other.position;
    this->size = other.size;

    return *this;
}

Vector2f Table::getSize() const {
    auto temp = size*(CELL_SIZE+CELL_MARGIN);
    return Vector2f(temp,temp);
}

void Table::setPosition(Vector2f pos) {
    position = pos;
}

void Table::centerAt(Vector2f pos) {
    position = pos - getSize()/2.f;
}

void Table::draw(RenderTarget &target, RenderStates states) const {
    for( int i=0; i<cells.get_size(); i++ ) {
        for (int j = 0; j < cells[i].get_size(); j++) {
            draw_cell(target, Vector2i(i, j));
        }
    }
}

void Table::draw_cell(RenderTarget &target, sf::Vector2i index) const{
    Vector2f temp(CELL_SIZE, CELL_SIZE);
    sf::RectangleShape rect(temp);

    Vector2f real_position;
    real_position = position + Vector2f(index) * float(CELL_SIZE + CELL_MARGIN);
    rect.setPosition(real_position);

    switch (cells[index.x][index.y]) {
        case 0: rect.setFillColor(sf::Color::Green); break;
        case 1: rect.setFillColor(sf::Color::Red); break;
        default: rect.setFillColor(sf::Color::Cyan); break;
    }

    target.draw(rect);
}

void Table::map( int(*func)(int, int, int, CyclicArray<CyclicArray<int>>&) ){
    auto temp(cells);
    for( int i=0; i<cells.get_size(); i++){
        for( int j=0; j<cells.get_size(); j++){
             temp[i][j] = func(i,j,cells[i][j],cells);
        }
    }
    cells = temp;
}

int update1(int i, int j, int data, CyclicArray<CyclicArray<int>>& arr){
    if( data == 0 )
        return 1;
    return 0;
}

int update2(int i, int j, int data, CyclicArray<CyclicArray<int>>& cells){
    auto neighbors = 0;
    for( int _i=-1; _i<2; _i++){
        for( int _j=-1; _j<2; _j++){
            if( (_i != 0) or (_j != 0) )
                neighbors += cells[i+_i][j+_j];
        }
    }

    if(neighbors == 2)
        return data;
    if(neighbors == 3)
        return 1;
    return 0;
}


void Table::update() {
    map(update2);
}

Vector2i Table::getClickedCell(Vector2f pos) {
    // get position at the left-top corner of the table
    Vector2f pos_at_corner = pos - position;
    return Vector2i(floor(pos_at_corner.x/float(CELL_SIZE+CELL_MARGIN)),floor(pos_at_corner.y/float(CELL_SIZE+CELL_MARGIN)));
}

void Table::click(Vector2f pos) {
    auto index = getClickedCell(pos);
    cells[index.x][index.y] = (cells[index.x][index.y] + 1)%2;
}

Table::Table(std::string &filename) {
    std::fstream fs;
    fs.open(filename, std::fstream::out);

    size = 0;
    fs >> size;
    cells = CyclicArray<CyclicArray<int>>(size);

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            fs >> cells[i][j];
        }
    }

    fs.close();
}

void Table::save(std::string &filename) {
    std::fstream fs;
    fs.open(filename, std::fstream::in);

    fs << size << '\n';
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            fs << cells[i][j] << ' ';
        }
        fs << '\n';
    }
    fs.close();
}
