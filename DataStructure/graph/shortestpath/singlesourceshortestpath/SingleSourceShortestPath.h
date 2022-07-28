//
// Created by lotushint on 2022/7/26.
// Dijkstra 算法求解单源最短路径
//

#ifndef DATASTRUCTURE_SINGLESOURCESHORTESTPATH_H
#define DATASTRUCTURE_SINGLESOURCESHORTESTPATH_H

#include "stdbool.h"
#include "../../adjacency/adjacencymatrix/AdjacencyMatrix.h"

//typedef enum {
//    /**
//     * false：0；
//     * true：1
//     */
//    false, true
//} boolean;

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
 * @param path 路径向量, path[i] 用来保存最短路径上第 i 个顶点的前驱顶点序号；没有前驱则为 -1
 * @param dist 距离向量
 */
void dijkstra(AdjacencyMatrixGraph matrixGraph, int v0, path path, dist dist) {
    /**
     * 表示当前元素是否已经求出最短路径
     */
    bool final[M];
    int i, k, min;
    /**
     * 当前选中顶点编号
     */
    int v;
    /*
     * 1.初始化集合 S 与距离向量 dist
     */
    for (v = 0; v < matrixGraph.vertexNumber; ++v) {
        final[v] = false;
        dist[v] = matrixGraph.edge[v0][v];
        if (dist[v] < FINITE && dist[v] != 0) {
            path[v] = v0;
        } else {
            //v 无前驱
            path[v] = -1;
        }
    }
    //初始时 S 中只有 v0
    final[v0] = true;
    //下一条可以去掉，因为源点 v0 到本身在矩阵中储存为 0
//    dist[v0] = 0;

    /*
     * 2.依次找出 matrixGraph.vertexNumber-1 个结点加入 S 中
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
        //输出本次入选的顶点 v 距离
        printf("\n%c---%d\n", matrixGraph.vertex[v], min);
        if (min == FINITE) {
            return;
        }
        //入选顶点 v 加入 S
        final[v] = true;

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

void outputShortestPathDirectedGraph(AdjacencyMatrixGraph matrixGraph, const path path, dist dist) {
    /**
     * 定义栈 stack 并初始化
     */
    int stack[M], pre, top = -1;
    for (int i = 0; i < matrixGraph.vertexNumber; ++i) {
        printf("\nDistance: %4d, Path: ", dist[i]);
        stack[++top] = i;
        pre = path[i];
        /*
         * 从第 i 个顶点开始向前搜索最短路径上的顶点
         */
        while (pre != -1) {
            stack[++top] = pre;
            pre = path[pre];
        }
        while (top > -1) {
            printf("%2d", stack[top--]);
        }
    }
}

#endif //DATASTRUCTURE_SINGLESOURCESHORTESTPATH_H
