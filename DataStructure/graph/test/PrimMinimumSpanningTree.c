//
// Created by lotushint on 2022/7/19.
// Prim最小生成树算法
// 输入：
//      ../graph/minimumspanningtree/files/graph.txt
// 输出：
//      The minimum cost spanning tree is:
//
//      0---1 10
//
//      1---3 5
//
//      1---5 6
//
//      1---2 7
//
//      5---4 10
//
//      The root of it is 0
#include "../minimumspanningtree/primminimumspanningtree/PrimMinimumSpanningTree.h"

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    AdjacencyMatrixGraph matrixGraph;
    /**
     * 用于存放最小生成数的 M - 1 条边
     */
    edge treeEdge[M - 1];
    char filename[20];
    printf("Please input filename of graph:\n");
    gets(filename);
    createAdjacencyMatrixGraph(&matrixGraph, filename, 0);
    primMinimumSpanningTree(matrixGraph, treeEdge);
    return 0;
}