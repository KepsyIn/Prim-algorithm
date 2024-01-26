#include "matrice.h"
#include <iostream>

Matrice::Matrice(int l, int c) : lignes(l), col(c) {
    data = new int*[lignes];
    for(int i=0; i<lignes; i++){
        data[i] = new int[col];
    }
};

Matrice::~Matrice() {
    for (int i = 0; i < lignes; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

void Matrice::afficher() {
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}