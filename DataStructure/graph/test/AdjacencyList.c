//
// Created by lotushint on 2022/7/16.
// 邻接表
//
#include "../adjacency/adjacencylist/AdjacencyListCreation.h"

int main() {
    AdjacencyListGraph listGraph;
    createAdjacencyListGraph(&listGraph, "../graph/adjacency/files/graph.txt", 0);
    return 0;
}