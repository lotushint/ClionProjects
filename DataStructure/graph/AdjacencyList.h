//
// Created by lotushint on 2022/7/16.
// 邻接表
//

#ifndef DATASTRUCTURE_ADJACENCYLIST_H
#define DATASTRUCTURE_ADJACENCYLIST_H
#define M 20 //图的最大顶点数
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
    struct Node *next;
} EdgeNode;
typedef struct vertexNode {
    /**
     * 顶点信息
     */
    vertexType vertex;
    /**
     * 邻接链表头指针
     */
    EdgeNode *firstEdge;
} VertexNode;
/**
 * 邻接表类型
 */
typedef struct {
    /**
     * 存放头结点的顺序表
     */
    VertexNode adjacencyList[M];
    /**
     * 图的顶点数
     */
    int vertexNumber;
    /**
     * 图的边数
     */
    int edgeNumber;
} AdjacencyList;
#endif //DATASTRUCTURE_ADJACENCYLIST_H
