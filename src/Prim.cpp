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

int** Prim::PrimM(GraphParser& g) {
    List<int> F;
    int deg = g.getDegree();
    matrice adjMatrice(deg);

    for (int i = 0; i < deg; i++) {
        for (int j = 0; j < deg; j++) {
            adjMatrice.setVal(i, j, g.getMat()[i][j]);
        }
    }

    int** result = new int*[deg];
    int* cout = new int[deg];
    int* pred = new int[deg];

    for (int i = 0; i < deg; i++) {
        result[i] = new int[2];
        cout[i] = INT_MAX;
        pred[i] = -1;
    }

    cout[sommet - 1] = 0;
    pred[sommet - 1] = 0;

    for (int i = 0; i < deg; i++) {
        F.add(i);
    }

    while (!F.isEmpty()) {
        int x = F.pop();
        for (int y = 0; y < deg; y++) {
            if (adjMatrice.getVal(x, y) < cout[y] && adjMatrice.getVal(x, y) != 0) {
                cout[y] = adjMatrice.getVal(x, y);
                pred[y] = x + 1;
            }
        }
    }

    // Remplissage du tableau d'entiers result avec les données nécessaires
    for (int i = 0; i < deg; i++) {
        result[i][0] = pred[i];
        result[i][1] = cout[i];
    }

    delete[] cout;
    delete[] pred;

    return result;
}


// int** Prim::PrimM(GraphParser& g) {
//     List<int> F;
//     int deg = g.getDegree();
//     matrice adjMatrice(deg);
//     for (int i = 0; i < deg; i++) {
//         for (int j = 0; j < deg; j++) {
//             adjMatrice.setVal(i, j, g.getMat()[i][j]);
//         }
//     }
//     int** result = new int*[2];
//     result[0] = new int[deg];
//     result[1] = new int[deg];

//     for (int i = 0; i < deg; i++) {
//         result[0][i] = -1;
//         result[1][i] = INT_MAX;
//     }

//     result[1][sommet - 1] = 0;
//     result[0][sommet - 1] = 0;

//     for (int i = 0; i < deg; i++) {
//         F.add(i);
//     }

//     while (!(F.isEmpty())) {
//         int x = F.pop();
//         for (int y = 0; y < deg; y++) {
//             if (adjMatrice.getVal(x, y) < result[1][y] && adjMatrice.getVal(x, y) != 0) {
//                 result[1][y] = adjMatrice.getVal(x, y);
//                 result[0][y] = x + 1;
//             }
//         }
//     }

//     for (int i = 0; i < deg; i++) {
//         std::cout << i + 1 << " -> " << result[0][i] << " : " << result[1][i] << std::endl;
//     }

//     return result;
// }
