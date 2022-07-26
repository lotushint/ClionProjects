//
// Created by lotushint on 2022/7/21.
// Kruskal 最小生成树算法
//

#ifndef DATASTRUCTURE_KRUSKALMINIMUMSPANNINGTREE_H
#define DATASTRUCTURE_KRUSKALMINIMUMSPANNINGTREE_H

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
 * 对边向量进行快速排序
 * @param edge 边向量
 * @param left 边向量左下标
 * @param right 边向量右下标
 */
void quickSort(edge edges[], int left, int right) {
    edge x;
    int i, j;
    if (left < right) {
        i = left;
        j = right;
        //保留 x （分区点），第一次一般选取第一个元素（可以任取）
        x = edges[i];
        while (i < j) {
            //从右向左找第一个比分区点小的元素放入分区前部（划分后的前部，此时分区点还没有确定）
            while (i < j && x.length < edges[j].length) {
                j--;
            }
            if (i < j) {
                edges[i++] = edges[j];
            }

            //从左向右找第一个比分区点大的元素放入分区后部（划分后的后部，此时分区点还没有确定）
            while (i < j && x.length > edges[i].length) {
                i++;
            }
            if (i < j) {
                edges[j--] = edges[i];
            }
        }
        //最后的位置放 x （分区点）
        edges[i] = x;
        //分区后递归：前部、后部
        quickSort(edges, left, i - 1);
        quickSort(edges, i + 1, right);
    }
}

/**
 * 从图的邻接矩阵中读取图的所有边信息
 * @param matrixGraph 图的邻接矩阵
 * @param edges 边向量
 */
void readEdge(AdjacencyMatrixGraph matrixGraph, edge edges[]) {
    int k = 0;
    for (int i = 0; i < matrixGraph.vertexNumber; ++i) {
        for (int j = 0; j < i; ++j) {
            if (matrixGraph.edge[i][j] != 0 && matrixGraph.edge[i][j] < FINITE) {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k++].length = matrixGraph.edge[i][j];
            }
        }
    }
}

/**
 * kruskal 求解最小生成树算法
 * @param matrixGraph 图的邻接矩阵
 */
void kruskalMinimumSpanningTree(AdjacencyMatrixGraph matrixGraph) {
    int k = 0, connectedComponent;
    /**
     * 保存每一个顶点所在的连通分量的编号
     */
    int vertexConnectedComponentNumber[M];
    /**
     * 用于存放图的所有边
     */
    edge edges[M * M];
    /**
     * 用于存放最小生成树的边信息
     */
    edge treeEdges[M];
    //读取边信息
    readEdge(matrixGraph, edges);
    //对边进行升序排列
    quickSort(edges, 0, matrixGraph.edgeNumber - 1);
    /*
     * 设置每一个顶点的连通分量为其顶点编号
     */
    for (int i = 0; i < matrixGraph.vertexNumber; ++i) {
        vertexConnectedComponentNumber[i] = i;
    }

    /*
     * 树中共有 matrixGraph.vertexNumber-1 条边
     */
    for (int i = 0; i < matrixGraph.vertexNumber - 1; ++i) {
        //找到属于两个连通分量权最小的边
        while (vertexConnectedComponentNumber[edges[k].begin] == vertexConnectedComponentNumber[edges[k].end]) {
            k++;
        }
        //将边 k 加入到生成树中
        treeEdges[i] = edges[k];
        //记录选中边的终点的连通分量的编号
        connectedComponent = vertexConnectedComponentNumber[edges[k].end];
        //两个连通分量合并为一个连通分量
        for (int j = 0; j < matrixGraph.vertexNumber; ++j) {
            if (vertexConnectedComponentNumber[j] == connectedComponent) {
                vertexConnectedComponentNumber[j] = vertexConnectedComponentNumber[edges[k].begin];
            }
        }
        k++;
    }
    printf("最小生成树是：\n");
    for (int j = 0; j < matrixGraph.vertexNumber - 1; ++j) {
        printf("%c---%c%6d\n", matrixGraph.vertex[treeEdges[j].begin], matrixGraph.vertex[treeEdges[j].end],
               treeEdges[j].length);
    }

}

#endif //DATASTRUCTURE_KRUSKALMINIMUMSPANNINGTREE_H
