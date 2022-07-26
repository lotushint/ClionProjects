//
// Created by lotushint on 2022/7/21.
// Kruskal 最小生成树算法
// 输入：
//      ../graph/minimumspanningtree/files/graph.txt
// 输出：
//      最小生成树是：
//      3---1     5
//      5---1     6
//      2---1     7
//      5---4    10
//      1---0    10
#include "../minimumspanningtree/kruskalminimumspanningtree/KruskalMinimumSpanningTree.h"

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    AdjacencyMatrixGraph matrixGraph;
    char filename[20];
    printf("Please input filename of graph:\n");
    gets(filename);
    createAdjacencyMatrixGraph(&matrixGraph, filename, 0);
    kruskalMinimumSpanningTree(matrixGraph);
    return 0;

}