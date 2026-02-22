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
    void computeAdj();
public:
    GraphParser(const std::string& filename) : filename(filename) , degree(0) {};
    void parseToList();
    void parseToMat();
    List<List<int>> getAdj() const;
    const matrice& getMat() const;
    int getDegree() const;
};