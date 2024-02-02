// #include <iostream>
// #include "Prim.h"

// int main(int argc, char *argv[]) {


//     // List<int> p;

//     // p.add(1,10);
//     // p.add(2,40);
//     // p.add(3,25);
//     // p.add(4,50);
//     // p.add(5,5);
//     // p.add(6,55);

//     // std::cout << "[0] " << p[0] << std::endl;

//     // std::cout << "[5] " << p[5] << std::endl;

//     // p.printList();

//     // p.setPriorityElement(6,49);
//     // p.remove(6);
//     // p.printList();
//     // int head = p.pop();

//     // std::cout << head << std::endl;
//     // p.printList();
   

//     GraphParser gp(argv[1]);

//     gp.parseToList();

//     int s = std::stoi(argv[2]);

//     Prim p(s); // ne pas oublier de faire -1 sur le sommet

//     List<List<int>> result = p.PrimL(gp);

    

//     for( List<int> l : gp.getAdj() ){
//         std::cout << "-sommet : ";
//         l.printList();
//     }

//     // gp.parseToMat();

    
//     // matrice temp = gp.getMat();
//     // temp.print();
    
//     // std::cout << "-degree : " << gp.getDegree() << std::endl;
//     int counter = 1;

//     std::cout << std::endl;
    
//     for( List<int> l : result ){
//         std::cout << "-sommet " << counter << " : ";
//         l.printList();
//         counter++;
//     }


//     return 0;
// }