//
// Created by lotushint on 2022/6/26.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include <stdio.h>
#include <malloc.h>

typedef char datatype;
typedef struct node {
    datatype data;
    struct TreeNode *leftChild, *rightChild;
    struct TreeNode *parent;
} BinaryNode;
typedef BinaryNode *BinaryTree;
/**
 * 指向二叉树更结点的指针
 */
BinaryTree root;

/**
 * 前序遍历
 * @param tree 指向二叉树根结点的指针
 */
void preorderTraversal(BinaryTree tree) {
    if (tree) {
        printf("%c", tree->data);
        preorderTraversal(tree->leftChild);
        preorderTraversal(tree->rightChild);
    }
}

/**
 * 中序遍历
 * @param tree 指向二叉树根结点的指针
 */
void inorderTraversal(BinaryTree tree) {
    if (tree) {
        inorderTraversal(tree->leftChild);
        printf("%c", tree->data);
        inorderTraversal(tree->rightChild);
    }
}

/**
 * 后序遍历
 * @param tree 指向二叉树根结点的指针
 */
void postorderTraversal(BinaryTree tree) {
    if (tree) {
        inorderTraversal(tree->leftChild);
        inorderTraversal(tree->rightChild);
        printf("%c", tree->data);
    }
}

/**
 * 根据前序遍历结果创建一颗给定二叉树
 * @return 二叉树树根地址
 */
BinaryTree createBinaryTree() {
    char c;
    BinaryTree tree;
    if ((c = getchar()) == '#') {
        tree = NULL;
    } else {
        tree = (BinaryNode *) malloc(sizeof(BinaryNode));
        tree->data = c;
        tree->leftChild = createBinaryTree();
        tree->rightChild = createBinaryTree();
    }
    return tree;
}

#endif //DATASTRUCTURE_BINARYTREE_H
