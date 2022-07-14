//
// Created by lotushint on 2022/7/13.
// 穿线二叉树——中序穿线二叉树的链式存储
//

#ifndef DATASTRUCTURE_INORDERTHREADINGBINARYTREESTORAGE_H
#define DATASTRUCTURE_INORDERTHREADINGBINARYTREESTORAGE_H
typedef char datatype;
typedef struct node {
    datatype data;
    /**
     * 左标志位：为 0 指向其左子女；为 1 指向其中序遍历的前驱结点
     */
    int leftTag;
    /**
     * 右标志位：为 0 指向其右子女；为 1 指向其中序遍历的后继结点
     */
    int rightTag;
    struct node *leftChild, *rightChild;
} ThreadBinaryTreeNode;
typedef ThreadBinaryTreeNode *ThreadBinaryTree;

#endif //DATASTRUCTURE_INORDERTHREADINGBINARYTREESTORAGE_H
