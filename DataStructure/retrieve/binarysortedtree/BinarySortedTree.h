//
// Created by lotushint on 2022/8/4.
// 二叉排序树
//

#ifndef DATASTRUCTURE_BINARYSORTEDTREE_H
#define DATASTRUCTURE_BINARYSORTEDTREE_H

#include "stdio.h"
#include "stdlib.h"

typedef int dataType;
/**
 * 二叉排序树结点定义
 */
typedef struct node {
    /**
     * 结点值
     */
    dataType data;
    /**
     * 左、右孩子指针
     */
    struct node *leftChild, *rightChild;
} BinarySortedTreeNode;
typedef BinarySortedTreeNode *BinarySortedTree;

/**
 * 二叉排序树的 非递归 查找算法
 * @param tree 二叉排序树
 * @param key 待查找关键字
 * @param parentPosition 父结点地址（二叉树结点二级指针）
 * @param position 待查找关键字所在地址（二叉树结点二级指针）
 */
void binarySortedSearch1(BinarySortedTree tree, dataType key,
                         BinarySortedTree *parentPosition,
                         BinarySortedTree *position) {
    *parentPosition = NULL;
    *position = tree;
    while (*position) {
        if (key == (*position)->data) {
            return;
        }
        *parentPosition = *position;
        *position = key < (*position)->data ? (*position)->leftChild : (*position)->rightChild;
    }
}

/**
 * 二叉排序树的 递归 算法
 * @param tree 二叉排序树
 * @param key 待查找关键字
 * @return 若查找成功，则返回关键字 key 在树中的结点地址；否则，返回空
 */BinarySortedTree binarySortedSearch2(BinarySortedTree tree, dataType key) {
    //树为空，或根结点即为待查找结点
    if (!tree || key == tree->data) {
        return tree;
    } else {
        if (key < tree->data) {
            //递归的在右子树中检索
            return binarySortedSearch2(tree->leftChild, key);
        } else {
            //递归的在左子树中检索
            return binarySortedSearch2(tree->rightChild, key);
        }
    }
}

/**
 * 在二叉排序树中插入结点值为 x 的结点
 * @param tree 二叉排序树（二叉树结点二级指针）
 * @param x 待插入结点值
 */
void insertBinarySortedTree(BinarySortedTree *tree, dataType x) {
    BinarySortedTreeNode *p;
    /**
     * 保存即将插入的结点的父节点
     */
    BinarySortedTreeNode *pre;
    p = *tree;
    //查找插入位置
    while (p) {
        //若二叉排序树中已有 x ，则无需插入
        if (x == p->data) {
            return;
        }
        //保存此次节点地址
        pre = p;
        p = x < p->data ? p->leftChild : p->rightChild;
    }

    //生成待插入的新结点
    p = (BinarySortedTreeNode *) malloc(sizeof(BinarySortedTreeNode));
    p->data = x;
    p->leftChild = p->rightChild = NULL;

    //树为空
    if (!*tree) {
        *tree = p;
    } else {
        if (x < pre->data) {
            pre->leftChild = p;
        } else {
            pre->rightChild = p;
        }
    }
}

/**
 * 二叉排序树的建立算法
 * @return 所建立的二叉排序树的根结点地址
 */
BinarySortedTree creatBinarySortedTree() {
    BinarySortedTree tree;
    dataType x;

    printf("\n请输入一个以 -1 为结束标记的结点序列：\n");
    scanf("%d", &x);
    while (x != -1) {
        insertBinarySortedTree(&tree, x);
        scanf("%d", &x);
    }
    return tree;
}

/**
 * 在二叉排序树中删除结点值为 x 的结点
 * @param tree 二叉排序树
 * @param x 待删除结点值
 * @return 删除结点后的二叉树地址
 */
BinarySortedTree deleteBinaryTreeNode(BinarySortedTree tree, dataType x) {
    /**
     * parentPosition:被删除结点的父结点<br>
     * position:被删除结点<br>
     * child:情况 4 中用来找到被删除结点的中序首点<br>
     */
    BinarySortedTreeNode *parentPosition, *position, *child;
    //查找待删除结点
    binarySortedSearch1(tree, x, &parentPosition, &position);
    //找到了待删除结点
    if (position) {
        /*
         * 情况 1：被删除结点为叶结点
         */
        if (position->leftChild == NULL && position->rightChild == NULL) {
            //待删除结点有双亲
            if (parentPosition) {
                if (position == parentPosition->leftChild) {
                    parentPosition->leftChild = NULL;
                } else {
                    parentPosition->rightChild = NULL;
                }
            } else {
                //被删除结点为树根
                tree = NULL;
            }
            free(position);
        } else if (position->rightChild == NULL) {
            /*
             * 情况 2：被删除结点的右子树为空，
             * 用被删除结点的左子树代替该结点
             */
            //被删除结点的双亲结点不为空
            if (parentPosition) {
                if (parentPosition->leftChild == position) {
                    //被删除结点是其双亲结点的左儿子
                    parentPosition->leftChild = position->leftChild;
                } else {
                    //被删除结点是其双亲结点的右儿子
                    parentPosition->rightChild = position->leftChild;
                }
            } else {
                tree = position->leftChild;
            }
            free(position);
        } else if (position->leftChild == NULL) {
            /*
             * 情况 3：被删除结点的左子树为空，
             * 用被删除结点的右子树代替该结点
             */
            //被删除结点的双亲结点不为空
            if (parentPosition) {
                if (parentPosition->leftChild == position) {
                    parentPosition->leftChild = position->rightChild;
                } else {
                    parentPosition->rightChild = position->rightChild;
                }
            } else {
                tree = position->rightChild;
            }
            free(position);
        } else {
            /*
             * 情况 4：被删除结点的左右子树均不为空，
             * 用右子树代替被删结点，同时将被删结点的左子树收为右子树中序首点的儿子
             */
            child = position->rightChild;
            //找到被删结点的右子树的中序首点
            while (child->leftChild) {
                child = child->leftChild;
            }

            //被删除结点的左子树收为 child 的左孩子
            child->leftChild = position->leftChild;
            //被删结点不是树根
            if (position) {
                if (parentPosition->leftChild == position) {
                    parentPosition->leftChild = position->rightChild;
                } else {
                    parentPosition->rightChild = position->rightChild;
                }
            } else {
                //被删除结点为树根
                tree = position->rightChild;
            }
            free(position);
        }
    }
    return tree;
}

#endif //DATASTRUCTURE_BINARYSORTEDTREE_H
