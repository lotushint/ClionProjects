//
// Created by lotushint on 2022/7/16.
// 邻接矩阵
//

#ifndef DATASTRUCTURE_ADJACENCYMATRIX_H
#define DATASTRUCTURE_ADJACENCYMATRIX_H

#include "stdio.h"

#define FINITE 5000 //此处用 5000 代表无穷大
#define M 20 //图的最大顶点数
/**
 * 顶点值类型
 */
typedef char vertexType;
/**
 * 权值类型
 */
typedef int edgeType;
typedef struct {
    /**
     * 顶点信息域
     */
    vertexType vertex[M];
    /**
     * 邻接矩阵
     */
    edgeType edge[M][M];
    /**
     * 图中顶点数
     */
    int vertexNumber;
    /**
     * 图中边数
     */
    int edgeNumber;
} MatrixGraph;

/**
 * 建立图的邻接矩阵存储结构
 * @param graph 邻接矩阵的指针变量
 * @param s 存放图信息的文件名
 * @param c 图的类型参数：<br><font color="red">为 0 表示建立无向图；<br>否则建立有向图</font>
 */
void createAdjacencyMatrixGraph(MatrixGraph *graph, char *s, int c) {
    int i, j, w;
    FILE *rf;

    //从文件中读取图的边信息
    rf = fopen(s, "r");
    if (rf) {
        //读入图的顶点数与边数
        fscanf(rf, "%d%d", &graph->vertexNumber, &graph->edgeNumber);
        //读入图中的顶点值
        for (i = 0; i < graph->vertexNumber; ++i) {
            fscanf(rf, "%1s", &graph->vertex[i]);
        }
        //初始化邻接矩阵
        for (i = 0; i < graph->vertexNumber; ++i) {
            for (j = 0; j < graph->vertexNumber; ++j) {
                if (i == j) {
                    graph->edge[i][j] = 0;
                } else {
                    graph->edge[i][j] = FINITE;
                }
            }
        }
        for (int k = 0; k < graph->edgeNumber; ++k) {
            fscanf(rf, "%d%d%d", &i, &j, &w);
            graph->edge[i][j] = w;
            if (c == 0) {
                graph->edge[j][i] = w;
            }
        }
        fclose(rf);
    } else {
        graph->vertexNumber = 0;
    }
}

#endif //DATASTRUCTURE_ADJACENCYMATRIX_H
