#include <iostream>
#include "Prim.h"

int main(int argc, char *argv[]) {

    if( argc == 3 ){

        GraphParser gp(argv[1]);

        gp.parseToList();

        int s = std::stoi(argv[2]);

        Prim p(s-1); // ne pas oublier de faire -1 sur le sommet

        List<List<int>> result = p.PrimL(gp);

        // gp.parseToMat();

        
        // matrice temp = gp.getMat();
        // temp.print();
        
        // std::cout << "-degree : " << gp.getDegree() << std::endl;
        int counter = 1;

        std::cout << std::endl;
        
        for( List<int> l : result ){
            std::cout << "-sommet " << counter << " : ";
            l.printList();
            counter++;
        }

    }
   

    GraphParser gp(argv[1]);

    gp.parseToList();

    int s = std::stoi(argv[2]);

    Prim p(s); // ne pas oublier de faire -1 sur le sommet

    List<List<int>> result = p.PrimL(gp);

    

    for( List<int> l : gp.getAdj() ){
        std::cout << "-sommet : ";
        l.printList();
    }

    // gp.parseToMat();

    
    // matrice temp = gp.getMat();
    // temp.print();
    
    // std::cout << "-degree : " << gp.getDegree() << std::endl;
    int counter = 1;

    std::cout << std::endl;
    
    for( List<int> l : result ){
        std::cout << "-sommet " << counter << " : ";
        l.printList();
        counter++;
    }


    return 0;
}