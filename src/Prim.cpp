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

    // cout.printList();
    // F.printList();

    // for( List<int> l : pred ){
    //     std::cout << " - sommet : ";
    //     l.printList(); 
    // }

    // std::cout << "adj " << std::endl;
    // for( List<int> l : adj ){
    //     std::cout << " - sommet : ";
    //     l.printList(); 
    // }

    std::cout << " --- DEBUT DE L'ALGO --- " << std::endl;

    // ============================================
    //            MARIO N'OUBLIE PAS DE FAIRE -1
    // ============================================
    while( !(F.isEmpty() ) ){
        int t = F.pop();

        for( const int& u : adj[t-1] ){
            if( F.isInList(u) ){
                //std::cout << "yep t : " << t << " et u : " << u << std::endl;
                int weight = cout.getPriorityElement(u);

                //std::cout << "yep " << weight;

                int weightUT;

                if( adj[t-1].isInList(u)){
                    weightUT = adj[t-1].getPriorityElement(u);
                }else{
                    weightUT = adj[u-1].getPriorityElement(t);
                }

                std::cout << t << "--" << weight << "," << weightUT << "-->" << u << std::endl;

                //int weightUT = adj[t - 1].getPriorityElement(u);
                //std::cout << "yep " << weight << " et " << weightUT << std::endl;

                if( weight >= weightUT ){
                    //if(!pred[u-1].isInList(t)){
                        pred[u-1].add(t);
                    //}
                    
                    std::cout << "ajout" << std::endl;
                    cout.setPriorityElement(u,weightUT);
                    if( F.isInList(u) ) {
                        F.setPriorityElement(u,weightUT);
                    }                   
                }
            }
        }
    }




    // for( List<int> l : pred ){
    //     l.printList();
    // }

    return pred;


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
