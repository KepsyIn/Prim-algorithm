#include <iostream>
#include "GraphParser.h"

int main(int argc, char *argv[]) {


    List<int> p;

    p.add(1,10);
    p.add(2,40);
    p.add(3,25);
    p.add(4,50);
    p.add(5,5);
    p.add(6,55);

    int head = p.pop();

    std::cout << head << std::endl;
    
    p.printList();
    // GraphParser gp(argv[1]);

    // gp.parseToList();
    // gp.parseToMat();

    
    //matrice temp = gp.getMat();
    //temp.print();
    
    // std::cout << "-degree : " << gp.getDegree() << std::endl;
    // for( List<int> l : gp.getAdj() ){
    //     std::cout << "-sommet : ";
    //     l.printList();
    // }

    return 0;
}