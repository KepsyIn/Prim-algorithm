#include <iostream>
#include "Prim.h"
#include "chrono.h"

int main(int argc, char *argv[]) {
    if (argc > 2) {
        GraphParser gp(argv[1]);
        gp.parseToMat();
        int s = std::stoi(argv[2]);
        chrono chrono;

        if (argc == 3) {
            Prim p(s);
            chrono.start();
            int** result = p.PrimM(gp);
            chrono.stop();

            int index = 1;
            int coutTotal = 0;
            std::cout << ((p.getConnex() ? "GRAPHE CONNEXE " : "GRAPHE PAS CONNEXE ")) << std::endl;

            for (int i = 0; i < gp.getDegree(); i++) {
                if (result[i][0] != -1) {
                    int x = result[i][0];
                    int cout = result[i][1];
                    coutTotal += cout;
                    std::cout << "sommet : " << index << " -> " << x << " : " << cout << std::endl;
                } else {
                    std::cout << "sommet : " << index << " -> __ : __" << std::endl;
                }
                index++;
            }

            std::cout << "Coût total : " << coutTotal << std::endl;
            std::cout << "temps CPU : " << chrono.getTime() << std::endl;
            for (int i = 0; i < gp.getDegree(); i++) {
                delete[] result[i];
            }
            delete[] result;
        } else if (argc == 4) {
            std::string filename(argv[3]);
            Prim p(s);
            chrono.start();
            int** result = p.PrimM(gp);
            chrono.stop();
            std::ofstream outputFile(filename);
            if (outputFile.is_open()) {
                int index = 1;
                int coutTotal = 0;
                outputFile << ((p.getConnex() ? "GRAPHE CONNEXE " : "GRAPHE PAS CONNEXE ")) << std::endl;
                for (int i = 0; i < gp.getDegree(); i++) {
                    if (result[i][0] != -1) {
                        int x = result[i][0];
                        int cout = result[i][1];
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
                std::cout << "Sortie écrite dans le fichier : " << filename << std::endl;
            } else {
                std::cerr << "Error: Unable to open file for writing: " << filename << std::endl;
                return 1;
            }
            for (int i = 0; i < gp.getDegree(); i++) {
                delete[] result[i];
            }
            delete[] result;
        }
    }

    return 0;
}