#include <iostream>
#include "Parser/GraphParser.h"

int main() {

    GraphParser gp("../graph.txt");

    gp.parse();
    for( List<int> l : gp.getAdj() ){
        l.printList();
    }

    return 0;
}