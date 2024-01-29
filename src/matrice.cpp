#include "matrice.h"
#include <iostream>

matrice::matrice(int s) : size(s) {
    data = new int*[size];
    for(int i=0; i<size; i++){
        data[i] = new int[size];
    }
    init();
};

matrice::~matrice() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

void matrice::setVal(int l, int c, int val){
    if(l <= size && c <= size){
        data[l][c] = val;
    }
}

void matrice::init(){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = 0;
        }
    }
}

void matrice::print() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}