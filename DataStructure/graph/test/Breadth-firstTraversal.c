//
// Created by lotushint on 2022/7/19.
// 广度优先遍历
//
#include "../traverse/Breadth-firstTraversal.h"

int main() {
    AdjacencyListGraph listGraph;
    createAdjacencyListGraph(&listGraph, "../graph/adjacency/files/depth_breadth-firstTraversalGraph.txt", 0);
    printf("\n该图共有%d个连通分量。\n", breadth_firstSearchTraverse(listGraph));
    return 0;
}