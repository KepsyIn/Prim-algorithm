#pragma once
#include "GraphParser.h"

class Prim{

    int sommet;
    bool connex;
    void isConnex(const List<List<int>>&);
public:
    Prim(int s) : sommet(s) , connex(true) {};
    List<List<int>> PrimL(GraphParser&);
    int* PrimM(GraphParser&);
    int getSommet(){return sommet;};
    bool getConnex() const;
    

};