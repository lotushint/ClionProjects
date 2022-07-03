//
// Created by lotushint on 2022/7/3.
//

#ifndef DATASTRUCTURE_TRAVERSE_H
#define DATASTRUCTURE_TRAVERSE_H

#include <malloc.h>
#include "../treestoragestructure/ChildRepresentation1.h"
#include "stdio.h"

/**
 * 树的前序遍历
 * @param p 指向数根结点的指针
 */
void preorderTraversal(treeNode p) {
    if (p) {
        printf("%c", p->data);
        for (int i = 0; i < m; ++i) {
            preorderTraversal(p->child[i]);
        }
    }
}

/**
 * 树的后序遍历
 * @param p 指向数根结点的指针
 */
void postorderTraversal(treeNode p) {
    if (p) {
        for (int i = 0; i < m; ++i) {
            postorderTraversal(p->child[i]);
        }
        printf("%c", p->data);
    }
}

/**
 * 根据树的前序遍历结果建立一个 3 度树
 * @return 树根地址
 */
treeNode createTree() {
    treeNode t;
    char c;
    if ((c = getchar()) == '#') {
        t = NULL;
    } else {
        t = (treeNode) malloc(sizeof(TreeNode));
        t->data = c;
        for (int i = 0; i < 3; ++i) {
            t->child[i] = createTree();
        }
    }
    return t;
}

/**
 * 树的层次遍历
 * @param t 指向数根结点的指针
 */
void levelTraversal(treeNode t) {
    /**
     * 存放等待访问的结点序列
     */
    treeNode queue[100];
    /**
     * 指向树结点的指针
     */
    treeNode p;
    /**
     * front:队头<br>
     * rear:队尾
     */
    int front = 0, rear = 1;
    queue[0] = t;

    //队列不为空
    while (front < rear) {
        //出队
        p = queue[front++];
        printf("%c", p->data);

        //p 的儿子进队
        for (int i = 0; i < m; ++i) {
            if (p->child[i]) {
                queue[rear++] = p->child[i];
            }
        }
    }
}

#endif //DATASTRUCTURE_TRAVERSE_H
