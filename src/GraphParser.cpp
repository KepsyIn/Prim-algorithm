#include "GraphParser.h"

void GraphParser::parse(){

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

void GraphParser::closeFile(){
    fileStream.close();
};

List<List<int>>  GraphParser::getAdj() const{
    return this->adjList;
}

int GraphParser::getDegree() const{
    return this->degree;
}