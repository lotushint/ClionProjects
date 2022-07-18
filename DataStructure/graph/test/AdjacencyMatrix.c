//
// Created by lotushint on 2022/7/16.
// 邻接矩阵
//
#include "../adjacency/adjacencymatrix/AdjacencyMatrix.h"

int main() {
    AdjacencyMatrixGraph matrixGraph;
    createAdjacencyMatrixGraph(&matrixGraph,
                               "../graph/adjacency/files/graph.txt",
                               0);
    return 0;
}