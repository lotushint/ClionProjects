//
// Created by lotushint on 2022/7/7.
// 二叉树的存储结构——链式存储
//

#ifndef DATASTRUCTURE_BINARYTREESTRUCTURE_H
#define DATASTRUCTURE_BINARYTREESTRUCTURE_H

typedef char datatype;
typedef struct Node {
    datatype data;
    struct TreeNode *leftChild, *rightChild;
} BinaryTreeNode;
typedef BinaryTreeNode *BinaryTree;
/**
 * 指向二叉树根结点的指针
 */
BinaryTree root;
#endif //DATASTRUCTURE_BINARYTREESTRUCTURE_H
