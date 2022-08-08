//
// Created by lotushint on 2022/8/7.
// 平衡二叉排序树（AVL树）
//

#ifndef DATASTRUCTURE_BALANCEDBINARYSORTTREE_H
#define DATASTRUCTURE_BALANCEDBINARYSORTTREE_H

#include "stdlib.h"

typedef int dataType;
typedef struct node {
    dataType data;
    struct node *leftChild, *rightChild;
    /**
     * 结点的平衡度
     */
    int balance;
} BalancedBinaryTreeNode;
typedef BalancedBinaryTreeNode *BalancedBinaryTree;

/**
 * 对 AVL 树进行左改组
 * @param tree AVL 树二级指针变量
 */
void leftChange(BalancedBinaryTree *tree) {
    /**
     * A:tree <br> B:pointerB <br> C:pointerC
     */
    BalancedBinaryTree pointerB, pointerC;

    // pointerB -> B
    pointerB = (*tree)->leftChild;
    /*
     * LL改组
     */
    if (pointerB->balance == 1) {
        // A 的左孩子 -》 B 的右孩子
        (*tree)->leftChild = pointerB->rightChild;
        // B 的右孩子 -》 A
        pointerB->rightChild = *tree;
        // A 的平衡度为 0
        (*tree)->balance = 0;
        // B 为根
        (*tree) = pointerB;
    } else if (pointerB->balance == -1) {
        /*
         * LR改组
         */
        // pointerC -》 C
        pointerC = pointerB->rightChild;
        // B 的右孩子 -》 C 的左孩子
        pointerB->rightChild = pointerC->leftChild;
        // C 的左孩子 -》 B
        pointerC->leftChild = pointerB;
        // A 的左孩子 -》 C 的右孩子
        (*tree)->leftChild = pointerC->rightChild;
        // C 的右孩子 -》 A
        pointerC->rightChild = *tree;

        /*
         * 调整平衡度
         */
        //在 C 的左插
        if (pointerC->balance == 1) {
            // A 的平衡度改为 -1
            (*tree)->balance = -1;
            // B 的平衡度改为 0
            pointerB->balance = 0;
        } else if (pointerC->balance == -1) {
            //在 C 的右插

            // A 的平衡度为 0
            (*tree)->balance = 0;
            // B 的平衡度为 1
            pointerB->balance = 1;
        }
        // C 为根
        *tree = pointerC;
    }

    //根结点平衡度置为 0
    (*tree)->balance = 0;
}

/**
 * 对 AVL 树进行右改组
 * @param tree AVL 树二级指针变量
 */
void rightChange(BalancedBinaryTree *tree) {
    /**
     * A:tree <br> B:pointerB <br> C:pointerC
     */
    BalancedBinaryTree pointerB, pointerC;
    pointerB = (*tree)->rightChild;
    /*
     * RR 改组
     */
    if (pointerB->balance == -1) {
        // A 的右孩子 -》 B 的左孩子
        (*tree)->rightChild = pointerB->leftChild;
        // B 的左孩子 -》 A
        pointerB->leftChild = *tree;
        // A 的平衡度改为 0
        (*tree)->balance = 0;
        // B 为根
        *tree = pointerB;
    } else if (pointerB->balance == 1) {
        /*
         * RL 改组
         */
        // pointerC -> B 的左孩子
        pointerC = pointerB->leftChild;
        // B 的左孩子 -》 C 的右孩子
        pointerB->leftChild = pointerC->rightChild;
        // C 的右孩子 -》 B
        pointerC->rightChild = pointerB;
        // A 的右孩字 -》 C 的左孩子
        (*tree)->rightChild = pointerC->leftChild;
        // C 的左孩子 -》 A
        pointerC->leftChild = *tree;
        /*
         * 调整平衡度
         */
        //在 C 的左插
        if (pointerC->balance == 1) {
            // A 的平衡度改为 -1
            (*tree)->balance = 0;
            // B 的平衡度改为 0
            pointerB->balance = -1;
        } else if (pointerC->balance == -1) {
            //在 C 的右插

            // A 的平衡度为 0
            (*tree)->balance = 1;
            // B 的平衡度为 1
            pointerB->balance = 0;
        }
        // C 为根
        *tree = pointerC;
    }
    //根结点平衡度置为 0
    (*tree)->balance = 0;
}

/**
 * 平衡二叉树的插入算法
 * @param tree AVL 树二级指针变量
 * @param x 待插入结点值
 * @param h AVL 树高度指针变量
 */
void insertAvlTree(BalancedBinaryTree *tree, dataType x, int *h) {
    // tree 所在子树为空（不一定是整棵树的根结点，可能是子树的根结点）
    if (*tree == NULL) {
        *tree = (BalancedBinaryTree) malloc(sizeof(BalancedBinaryTreeNode));
        (*tree)->data = x;
        (*tree)->balance = 0;
        (*tree)->leftChild = (*tree)->rightChild = NULL;
        *h = 1;
    } else if (x < (*tree)->data) {
        /*
         * 在左子树中插入新结点
         */

    } else {
        /*
         * 在右子树中插入新结点
         */
    }
}

#endif //DATASTRUCTURE_BALANCEDBINARYSORTTREE_H
