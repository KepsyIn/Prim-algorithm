#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../Liste/Liste.h"

class GraphParser {
private:
    std::string filename;
    std::ifstream fileStream;
    List<List<int>> adjList;
    int degres;
public:
    GraphParser(const std::string& filename) : filename(filename) {};
    void parse();
    void closeFile();
    List<List<int>> getAdj() const;
};