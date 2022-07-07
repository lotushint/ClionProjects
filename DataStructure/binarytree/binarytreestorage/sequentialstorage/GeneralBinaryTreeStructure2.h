//
// Created by lotushint on 2022/7/7.
// 一般二叉树的顺序存储扩展（增加一个存放双亲下标的域）
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
    /**
     * 存放双亲结点的下标
     */
    int parent;
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
