//
// Created by lotushint on 2022/7/29.
// 拓扑排序
//

#ifndef DATASTRUCTURE_TOPOLOGICALSORT_H
#define DATASTRUCTURE_TOPOLOGICALSORT_H
#define M 20 //图的最大顶点数

#include "stdio.h"
#include "malloc.h"

/**
 * 顶点信息数据类型
 */
typedef char vertexType;
/**
 * 边表结点
 */
typedef struct node {
    /**
     * 邻接点
     */
    int adjacentVertex;
    /**
     * 指针域，指向下一个
     */
    struct node *next;
} EdgeNode;
/**
 * 带顶点入度的头结点定义
 */
typedef struct de {
    EdgeNode *firstEdge;
    vertexType vertex;
    /**
     * 顶点的入度域
     */
    int inDegree;
} VertexNode;
/**
 * AOv 网络的邻接表结构
 */
typedef struct {
    VertexNode adjacencyList[M];
    int vertexNumber;
    int edgeNumber;
} AovGraph;

/**
 * 拓扑排序
 * @param graph AOV 邻接表存储变量
 * @return 拓扑排序输出的顶点个数
 */
int topologicalSort(AovGraph graph) {
    int counter = 0, j, v, flag[M];
    /**
     * 队列
     */
    int queue[M], front, rear;
    //初始化空队列
    front = rear = 0;

    /**
     * 指针
     */
    EdgeNode *edgeNodePointer;
    //访问标记初始化
    for (int i = 0; i < graph.vertexNumber; ++i) {
        flag[i] = 0;
    }

    //先将所有入度为 0 的顶点入队
    for (int i = 0; i < graph.vertexNumber; ++i) {
        if (graph.adjacencyList[i].inDegree == 0 && flag[i] == 0) {
            queue[rear++] = i;
            flag[i] = 1;
        }
    }

    printf("\nAOV网络的拓扑排序时：\n");
    while (front < rear) {
        v = queue[front++];
        printf("%c ", graph.adjacencyList[v].vertex);
        //计数器加一
        counter++;
        edgeNodePointer = graph.adjacencyList[v].firstEdge;
        //将所有与 v 邻接的顶点的入度域减 1
        while (edgeNodePointer) {
            j = edgeNodePointer->adjacentVertex;
            if (--graph.adjacencyList[j].inDegree == 0 && flag[j] == 0) {
                queue[rear++] = j;
                flag[j] = 1;
            }
            edgeNodePointer = edgeNodePointer->next;
        }
    }
    return counter;
}

/**
 * 建立图的邻接表（有向网络）
 * @param graph 邻接表类型的指针
 * @param filename 存放图信息的文件名
 */
void createAdjacencyListGraph(AovGraph *graph, char *filename) {
    /**
     * vi(start)-->vj(end),
     */
    int i, j;
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
            //边表入度域置为 0
            graph->adjacencyList[i].inDegree = 0;
        }
        //循环 edgeNumber 次建立边表
        for (int k = 0; k < graph->edgeNumber; ++k) {
            //输入无序对(i,j,w)
            fscanf(fp, "%d%d", &i, &j);
            edgeNodePointer = (EdgeNode *) malloc(sizeof(EdgeNode));
            edgeNodePointer->adjacentVertex = j;
            edgeNodePointer->next = graph->adjacencyList[i].firstEdge;
            //将新结点插入顶点 vi 的边表结点
            graph->adjacencyList[i].firstEdge = edgeNodePointer;
            graph->adjacencyList[j].inDegree++;
        }
        fclose(fp);
    } else {
        graph->vertexNumber = 0;
    }
}

#endif //DATASTRUCTURE_TOPOLOGICALSORT_H
