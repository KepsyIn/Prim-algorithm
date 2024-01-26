#pragma once

class Matrice {
    private:
        int **data;
        int lignes;
        int col;
    public:
        Matrice(int l, int c);
        ~Matrice();
        void init();
        void print();
        
};