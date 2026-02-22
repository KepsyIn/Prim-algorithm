#pragma once
#include <iostream>
#include <vector>
#include <fstream>

struct MSTResult {
    std::vector<int> predecessor;  // Parent vertex for each vertex in MST
    std::vector<int> weight;       // Edge weight to parent
    int totalCost;                 // Total MST weight
    bool isConnected;              // Graph connectivity
    
    MSTResult() : totalCost(0), isConnected(true) {}
    
    void print() const {
        std::cout << (isConnected ? "Graph is CONNECTED" : "Graph is NOT CONNECTED") << std::endl;
        std::cout << "─────────────────────────────────" << std::endl;
        
        for (size_t i = 0; i < predecessor.size(); i++) {
            int vertex = i + 1;
            if (predecessor[i] > 0) {
                std::cout << "Vertex " << vertex << " -> " << predecessor[i] 
                         << " (weight: " << weight[i] << ")" << std::endl;
            } else {
                std::cout << "Vertex " << vertex << " -> start vertex" << std::endl;
            }
        }
        
        std::cout << "─────────────────────────────────" << std::endl;
        std::cout << "Total MST Cost: " << totalCost << std::endl;
    }
    
    void exportToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file " << filename << std::endl;
            return;
        }
        
        file << (isConnected ? "Graph is CONNECTED" : "Graph is NOT CONNECTED") << std::endl;
        file << "─────────────────────────────────" << std::endl;
        
        for (size_t i = 0; i < predecessor.size(); i++) {
            int vertex = i + 1;
            if (predecessor[i] > 0) {
                file << "Vertex " << vertex << " -> " << predecessor[i] 
                    << " (weight: " << weight[i] << ")" << std::endl;
            } else {
                file << "Vertex " << vertex << " -> start vertex" << std::endl;
            }
        }
        
        file << "─────────────────────────────────" << std::endl;
        file << "Total MST Cost: " << totalCost << std::endl;
        file.close();
        std::cout << "Results exported to: " << filename << std::endl;
    }
};
