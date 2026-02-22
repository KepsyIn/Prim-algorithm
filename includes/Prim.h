#pragma once
#include "GraphParser.h"
#include "MSTResult.h"
#include <fstream>

class Prim{

    int sommet;
    bool connex;
    void isConnex(const List<List<int>>&);
public:
    Prim(int s) : sommet(s) , connex(true) {};
    MSTResult PrimL(GraphParser&);
    MSTResult PrimM(GraphParser&);
    int getSommet(){return sommet;};
    bool getConnex() const;
    

};