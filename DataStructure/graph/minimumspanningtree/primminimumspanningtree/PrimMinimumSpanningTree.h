//
// Created by lotushint on 2022/7/19.
// Prim 最小生成树算法
//

#ifndef DATASTRUCTURE_PRIMMINIMUMSPANNINGTREE_H
#define DATASTRUCTURE_PRIMMINIMUMSPANNINGTREE_H

#include "../../adjacency/adjacencymatrix/AdjacencyMatrix.h"

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
 * @param treeEdge 边向量
 */
void primMinimumSpanningTree(AdjacencyMatrixGraph matrixGraph, edge treeEdge[M - 1]) {
    edge x;
    int v, k, min, s, j, d;
    /*
     * 1.建立初始入选点，并初始化生成树边集 treeEdge
     */
    for (v = 1; v <= matrixGraph.vertexNumber - 1; v++) {
        /*
         * 此处从顶点 v0 开始求最小生成树,将 V0——Vv(v = 1,2,3,...,vertexNumber-1) 边加入 treeEdge
         */
        treeEdge[v - 1].begin = 0;
        treeEdge[v - 1].end = v;
        treeEdge[v - 1].length = matrixGraph.edge[0][v];
    }
    /*
     * 2.依次求当前（第 k 条）最小两栖边，并加入 treeEdge
     */
    for (k = 0; k <= matrixGraph.vertexNumber - 3; ++k) {
        min = treeEdge[k].length;
        s = k;
        for (j = k + 1; j <= matrixGraph.vertexNumber - 2; ++j) {
            if (treeEdge[j].length < min) {
                min = treeEdge[j].length;
                s = j;
            }
        }
        //入选顶点为 v
        v = treeEdge[s].end;

        /*
         * 通过交换，将当前最小边加入 treeEdge 中
         */
        x = treeEdge[s];
        treeEdge[s] = treeEdge[k];
        treeEdge[k] = x;
        /**
         * 3.由于新顶点 v 的加入，修改两栖边的基本信息
         */
        for (j = k + 1; j <= matrixGraph.vertexNumber - 2; ++j) {
            d = matrixGraph.edge[v][treeEdge[j].end];
            if (d < treeEdge[j].length) {
                treeEdge[j].length = d;
                treeEdge[j].begin = v;
            }
        }
    }
    /*
     * 输出最小生成树
     */
    printf("\n The minimum cost spanning tree is:\n");
    for (j = 0; j <= matrixGraph.vertexNumber - 2; ++j) {
        printf("\n%c---%c %d\n", matrixGraph.vertex[treeEdge[j].begin], matrixGraph.vertex[treeEdge[j].end],
               treeEdge[j].length);
    }
    printf("\nThe root of it is %c\n", matrixGraph.vertex[0]);
}

#endif //DATASTRUCTURE_PRIMMINIMUMSPANNINGTREE_H
