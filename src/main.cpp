#include "matrice/matrice.h"
#include "Liste/Liste.h"

int main() {
    Matrice mat(3, 3);
    mat.init(0, 5, 42);
    mat.print();

    return 0;
}