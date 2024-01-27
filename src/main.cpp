#include "matrice/matrice.h"

int main() {
    Matrice mat(3, 3);
    mat.init(0, 5, 42);
    mat.print();

    return 0;
}