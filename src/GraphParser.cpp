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
                        temp.add(target,dist);
                    }
                } 
                // else {
                //     temp.add(current,0); // poids 0 parce que c'est eux même
                // }
            }

            adjList.add(temp);
            temp.clear();
        }
    }

    fileStream.close();


    computeAdj();

};

void GraphParser::computeAdj(){
    int indexCounter = 0;

    for( List<int> l : adjList ){
        for( const int& u : l ){
            if( !adjList[u-1].isInList(indexCounter+1) ){
                adjList[u-1].add(indexCounter + 1, adjList[indexCounter].getPriorityElement(u));
            }
        }

        indexCounter++;
    }
};

void GraphParser::parseToMat(){
    
    std::ifstream fileStream;
    fileStream.open(filename);

    if (!fileStream.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }

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