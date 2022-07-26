//
// Created by lotushint on 2022/7/26.
//

#include "../singlesourceshortestpath/SingleSourceShortestPath.h"

int main() {
    AdjacencyMatrixGraph matrixGraph;
    path path;
    dist dist;
    int v0;
    //有向网 G13
    createAdjacencyMatrixGraph(&matrixGraph, "../graph/singlesourceshortestpath/files/g13.txt", 1);
    printf("please input the source point v0:");
    scanf("%d", &v0);
    dijkstra(matrixGraph, v0, path, dist);
    outputShortestPathDirectedGraph(matrixGraph, path, dist);
    return 0;
}