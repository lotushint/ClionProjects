//
// Created by lotushint on 2022/7/18.
// 深度优先遍历
// 输出：
//      visit vertex: 0
//      visit vertex: 1
//      visit vertex: 3
//      visit vertex: 4
//      visit vertex: 5
//      visit vertex: 2
//
#include "../traverse/Depth-firstTraversal.h"

int main() {
    AdjacencyListGraph listGraph;
    createAdjacencyListGraph(&listGraph, "../graph/adjacency/files/depth-firstTraversalGraph.txt", 0);
    depth_firstTraversal(listGraph);
    return 0;
}