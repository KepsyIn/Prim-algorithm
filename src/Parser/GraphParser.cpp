#include "GraphParser.h"

void GraphParser::parse(){

    if (!fileStream.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }

    int number;

    //lecture du degrés du graphe
    fileStream >> this->degres;

    while (fileStream >> number) {
        List<int> temp;
        if(number != 0) {
            // ajout dans la liste
            temp.add(number);
        } else {
            // on ne fait rien
            adjList.add(temp);
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