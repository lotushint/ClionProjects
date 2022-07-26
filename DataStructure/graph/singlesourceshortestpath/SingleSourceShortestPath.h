//
// Created by lotushint on 2022/7/26.
//

#ifndef DATASTRUCTURE_SINGLESOURCESHORTESTPATH_H
#define DATASTRUCTURE_SINGLESOURCESHORTESTPATH_H

#include "../adjacency/adjacencymatrix/AdjacencyMatrix.h"

typedef enum {
    /**
     * FALSE：0；
     * TRUE：1
     */
    FALSE, TRUE
} boolean;

/**
 * 距离向量类型
 */
typedef int dist[M];
/**
 * 路径类型
 */
typedef int path[M];

/**
 * Dijkstra 算法求解单源最短路径
 * @param matrixGraph 图的邻接矩阵
 * @param v0 源点
 * @param path 路径向量, p[i] 用来保存最短路径上第 i 个顶点的前驱顶点序号
 * @param dist 距离向量
 */
void dijkstra(AdjacencyMatrixGraph matrixGraph, int v0, path path, dist dist) {
    /**
     * 表示当前元素是否已经求出最短路径
     */
    boolean final[M];
    int i, k, min;
    /**
     * 当前选中顶点编号
     */
    int v;
    /*
     * 1.初始化集合 S 与距离向量 dist
     */
    for (v = 0; v < matrixGraph.vertexNumber; ++v) {
        final[v] = FALSE;
        dist[v] = matrixGraph.edge[v0][v];
        if (dist[v] < FINITE && dist[v] != 0) {
            path[v] = v0;
        } else {
            //v 无前驱
            path[v] = -1;
        }
    }
    //初始时 S 中只有 v0
    final[v0] = TRUE;
    dist[v0] = 0;

    /*
     * 2.依次找出 n-1 个结点加入 S 中
     */
    for (i = 1; i < matrixGraph.vertexNumber; ++i) {
        min = FINITE;
        //找最小边入结点
        for (k = 0; k < matrixGraph.vertexNumber; ++k) {
            if (!final[k] && dist[k] < min) {
                v = k;
                min = dist[k];
            }
        }
        //输出本次入选的顶点距离
        printf("\n%c---%d\n", matrixGraph.vertex[v], min);
        if (min == FINITE) {
            return;
        }
        //v 加入 S
        final[v] = TRUE;

        /*
         * 3.修改 S 与 V-S 中各结点的距离
         */
        for (k = 0; k < matrixGraph.vertexNumber; ++k) {
            if (!final[k] && (min + matrixGraph.edge[v][k] < dist[k])) {
                dist[k] = min + matrixGraph.edge[v][k];
                path[k] = v;
            }
        }
    }
}

void outputShortestPathDirectedGraph(AdjacencyMatrixGraph matrixGraph, path path, dist dist) {
    /**
     * 定义栈 st 并初始化
     */
    int st[M], pre, top = -1;
    for (int i = 0; i < matrixGraph.vertexNumber; ++i) {
        printf("\nDistance: %7d, path:", dist[i]);
        st[++top] = i;
        pre = path[i];
        /*
         * 从第 i 个顶点开始向前搜索最短路径上的顶点
         */
        while (pre != -1) {
            st[++top] = pre;
            pre = path[pre];
        }
        while (top > 0) {
            printf("%2d", st[top--]);
        }
    }
}

#endif //DATASTRUCTURE_SINGLESOURCESHORTESTPATH_H
