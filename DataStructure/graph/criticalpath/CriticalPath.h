//
// Created by lotushint on 2022/7/30.
// 关键路径
//

#ifndef DATASTRUCTURE_CRITICALPATH_H
#define DATASTRUCTURE_CRITICALPATH_H
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
     * 边的权值
     */
    int weight;
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
 * AOE 网络的邻接表结构
 */
typedef struct {
    VertexNode adjacencyList[M];
    int vertexNumber;
    int edgeNumber;
} AoeGraph;

/**
 * 求 AOE 网各事件的最早发生时间
 * @param graph AOE 网的出边表
 * @param ve 事件最早发生时间向量
 * @param topologicalSequence AOE 网的拓扑排序列向量
 * @return 返回输出的顶点个数
 */
int eventEarliestTime(AoeGraph graph, int ve[], int topologicalSequence[]) {
    int counter = 0;
    int j, v;
    int flag[M];
    /**
     * 队列
     */
    int queue[M], front, rear;
    front = rear = 0;

    EdgeNode *edgeNodePointer;

    //1.初始化
    for (int i = 0; i < graph.vertexNumber; ++i) {
        //初始化每个顶点的最早开始时间 ve[i] 为 0
        ve[i] = 0;
        //访问标记初始化
        flag[i] = 0;
    }

    //2.先将所有入度为 0 的顶点入队
    for (int i = 0; i < graph.vertexNumber; ++i) {
        if (graph.adjacencyList[i].inDegree == 0 && flag[i] == 0) {
            queue[rear++] = i;
            flag[i] = 1;
        }
    }

    //队列不为空时
    while (front < rear) {
        v = queue[front++];
        printf("%c---->", graph.adjacencyList[v].vertex);

        //记录拓扑排序当前元素
        topologicalSequence[counter++] = v;

        edgeNodePointer = graph.adjacencyList[v].firstEdge;

        while (edgeNodePointer) {
            j = edgeNodePointer->adjacentVertex;
            //若入度为 0 ，则将进队
            if (--graph.adjacencyList[j].inDegree == 0 && flag[j] == 0) {
                queue[rear++] = j;
                flag[j] = 1;
            }
            if (ve[v] + edgeNodePointer->weight > ve[j]) {
                //ve[j]的值是从源点到顶点 j 的最长距离
                ve[j] = ve[v] + edgeNodePointer->weight;
            }
            edgeNodePointer = edgeNodePointer->next;
        }
    }
    return counter;
}

/**
 * 求 AOE 网各事件的最晚允许开始时间
 * @param graph AOE 网的入边表
 * @param ve 事件最早发生时间向量
 * @param vl 事件最晚允许发生时间向量
 * @param topologicalSequence AOE 网的拓扑排序列向量
 */
void eventLatestTime(AoeGraph graph, const int ve[], int vl[], int topologicalSequence[]) {
    int k = graph.vertexNumber - 1, j, v;
    EdgeNode *edgeNodePointer;
    //初始化 AOE 网中每个顶点的最晚允许开始时间为关键路径长度
    for (int i = 0; i < graph.vertexNumber; ++i) {
        vl[i] = ve[topologicalSequence[graph.vertexNumber - 1]];
    }
    while (k > -1) {
        v = topologicalSequence[k];
        edgeNodePointer = graph.adjacencyList[v].firstEdge;
        while (edgeNodePointer) {
            j = edgeNodePointer->adjacentVertex;
            if (vl[v] - edgeNodePointer->weight < vl[j]) {
                vl[j] = vl[v] - edgeNodePointer->weight;
            }
            edgeNodePointer = edgeNodePointer->next;
        }
        k--;
    }
}

#endif //DATASTRUCTURE_CRITICALPATH_H
