//
// Created by hefan on 2022/6/1.
// 单链表
//

#ifndef DATASTRUCTURE_SINGLYLINKEDLIST_H
#define DATASTRUCTURE_SINGLYLINKEDLIST_H

#include <malloc.h>
#include "stdio.h"

typedef int datatype;
typedef struct linkNode {
    datatype info;
    struct linkNode *next;
} TreeNode;

/**
 * 建立一个空的单链表
 * @return 指向 TreeNode 类型变量的指针
 */
TreeNode *init() {
    return NULL;
}

/**
 * 输出单链表中各个结点的值
 * @param head 指向 TreeNode 类型变量的指针，头指针
 */
void display(TreeNode *head) {
    TreeNode *p;
    p = head;
    if (!p) {
        printf("\n单链表是空的！");
    } else {
        printf("\n单链表中各个结点的值为：\n");
        while (p != NULL) {
            printf("%5d", p->info);
            p = p->next;
        }
    }
}

/**
 * 在单链表中查找第 i 个结点的存放地址
 * @param head 指向 TreeNode 类型变量的指针，头指针
 * @param i int类型变量
 * @return 指向 TreeNode 类型变量的指针
 */
TreeNode *find(TreeNode *head, int i) {
    int j = 1;
    TreeNode *p;
    p = head;
    if (i < 1) {
        return NULL;
    }
    while (p && j != i) {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * 单链表第 i 个结点后插入值为 x 的新结点
 * @param head 指向 TreeNode 类型变量的指针，头指针
 * @param x datatype 类型变量
 * @param i int类型变量
 * @return 指向 TreeNode 类型变量的指针，头指针 head
 */
TreeNode *insert(TreeNode *head, datatype x, int i) {
    /**
     * p:动态获取存储空间
     * q:第 i 个结点
     */
    TreeNode *p, *q;
    q = find(head, i);
    if (!q && i != 0) {
        printf("\n找不到第%d个结点，不能插入%d!", i, x);
    } else {
        /**
         * 分配空间
         */
        p = (TreeNode *) malloc(sizeof(TreeNode));
        p->info = x;
        /**
         * 插入时分为头部和不是头部
         */
        if (i == 0) {
            //插入的结点作为单链表的第一个结点
            p->next = head;
            head = p;
        } else {
            p->next = q->next;
            q->next = p;
        }
    }
    return head;
}

/**
 * 在单链表中删除一个值为 x 的结点
 * @param head 指向 TreeNode 类型变量的指针，头指针
 * @param x datatype 类型变量
 * @return 指向 TreeNode 类型变量的指针
 */
TreeNode *delete(TreeNode *head, datatype x) {
    /**
     * pre:q的前驱结点
     * q:要删除的结点
     */
    TreeNode *pre = NULL, *q;
    if (!head) {
        printf("单链表是空的！");
        return head;
    }
    q = head;
    while (q && q->info != x) {
        pre = q;
        q = q->next;
    }

    if (q) {
        if (!pre) {
            //要删除第一个结点
            head = head->next;
        } else {
            pre->next = q->next;
            free(q);
        }
    }
    return head;
}
#endif //DATASTRUCTURE_SINGLYLINKEDLIST_H
