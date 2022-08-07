//
// Created by lotushint on 2022/8/5.
// 丰满树
//

#ifndef DATASTRUCTURE_PLUMPTREE_H
#define DATASTRUCTURE_PLUMPTREE_H

#include "stdio.h"
#include "stdlib.h"

typedef int dataType;
/**
 * 二叉树结点定义
 */
typedef struct node {
    dataType data;
    struct node *leftChild, *rightChild;
} BinaryTreeNode;
typedef BinaryTreeNode *BinaryTree;

/**
 * 平分法创建一棵丰满树
 * @param node 存放结点的向量
 * @param low 向量起点
 * @param high 向量终点
 * @return 所建立的丰满树的地址
 */
BinaryTree createPlumpTree(int node[], int low, int high) {
    int mid;
    BinaryTree tree;
    if (low <= high) {
        mid = (low + high) / 2;
        tree = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
        tree->data = node[mid];
        //平分法建左子树
        tree->leftChild = createPlumpTree(node, low, mid - 1);
        //平分法建右子树
        tree->rightChild = createPlumpTree(node, mid + 1, high);
        return tree;
    } else {
        return NULL;
    }
}

#endif //DATASTRUCTURE_PLUMPTREE_H
