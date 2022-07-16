//
// Created by lotushint on 2022/7/16.
// 邻接矩阵
//
#include "../AdjacencyMatrix.h"

int main() {
    MatrixGraph matrixGraph;
    createAdjacencyMatrixGraph(&matrixGraph,
                               "../graph/files/graph.txt",
                               0);
    return 0;
}