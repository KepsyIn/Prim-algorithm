#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Liste.h"
#include "matrice.h"

class GraphParser {
private:
    std::string filename;
    List<List<int>> adjList;
    int degree;
    matrice mat;
public:
    GraphParser(const std::string& filename) : filename(filename) {};
    void parseToList();
    void parseToMat();
    List<List<int>> getAdj() const;
    matrice getMat() const;
    int getDegree() const;
};