//
// Created by lotushint on 2022/7/28.
// 所有顶点对的最短路径
//

#include "../shortestpath/singlesourceshortestpath/SingleSourceShortestPath.h"
#include "../shortestpath/shortestpathforallvertexpairs/ShortestPathForAllVertexPairs.h"

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    //1.使用单源最短路径
    printf("使用单源最短路径求所有顶点对的最短路径：");
    AdjacencyMatrixGraph matrixGraph;
    path path;
    dist dist;
    int v0;
    //有向网 G13
    createAdjacencyMatrixGraph(&matrixGraph, "../graph/shortestpath/singlesourceshortestpath/files/g13.txt", 1);
    for (v0 = 0; v0 < matrixGraph.vertexNumber; ++v0) {
        printf("\n------源点为 %d------\n", v0);
        dijkstra(matrixGraph, v0, path, dist);
        outputShortestPathDirectedGraph(matrixGraph, path, dist);
    }


    //2.Floyd算法
    printf("\n使用Floyd算法求所有顶点对的最短路径：");
    pathway pathway;
    distance distance;
    floyd(matrixGraph, pathway, distance);
    outputFloydShortestPathDirectedGraph(matrixGraph, pathway, distance);
    return 0;
}