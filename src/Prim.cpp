#include "Prim.h"
#include <climits>
#include <vector>

MSTResult Prim::PrimL(GraphParser& g){
    
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
    
    // Build the result structure
    MSTResult result;
    result.predecessor.resize(degree);
    result.weight.resize(degree);
    result.isConnected = connex;
    result.totalCost = 0;
    
    for (int i = 0; i < degree; i++) {
        if (!pred[i].isEmpty()) {
            result.predecessor[i] = pred[i][0];
            result.weight[i] = pred[i].getPriorityElement(pred[i][0]);
            result.totalCost += result.weight[i];
        } else {
            result.predecessor[i] = (i + 1 == sommet) ? 0 : -1;
            result.weight[i] = 0;
        }
    }
    
    return result;
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

MSTResult Prim::PrimM(GraphParser& g) {
    int deg = g.getDegree();
    const matrice& adjMatrice = g.getMat();
    
    // Track which vertices are in MST
    std::vector<bool> inMST(deg, false);
    std::vector<int> pred(deg, -1);
    std::vector<int> cost(deg, INT_MAX);
    
    // Start from the source vertex
    cost[sommet - 1] = 0;
    pred[sommet - 1] = 0;
    
    // Build MST
    for (int count = 0; count < deg; count++) {
        int u = -1;
        
        // Find minimum cost vertex not in MST
        for (int v = 0; v < deg; v++) {
            if (!inMST[v] && (u == -1 || cost[v] < cost[u])) {
                u = v;
            }
        }
        
        if (u == -1 || cost[u] == INT_MAX) {
            connex = false;  // Graph is not connected
            break;
        }
        
        inMST[u] = true;
        
        // Update costs for adjacent vertices
        for (int v = 0; v < deg; v++) {
            int weight = adjMatrice.getVal(u, v);
            if (weight > 0 && !inMST[v] && weight < cost[v]) {
                cost[v] = weight;
                pred[v] = u + 1;  // Store 1-indexed vertex
            }
        }
    }
    
    // Build the result structure
    MSTResult result;
    result.predecessor.resize(deg);
    result.weight.resize(deg);
    result.isConnected = connex;
    result.totalCost = 0;
    
    for (int i = 0; i < deg; i++) {
        if (cost[i] != INT_MAX) {
            result.predecessor[i] = pred[i];
            result.weight[i] = cost[i];
            result.totalCost += result.weight[i];
        } else {
            result.predecessor[i] = -1;
            result.weight[i] = 0;
        }
    }
    
    return result;
}
