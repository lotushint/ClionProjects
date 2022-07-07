//
// Created by lotushint on 2022/7/5.
// 将树的层号表示转换成树的扩充孩子表示（增加一个域指向结点双亲的下标）
//

#ifndef DATASTRUCTURE_LEVELTOCHILDREPRESENTATION_H
#define DATASTRUCTURE_LEVELTOCHILDREPRESENTATION_H
#define m 4 //树的度数
#define MAXSIZE 20 //数组元素个数的最大值

#include "stdio.h"

typedef char datatype;
/**
 * 树的扩充孩子表示法中结点的类型
 */
typedef struct Node {
    datatype data;
    int child[m];
    /**
     * 增加一个域指向结点双亲的下标
     */
    int parent;
} TreeNode;

/**
 * 层号表示法中结点的类型
 */
typedef struct {
    datatype data;
    /**
     * 存储结点的层号
     */
    int level;
} LevelNode;

/**
 * 树的扩充孩子表示法的存储数组
 */
TreeNode tree[MAXSIZE];
/**
 * 根结点的下标
 */
int root;
/**
 * 树中实际所含结点的个数
 */
int length;

/**
 * 树层号表示法的数组
 */
LevelNode level[MAXSIZE];

/**
 * 将树的层号表示法转换成树的扩充孩子表示法
 * @param len 树的实际结点长度
 * @param levelNode 树层号表示数组
 * @param treeNode 树结点数组
 * @param rootPointer 树根的地址
 */
void levelToChildRepresentation(int len, LevelNode levelNode[], TreeNode treeNode[], int *rootPointer) {
    int i, j, k;
    for (i = 0; i < len; ++i) {
        for (j = 0; j < m; ++j) {
            treeNode[i].child[j] = -1;
        }
    }
    /**
     * 第一个元素为根结点
     */
    *rootPointer = 0;
    /*
     * 根结点转换
     */
    treeNode[0].data = levelNode[0].data;
    //根结点没有双亲
    treeNode[0].parent = -1;

    //根结点后面的结点开始转换
    for (i = 1; i < len; ++i) {
        treeNode[i].data = levelNode[i].data;

        j = i - 1;
        //结点 i 为其前一个元素 j 的 第一个子女
        if (levelNode[i].level > levelNode[j].level) {
            treeNode[j].child[0] = i;
            treeNode[i].parent = j;
        } else {
            //寻找结点 i 的 兄弟（结点 j 的祖辈）
            while (levelNode[i].level < levelNode[j].level) {
                j = treeNode[j].parent;
            }
            //结点 i 和 j 的双亲相同
            treeNode[i].parent = treeNode[j].parent;

            //j 赋值为 i 和 j 的双亲
            j = treeNode[j].parent;
            k = 0;
            //找到结点 j 第一个空子女
            while (treeNode[j].child[k] != -1) {
                k++;
            }
            //挂上 i 结点
            treeNode[j].child[k] = i;
        }
    }
}


/**
 * 树的前序遍历
 * @param treeNodes 树的结点数组
 * @param treeRoot 树根的下标
 */
void preorderTraverse(TreeNode node[], int treeRoot) {
    printf("%c", node[treeRoot].data);
    for (int i = 0; i < m; ++i) {
        if (node[treeRoot].child[i] != -1) {
            preorderTraverse(node, node[treeRoot].child[i]);
        }
    }
}

#endif //DATASTRUCTURE_LEVELTOCHILDREPRESENTATION_H
