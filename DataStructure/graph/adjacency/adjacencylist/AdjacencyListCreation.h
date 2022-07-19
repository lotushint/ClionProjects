//
// Created by lotushint on 2022/7/18.
// 建立图的邻接表
//

#ifndef DATASTRUCTURE_ADJACENCYLISTCREATION_H
#define DATASTRUCTURE_ADJACENCYLISTCREATION_H

#include "stdio.h"
#include "AdjacencyListStorageStructure.h"
#include <malloc.h>

/**
 * 建立图的邻接表
 * @param graph 邻接表类型的指针
 * @param filename 存放图信息的文件名
 * @param c 图的类型参数：<br><font color="red">为 0 表示建立无向图；<br>否则建立有向图</font>
 */
void createAdjacencyListGraph(AdjacencyListGraph *graph, char *filename, int c) {
    /**
     * vi(start)--w(weight)-->vj(end),
     */
    int i, j, w;
    EdgeNode *edgeNodePointer;
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp) {
        //读入顶点数与边数
        fscanf(fp, "%d%d", &graph->vertexNumber, &graph->edgeNumber);
        //读入顶点信息
        for (i = 0; i < graph->vertexNumber; ++i) {
            fscanf(fp, "%1s", &graph->adjacencyList[i].vertex);
            //边表置为空表
            graph->adjacencyList[i].firstEdge = NULL;
        }
        //循环 edgeNumber 次建立边表
        for (int k = 0; k < graph->edgeNumber; ++k) {
            //输入无序对(i,j,w)
            fscanf(fp, "%d%d%d", &i, &j, &w);
            edgeNodePointer = (EdgeNode *) malloc(sizeof(EdgeNode));
            edgeNodePointer->adjacentVertex = j;
            edgeNodePointer->weight = w;
            edgeNodePointer->next = graph->adjacencyList[i].firstEdge;
            //将新结点插入顶点 vi 的边表结点
            graph->adjacencyList[i].firstEdge = edgeNodePointer;
            if (c == 0) {
                edgeNodePointer = (EdgeNode *) malloc(sizeof(EdgeNode));
                edgeNodePointer->adjacentVertex = i;
                edgeNodePointer->weight = w;
                edgeNodePointer->next = graph->adjacencyList[j].firstEdge;
                //将新结点插入顶点 vj 的边表结点
                graph->adjacencyList[j].firstEdge = edgeNodePointer;
            }
        }
        fclose(fp);
    } else {
        graph->vertexNumber = 0;
    }
}

#endif //DATASTRUCTURE_ADJACENCYLISTCREATION_H
