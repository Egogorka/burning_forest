//
// Created by Meevere on 4/14/2021.
//

#ifndef MIPT2021_2SEM_CYCLIC_ARRAY_H
#define MIPT2021_2SEM_CYCLIC_ARRAY_H

#include "containers/array.h"

namespace containers::array {

    template <typename T>
    class CyclicArray: public Array<T>{
    public:
        using Array<T>::Array;

        T& operator [] (int i){
            if( this->_size == 0 )
                throw std::out_of_range("out of bounds");

            if( i < 0 ){
                i = this->_size-(-i)%this->_size;
            }
            return this->_arr[i % this->_size];
        }

        T operator [] (int i) const{
            if( this->_size == 0 )
                throw std::out_of_range("out of bounds");

            if( i < 0 ){
                i = this->_size-(-i)%this->_size;
            }
            return this->_arr[i % this->_size];
        }
    };

}

#endif //MIPT2021_2SEM_CYCLIC_ARRAY_H
