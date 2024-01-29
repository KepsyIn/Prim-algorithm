#include "GraphParser.h"

void GraphParser::parseToList(){

    std::cout << "filename : " << this->filename << std::endl;

    fileStream.open(filename);

    if (!fileStream.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }

    int number;

    //lecture du degrés du graphe
    fileStream >> this->degree;

    List<int> temp;

    while (fileStream >> number) {
        
        if(number != 0) {
            // ajout dans la liste
            temp.add(number);
        } else {
            // on ne fait rien
            adjList.add(temp);
            temp.printList();
            temp.clear();
        }
    }

    fileStream.close();

};

void GraphParser::parseToMat(){

    std::cout << "filename : " << this->filename << std::endl;

    fileStream.open(filename);

    if (!fileStream.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }

    int number;
    int current;
    int target;
    int dist;

    //lecture du degrés du graphe
    fileStream >> this->degree;

    matrice mat(degree);

    while (fileStream >> current) {
        if(current != 0){
            fileStream >> target;
            fileStream >> dist;
            mat.setVal(current-1, target-1, dist);
        }

    }

    fileStream.close();

    mat.print();
}

void GraphParser::closeFile(){
    fileStream.close();
};

List<List<int>>  GraphParser::getAdj() const{
    return this->adjList;
}

int GraphParser::getDegree() const{
    return this->degree;
}