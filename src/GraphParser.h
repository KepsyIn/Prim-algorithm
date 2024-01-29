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
public:
    GraphParser(const std::string& filename) : filename(filename) {};
    void parseToList();
    void parseToMat();
    List<List<int>> getAdj() const;
    int getDegree() const;
};