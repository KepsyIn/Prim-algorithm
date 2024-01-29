#include "matrice.h"
#include <iostream>

matrice::matrice(int l, int c) : lignes(l), col(c) {
    data = new int*[lignes];
    for(int i=0; i<lignes; i++){
        data[i] = new int[col];
    }
};

matrice::~matrice() {
    for (int i = 0; i < lignes; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

void matrice::init(int l, int c, int val){
    if(l <= lignes && c <= col){
        data[l][c] = val;
    }
}

void matrice::print() {
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}