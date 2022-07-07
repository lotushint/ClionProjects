//
// Created by lotushint on 2022/7/7.
// 二叉树的存储结构——链式存储扩展（增加了一个指针域指向结点的双亲）
//

#ifndef DATASTRUCTURE_BINARYTREESTRUCTURE2_H
#define DATASTRUCTURE_BINARYTREESTRUCTURE2_H

typedef char datatype;
typedef struct Node {
    datatype data;
    struct Node *leftChild, *rightChild;
    /**
     * 指向双亲结点的指针
     */
    struct Node *parent;
} BinaryTreeNode;
typedef BinaryTreeNode *BinaryTree;
/**
 * 指向二叉树根结点的指针
 */
BinaryTree root;
#endif //DATASTRUCTURE_BINARYTREESTRUCTURE2_H
