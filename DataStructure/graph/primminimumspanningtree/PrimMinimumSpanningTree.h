//
// Created by lotushint on 2022/7/19.
// Prim最小生成树算法
//

#ifndef DATASTRUCTURE_PRIMMINIMUMSPANNINGTREE_H
#define DATASTRUCTURE_PRIMMINIMUMSPANNINGTREE_H

#include "../adjacency/adjacencymatrix/AdjacencyMatrix.h"

/**
 * 用于保存最小生成树的边类型定义
 */
typedef struct edgeData {
    /**
     * 边顶点序号
     */
    int begin, end;
    /**
     * 边长
     */
    int length;
} edge;

/**
 * prim算法构造最小生成树
 * @param matrixGraph 图的邻接矩阵
 * @param tree 边向量
 */
void primMinimumSpanningTree(AdjacencyMatrixGraph matrixGraph, edge tree[M - 1]) {

}

#endif //DATASTRUCTURE_PRIMMINIMUMSPANNINGTREE_H
