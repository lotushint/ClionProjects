//
// Created by hefan on 2022/6/9.
// 双链表
//

#ifndef DATASTRUCTURE_DOUBLYLINKEDLIST_H
#define DATASTRUCTURE_DOUBLYLINKEDLIST_H

#include "stdio.h"
#include "stdlib.h"

typedef int datatype;
typedef struct doubleLinkNode {
    datatype info;
    struct doubleLinkNode *leftLink, *rightLink;
} doubleNode;

/**
 * 建立一个空的单链表
 * @return 指向 doubleNode 类型变量的指针
 */
doubleNode *init() {
    return NULL;
}

/**
 * 输出单链表中各个结点的值
 * @param head 指向 doubleNode 类型变量的指针 head
 */
void display(doubleNode *head) {
    doubleNode *p;
    printf("\n");
    p = head;
    if (!p) {
        printf("\n双链表是空的！\n");
    } else {
        printf("\n双链表中各个结点的值为：\n");
        while (p) {
            printf("%5d", p->info);
            p = p->rightLink;
        }
    }
}

/**
 * 在双链表中查找第 i 个结点的存储地址
 * @param head 指向 doubleNode 类型变量的指针 head
 * @param i int 类型的变量 i
 * @return 指向 doubleNode 类型变量的指针
 */
doubleNode *find(doubleNode *head, int i) {
    doubleNode *p;
    p = head;
    if (i < 1) {
        printf("\n第%d个结点不存在！\n", i);
        return NULL;
    } else {
        for (int j = 0; j < i && p; ++j) {
            p = p->rightLink;
        }
        if (p) {
            return p;
        } else {
            printf("\n第%d个结点不存在！\n", i);
            return NULL;
        }
    }
}

/**
 * 双链表第 i 个结点后插入值为 x 的新结点
 * @param head 指向 doubleNode 类型变量的指针 head
 * @param x datatype 类型的变量 x
 * @param i int 类型的变量 i
 * @return 指向 doubleNode 类型变量的指针
 */
doubleNode *insert(doubleNode *head, datatype x, int i) {
    doubleNode *p, *q;
    q = head;
    p = (doubleNode *) malloc(sizeof(doubleNode));
    p->info = x;
    if (i < 0) {
        printf("\n \n", i);
        return NULL;
    } else if (i == 0) {
        //第一个结点之前插入
        p->leftLink = NULL;
        p->rightLink = q;
        q->leftLink = p;
        head = p;
        return head;
    } else {
        int j = 1;
        /* 找到第 i 个结点 */
        while (q && i != j) {
            q = q->rightLink;
            j++;
        }
        /* 插入结点 p */
        p->rightLink = q->rightLink;
        p->rightLink->leftLink = p;
        q->rightLink = p;
        p->leftLink = q;
    }
}

/**
 *
 * @param head
 * @param x
 * @return
 */
double *delete(doubleNode *head, datatype x) {

}

#endif //DATASTRUCTURE_DOUBLYLINKEDLIST_H
