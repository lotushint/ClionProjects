//
// Created by lotushint on 2022/7/29.
// 拓扑排序（结果不止一种有多种）
//

#include "../topologicalsort/TopologicalSort.h"

int main() {
    AovGraph graph;
    createAdjacencyListGraph(&graph, "../graph/topologicalsort/files/graph.txt");
    topologicalSort(graph);
    return 0;
}