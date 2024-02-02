#include "Prim.h"
#include <climits>

List<List<int>> Prim::PrimL(GraphParser& g){
    
    List<List<int>> pred;
    List<int> F;

    int degree = g.getDegree();
    List<List<int>> adj = g.getAdj();

    for( int i = 1 ; i <= degree ; i++ ) {
        List<int> temp;
        pred.add(temp);
        F.add(i,INT_MAX);
    }

    F.setPriorityElement(sommet,0);
    List<int> cout(F);
    
    int tempPoids = INT8_MAX;
    for( const int& u : adj[sommet-1] ){
        if(tempPoids < adj[sommet-1].getPriorityElement(u) ){
            tempPoids = u;
        }
    }

    F.setPriorityElement(sommet,tempPoids);
    while( !(F.isEmpty() ) ){
        int t = F.pop();

        for( const int& u : adj[t-1] ){
            if( F.isInList(u) ){
                int weight = cout.getPriorityElement(u);
                int weightUT;
                if( adj[t-1].isInList(u)){
                    weightUT = adj[t-1].getPriorityElement(u);
                }else{
                    weightUT = adj[u-1].getPriorityElement(t);
                }
                if( weight >= weightUT ){
                    pred[u-1].clear();
                    pred[u-1].add(t,weightUT);
                    cout.setPriorityElement(u,weightUT);
                    if( F.isInList(u) ) {
                        F.setPriorityElement(u,weightUT);
                    }                   
                }
            }
        }
    }
    isConnex(pred);
    return pred;
}

void Prim::isConnex(const List<List<int>>& list ) {
    int index = 1;

    for( List<int> l : list ){
        if( l.isEmpty() && index != sommet ){
            connex = false;
        }
        index++;
    }
}

bool Prim::getConnex() const {
    return this->connex;
}

int* Prim::PrimM(GraphParser& g){
    List<int> F;
    int deg = g.getDegree();
    matrice adjMatrice = g.getMat();
    int* cout = new int[deg];
    int* pred = new int[deg];
    for(int i = 0; i < deg; i++){
        cout[i] = INT_MAX;
        pred[i] = -1;
    }
    cout[sommet-1] = 0;
    pred[sommet-1] = 0;
    for(int i = 0; i < deg; i++){
        F.add(i);
    }
    while(!(F.isEmpty())){
        int x = F.pop();
        for(int y = 0; y < deg; y++){
            if(adjMatrice[x][y] < cout[y] && adjMatrice[x][y] != 0){
                cout[y] = adjMatrice[x][y];
                pred[y] = x+1;
            }
        }
    }
    for (int i = 0; i < deg; i++) {
        std::cout << i+1 << " -> " << pred[i] << " : " << cout[i] << std::endl;
    }

    return pred;
}