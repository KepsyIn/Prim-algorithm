#include "GraphParser.h"

void GraphParser::parseToList(){

    std::ifstream fileStream;
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
            int poids;

            fileStream >> poids;

            if( poids != 0 ){
                
                temp.add(number,poids);
            }
            
        } else {
            // on ne fait rien
            adjList.add(temp);
            temp.clear();
        }
    }

    fileStream.close();

};

void GraphParser::parseToMat(){
    
    std::ifstream fileStream;
    fileStream.open(filename);

    if (!fileStream.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }

    //lecture du degrés du graphe
    fileStream >> this->degree;

    int number;

    mat.createMatrice(this->degree);

    while (fileStream >> number) {

        int current;
        int target;
        int dist;

        if( number != 0 ){
            current = number;
            while( number != 0 ){
                fileStream >> number;
                if( number != 0 ){
                    target = number;
                    fileStream >> number;
                    if( number != 0 ){
                        dist = number;
                        mat.setVal(current-1,target-1,dist);
                    }
                }
            }
        }

    }

    fileStream.close();
}

List<List<int>>  GraphParser::getAdj() const{
    return this->adjList;
}

int GraphParser::getDegree() const{
    return this->degree;
}

matrice GraphParser::getMat() const{
    return this->mat;
}