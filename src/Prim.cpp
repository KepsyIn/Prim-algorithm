#include "Prim.h"
#include <climits>

List<List<int>> Prim::PrimL(GraphParser& g){
    int deg = g.getDegree();
    List<int> priorityList;
    List<List<int>> result(g.getAdj());
    for(int i = 0; i < deg; i++){
        priorityList.add(i+1, INT_MAX);
        for(int j = 1; j < result[i].length(); j++){
            result[i].remove(j);
        }
    }
    priorityList.remove(sommet);
    priorityList.add(sommet, 0);
    while(!priorityList.isEmpty()){
        int t = priorityList.pop();
        List<int> tempList = g.getAdj()[t];
        for(int i : tempList){
            if(priorityList.getPriorityElement(i) >= tempList.getPriorityElement(i)){
                result[i].add(t, priorityList.getPriorityElement(i));
                priorityList.setPriorityElement(i, tempList.getPriorityElement(i));

            }
        }
    }
    return result;
}

// List<List<int>> Prim::PrimM(GraphParser& g){

// }