#include <iostream>
#include "GraphParser.h"

int main(int argc, char *argv[]) {

    GraphParser gp(argv[1]);

    gp.parse();

    std::cout << "-degree : " << gp.getDegree() << std::endl;

    for( List<int> l : gp.getAdj() ){
        std::cout << "-sommet : ";
        l.printList();
    }

    return 0;
}