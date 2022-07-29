//
// Created by lotushint on 2022/7/28.
// Floyd 所有顶点对的最短路径
//

#ifndef DATASTRUCTURE_SHORTESTPATHFORALLVERTEXPAIRS_H
#define DATASTRUCTURE_SHORTESTPATHFORALLVERTEXPAIRS_H

#include "../../adjacency/adjacencymatrix/AdjacencyMatrix.h"

typedef int distance[M][M];
typedef int pathway[M][M];

/**
 * Floyd方法求所有顶点对的最短路径
 * @param matrixGraph 邻接矩阵
 * @param path 路径向量
 * @param dist 距离向量
 */
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

/**
 * 输出有向图的最短路径
 * @param matrixGraph 邻接矩阵
 * @param pathway 路径向量
 * @param distance 距离向量
 */
void outputFloydShortestPathDirectedGraph(AdjacencyMatrixGraph matrixGraph, pathway pathway, distance distance) {
    /**
     * 中转顶点
     */
    int transitVertex;
    for (int i = 0; i < matrixGraph.vertexNumber; ++i) {
        for (int j = 0; j < matrixGraph.vertexNumber; ++j) {
            printf("\nDistance:%d---%d  %d  ", i, j, distance[i][j]);
            transitVertex = i;
            //起点
            printf("Path: %d ", transitVertex);

            while (pathway[transitVertex][j] != -1 && transitVertex != pathway[transitVertex][j]) {
                transitVertex = pathway[transitVertex][j];
                printf(" %d ", transitVertex);
            }

            //终点
            printf(" %d \n", j);
        }
    }
}

#endif //DATASTRUCTURE_SHORTESTPATHFORALLVERTEXPAIRS_H
