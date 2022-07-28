//
// Created by lotushint on 2022/7/28.
// Floyd 所有顶点对的最短路径
//

#ifndef DATASTRUCTURE_SHORTESTPATHFORALLVERTEXPAIRS_H
#define DATASTRUCTURE_SHORTESTPATHFORALLVERTEXPAIRS_H

#include "../adjacency/adjacencymatrix/AdjacencyMatrix.h"

typedef int distance[M][M];
typedef int pathway[M][M];

void floyd(AdjacencyMatrixGraph matrixGraph, pathway path, distance dist) {
    //1.初始化
    for (int i = 0; i < matrixGraph.vertexNumber; ++i) {
        for (int j = 0; j < matrixGraph.vertexNumber; ++j) {
            dist[i][j] = matrixGraph.edge[i][j];
            if (i != j && dist[i][j] < FINITE) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }

    //2.递推求解每一对顶点间的最短距离, matrixGraph.vertexNumber 次, k 为经过的顶点号
    for (int k = 0; k < matrixGraph.vertexNumber; ++k) {
        for (int i = 0; i < matrixGraph.vertexNumber; ++i) {
            for (int j = 0; j < matrixGraph.vertexNumber; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

#endif //DATASTRUCTURE_SHORTESTPATHFORALLVERTEXPAIRS_H
