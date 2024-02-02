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

            Prim p(s-1);

            // debut chrono
            List<List<int>> result = p.PrimL(gp);
            // fin chrono

            int index = 1;

            for( List<int> l : result ){
                for( int& x : l ){
                    std::cout << x << "->" << ( index == s ) ? "_" : index << ":" << l.getPriorityElement(x) << std::endl;  
                };
                index++;
            };

            // print chrono

        } else if( argc == 4 ){

            

            std::string filename(argv[3]);

            Prim p(s-1);

            List<List<int>> result = p.PrimL(gp);

            // ecriture dans le fichier

        }
    }
   

    return 0;
}