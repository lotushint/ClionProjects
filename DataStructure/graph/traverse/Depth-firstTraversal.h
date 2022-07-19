//
// Created by lotushint on 2022/7/18.
// 深度优先遍历
//

#ifndef DATASTRUCTURE_DEPTH_FIRSTTRAVERSAL_H
#define DATASTRUCTURE_DEPTH_FIRSTTRAVERSAL_H

#include <stdio.h>
#include "../adjacency/adjacencylist/AdjacencyListStorageStructure.h"
#include "../adjacency/adjacencylist/AdjacencyListCreation.h"

/**
 * 全局标志向量
 */
int visited[M];

/**
 * 从顶点 i 开始深度优先遍历图的连接分量
 * @param listGraph 图的邻接表
 * @param i 遍历起点
 */
void depth_firstSearch(AdjacencyListGraph listGraph, int i) {
    EdgeNode *p;
    //访问顶点 i
    printf("visit vertex: %c \n", listGraph.adjacencyList[i].vertex);
    visited[i] = 1;

    p = listGraph.adjacencyList[i].firstEdge;
    /**
     * 从 p 的邻接点出发进行深度优先遍历
     */
    while (p) {
        if (!visited[p->adjacentVertex]) {
            depth_firstSearch(listGraph, p->adjacentVertex);
        }
        p = p->next;
    }
};

/**
 * 深度优先遍历图
 * @param listGraph 图的邻接表
 */
void depth_firstTraversal(AdjacencyListGraph listGraph) {
    //初始化标志数组
    for (int i = 0; i < listGraph.vertexNumber; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < listGraph.vertexNumber; ++i) {
        //vi未访问过
        if (!visited[i]) {
            depth_firstSearch(listGraph, i);
        }
    }
}

#endif //DATASTRUCTURE_DEPTH_FIRSTTRAVERSAL_H
