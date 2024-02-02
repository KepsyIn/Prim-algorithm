#include <iostream>
#include "Prim.h"
#include "chrono.h"

int main(int argc, char *argv[]) {

    if( argc > 2 ){

        GraphParser gp(argv[1]);

        gp.parseToList();

        int s = std::stoi(argv[2]);

        chrono chrono;
        
        if( argc == 3 ){

            Prim p(s);

            // debut chrono
            chrono.start();
            List<List<int>> result = p.PrimL(gp);
            chrono.stop();
            // fin chrono

            int index = 1;
            int coutTotal = 0;
            std::cout << (( p.getConnex() ? "GRAPHE CONNEXE " : "GRAPHE PAS CONNEXE " )) << std::endl;

            for( List<int> l : result ){
                if( !l.isEmpty() ){
                    int x = l[0];
                    int cout = l.getPriorityElement(x);
                    coutTotal += cout;
                    std::cout << "sommet : " << index << " -> " << x << " : " << cout << std::endl;
                } else {
                    std::cout << "sommet : " << index << " -> __ : __" << std::endl;
                }
                index++;
            }
            std::cout <<"Coût total : " << coutTotal << std::endl;
            std::cout << "temps CPU : " << chrono.getTime() << std::endl;

        } else if( argc == 4 ){
            std::string filename(argv[3]);
            Prim p(s);
            List<List<int>> result = p.PrimL(gp);

            // Writing to the specified file
            std::ofstream outputFile(filename);
            if (outputFile.is_open()) {
                int index = 1;
                int coutTotal = 0;
                outputFile << ((p.getConnex() ? "GRAPHE CONNEXE " : "GRAPHE PAS CONNEXE ")) << std::endl;

                for (List<int> l : result) {
                    if (!l.isEmpty()) {
                        int x = l[0];
                        int cout = l.getPriorityElement(x);
                        coutTotal += cout;
                        outputFile << "sommet : " << index << " -> " << x << " : " << cout << std::endl;
                    } else {
                        outputFile << "sommet : " << index << " -> __ : __" << std::endl;
                    }
                    index++;
                }
                outputFile << "Coût total : " << coutTotal << std::endl;
                outputFile << "temps CPU : " << chrono.getTime() << std::endl;

                outputFile.close();
                std::cout << "Output written to file: " << filename << std::endl;
            } else {
                std::cerr << "Error: Unable to open file for writing: " << filename << std::endl;
                return 1;
            }
        }
    }

    return 0;
}