//
// Created by lotushint on 2022/6/15.
//

#ifndef DATASTRUCTURE_LINKEDSTACK_H
#define DATASTRUCTURE_LINKEDSTACK_H

#include "stdio.h"
#include "stdlib.h"

typedef int datatype;
typedef struct linkNode {
    datatype info;
    struct linkNode *next;
} TreeNode;

/**
 * 建立一个空的链式栈
 * @return 指向 TreeNode 类型变量的指针
 */
TreeNode *init() {
    return NULL;
}

/**
 * 判断链式栈是否为空
 * @param top 指向 TreeNode 类型变量的指针 top
 * @return int 类型的变量
 */
int empty(TreeNode *top) {
    return top ? 0 : 1;
}

/**
 * 读链式栈的栈顶结点值
 * @param top 指向 TreeNode 类型变量的指针 top
 * @return datatype 类型的变量
 */
datatype read(TreeNode *top) {
    if (!top) {
        printf("\n链式栈是空的！");
        exit(1);
    }
    return top->info;
}

/**
 * 输出链式栈中各个结点的值
 * @param top 指向 TreeNode 类型变量的指针 top
 */
void display(TreeNode *top) {
    printf("\n");
    if (!top) {
        printf("\n链式栈是空的！");
    }
    while (top) {
        printf("%5d", top->info);
        top = top->next;
    }
    printf("\n");
}

/**
 * 向链式栈插入值为 x 结点（进栈）
 * @param top 指向 TreeNode 类型变量的指针 top
 * @param x datatype 类型的变量
 * @return 指向 TreeNode 类型变量的指针
 */
TreeNode *push(TreeNode *top, datatype x) {
    TreeNode *p = (TreeNode *) malloc(sizeof(TreeNode));
    p->info = x;
    p->next = top;
    top = p;
    return top;
}

/**
 * 删除链式栈的栈顶结点（出栈）
 * @param top 指向 TreeNode 类型变量的指针 top
 * @return 指向 TreeNode 类型变量的指针
 */
TreeNode *pop(TreeNode *top) {
    TreeNode *q;
    if (!top) {
        printf("\n链式栈是空的！");
        return NULL;
    }
    q = top;
    top = top->next;
    free(q);
    return top;
}

#endif //DATASTRUCTURE_LINKEDSTACK_H
