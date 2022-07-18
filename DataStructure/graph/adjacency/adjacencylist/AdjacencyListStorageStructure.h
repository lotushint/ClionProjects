//
// Created by lotushint on 2022/7/18.
// 邻接表存储结构
//

#ifndef DATASTRUCTURE_ADJACENCYLISTSTORAGESTRUCTURE_H
#define DATASTRUCTURE_ADJACENCYLISTSTORAGESTRUCTURE_H
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
     * 权值
     */
    int weight;
    /**
     * 指针域，指向下一个
     */
    struct node *next;
} EdgeNode;
/**
 * 头结点类型
 */
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
} AdjacencyListGraph;
#endif //DATASTRUCTURE_ADJACENCYLISTSTORAGESTRUCTURE_H
