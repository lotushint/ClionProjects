//
// Created by lotushint on 2022/7/19.
// 广度优先遍历
//

#ifndef DATASTRUCTURE_BREADTH_FIRSTTRAVERSAL_H
#define DATASTRUCTURE_BREADTH_FIRSTTRAVERSAL_H

#include <stdio.h>
#include "../adjacency/adjacencylist/AdjacencyListStorageStructure.h"
#include "../adjacency/adjacencylist/AdjacencyListCreation.h"

/**
 * 全局标志向量
 */
int visited[M];

/**
 * 从顶点 i 开始广度优先遍历图的连接分量
 * @param listGraph 图的邻接表
 * @param i 遍历起点
 */
void breadth_firstSearch(AdjacencyListGraph listGraph, int i) {
    EdgeNode *p;
    /**
     * 队列, j 为出队的元素
     */
    int queue[M], front, rear, j;
    //初始化空队列
    front = rear = 0;
    //访问顶点 vi
    printf("visit vertex: %c \n", listGraph.adjacencyList[i].vertex);
    visited[i] = 1;
    queue[rear++] = i;
    while (rear > front) {
        //出队
        j = queue[front++];
        p = listGraph.adjacencyList[j].firstEdge;

        /**
         * 广度优先搜索邻接表
         */
        while (p) {
            if (visited[p->adjacentVertex] == 0) {
                printf("visit vertex: %c \n", listGraph.adjacencyList[p->adjacentVertex].vertex);
                queue[rear++] = p->adjacentVertex;
                visited[p->adjacentVertex] = 1;
            }
            p = p->next;
        }
    }
}

/**
 * 广度优先遍历图
 * @param listGraph 图的邻接表
 * @return 连通分量的个数
 */
int breadth_firstSearchTraverse(AdjacencyListGraph listGraph) {
    int counter = 0;
    for (int i = 0; i < listGraph.vertexNumber; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < listGraph.vertexNumber; ++i) {
        if (!visited[i]) {
            counter++;
            breadth_firstSearch(listGraph, i);
        }
    }
    return counter;
}

#endif //DATASTRUCTURE_BREADTH_FIRSTTRAVERSAL_H
