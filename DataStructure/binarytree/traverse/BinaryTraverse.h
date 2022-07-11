//
// Created by lotushint on 2022/6/26.
// 二叉树的遍历（递归方式）
//

#ifndef DATASTRUCTURE_BINARYTRAVERSE_H
#define DATASTRUCTURE_BINARYTRAVERSE_H

#include <stdio.h>
#include <malloc.h>
#include "../binarytreestorage/linkedstorage/BinaryTreeStructure2.h"

/**
 * 前序遍历（递归方式）
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
 * 中序遍历（递归方式）
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
 * 后序遍历（递归方式）
 * @param tree 指向二叉树根结点的指针
 */
void postorderTraversal(BinaryTree tree) {
    if (tree) {
        postorderTraversal(tree->leftChild);
        postorderTraversal(tree->rightChild);
        printf("%c", tree->data);
    }
}


#endif //DATASTRUCTURE_BINARYTRAVERSE_H
