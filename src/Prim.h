#pragma once
#include "GraphParser.h"

class Prim{

    int sommet;
public:
    Prim(int s) : sommet(s) {};
    List<List<int>> PrimL(GraphParser&);
    int* PrimM(GraphParser&);
    int getSommet(){return sommet;};

};