#include <iostream>
#include "Prim.h"
#include "chrono.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <graph_file> <start_vertex> [output_file]" << std::endl;
        return 1;
    }

    GraphParser gp(argv[1]);
    gp.parseToMat();
    int startVertex = std::stoi(argv[2]);
    
    Prim prim(startVertex);
    chrono timer;
    
    timer.start();
    MSTResult result = prim.PrimM(gp);
    timer.stop();
    
    // Print results
    result.print();
    std::cout << "Execution time: " << timer.getTime() << " microseconds" << std::endl;
    
    // Export to file if output file is specified
    if (argc == 4) {
        result.exportToFile(argv[3]);
    }
    
    return 0;
}