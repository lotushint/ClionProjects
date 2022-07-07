//
// Created by lotushint on 2022/7/7.
// 一般二叉树的顺序存储
//

#ifndef DATASTRUCTURE_GENERALBINARYTREE_H
#define DATASTRUCTURE_GENERALBINARYTREE_H
#define MAXSIZE 20
typedef char datatype;
typedef struct {
    datatype data;
    /**
     * 存放左、右子女的下标
     */
    int leftChild, rightChild;
} Node;
Node tree[MAXSIZE];
/**
 * 树中实际所含结点的个数
 */
int n;
/**
 * 存放根结点的下标
 */
int root;
#endif //DATASTRUCTURE_GENERALBINARYTREE_H
