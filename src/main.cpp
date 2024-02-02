#include <iostream>
#include "Prim.h"

int main(int argc, char *argv[]) {

    if( argc > 2 ){

         GraphParser gp(argv[1]);

        gp.parseToList();

        int s = std::stoi(argv[2]);
        
        if( argc == 3 ){

            GraphParser gp(argv[1]);

            gp.parseToList();

            int s = std::stoi(argv[2]);

            Prim p(s);

            // debut chrono
            List<List<int>> result = p.PrimL(gp);
            // fin chrono

            int index = 1;
            for( List<int> l : result ){
                if( !l.isEmpty() ){
                    int x = l[0];
                    int cout = l.getPriorityElement(x);

                    std::cout << "sommet : " << index << " -> " << x << " : " << cout << std::endl;
                }else {
                    std::cout << "sommet : " << index << " : pas de pred " << std::endl;
                }

                //std::cout << "sommet : " << index << " -> " << x << " : " << l.getPriorityElement(x) << std::endl;
                index++;
                // for( int x : l ){
                //     int cout = result[index-1].getPriorityElement(x);
                //     std::cout << x << "->" << ((x == s) ? "_" : std::to_string(index)) << ":" << std::to_string(cout) << std::endl;  
                // };
            }
            

            // print chrono

        } else if( argc == 4 ){

            

            std::string filename(argv[3]);

            Prim p(s);

            List<List<int>> result = p.PrimL(gp);

            // ecriture dans le fichier

        }
    }
   

    return 0;
}