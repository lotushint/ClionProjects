//
// Created by lotushint on 2022/7/13.
// 穿线二叉树——中序穿线二叉树的创建（链式存储）
// 1.首先创建一棵一般的二叉树
// 2.然后对其进行中序穿线操作
//

#ifndef DATASTRUCTURE_INORDERTHREADINGBINARYTREECREATION_H
#define DATASTRUCTURE_INORDERTHREADINGBINARYTREECREATION_H

#include <stdio.h>
#include <malloc.h>
#include "../storage/InorderThreadingBinaryTreeStorage.h"

/**
 * 初始化前驱结点
 */
ThreadBinaryTree pre = NULL;

/**
 * 根据 前序遍历 结果创建二叉树
 * @return 树根地址
 */
ThreadBinaryTree createBinaryTree() {
    char c;
    ThreadBinaryTree root;
    if ((c = getchar()) == '#') {
        root = NULL;
    } else {
        root = (ThreadBinaryTree) malloc(sizeof(ThreadBinaryTreeNode));
        root->data = c;
        root->leftChild = createBinaryTree();
        root->rightChild = createBinaryTree();
    }
    return root;
}

/**
 * 对二叉树进行中序线索化
 * @param tree 树根地址
 */
void inorderThreading(ThreadBinaryTree *tree) {
    if (*tree) {
        inorderThreading(&(*tree)->leftChild);
        (*tree)->leftTag = (*tree)->leftChild ? 0 : 1;
        (*tree)->rightTag = (*tree)->rightChild ? 0 : 1;
        if (pre) {
            if (pre->rightTag == 1) {
                pre->rightChild = *tree;
            }
            if ((*tree)->leftTag == 1) {
                (*tree)->leftChild = pre;
            }
        }
        pre = *tree;
        inorderThreading(&(*tree)->rightChild);
    }
}

/**
 * 创建中序穿线二叉树
 * @param tree 树根地址
 */
void createThreadingBinaryTree(ThreadBinaryTree *tree) {
    *tree = createBinaryTree();
    inorderThreading(tree);
}

#endif //DATASTRUCTURE_INORDERTHREADINGBINARYTREECREATION_H
