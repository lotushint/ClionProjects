//
// Created by hefan on 2022/6/1.
// 带头结点的单链表
//

#ifndef DATASTRUCTURE_LEADINGNODESINGLYLINKEDTABLE_H
#define DATASTRUCTURE_LEADINGNODESINGLYLINKEDTABLE_H

#include <malloc.h>
#include "stdio.h"

typedef int datatype;
typedef struct linkNode {
    datatype info;
    struct linkNode *next;
} node;

/**
 * 建立一个空的带头结点的单链表
 * @return 指向 node 类型变量的指针
 */
node *init() {
    node *head;
    //注意这里初始化
    head = (node *) malloc(sizeof(node));
    head->next = NULL;
    return head;
}

/**
 * 输出带头结点的单链表中各个结点的值
 * @param head 指向 node 类型变量的指针
 */
void display(node *head) {
    node *p;
    //从第一个（实际）结点开始
    p = head->next;
    if (!p) {
        printf("\n带头结点的单链表是空的！");
    } else {
        printf("\n带头结点的单链表各个结点的值为：\n");
        while (p) {
            printf("%5d", p->info);
            p = p->next;
        }
    }
}

/**
 * 在带头结点的单链表中查找第 i 个结点 地址
 * @param head 指向 node 类型变量的指针
 * @param i int 类型变量
 * @return 指向 node 类型变量的指针，头指针
 */
node *find(node *head, int i) {
    int j = 0;
    node *p;
    p = head;
    if (i < 0) {
        printf("\n带头结点的单链表中不存在第%d个结点！", i);
        return NULL;
    } else if (i == 0) {
        //此时 p 指向的是头结点
        return p;
    }
    while (p && i != j) {
        p = p->next;
        j++;
    }
    //i == 0 时，p 指向的是头结点
    return p;
}

/**
 * 在带头结点的中单链表第 i 个结点后插入值为 x 的新结点
 * @param head 指向 node 类型变量的指针，头指针
 * @param x datatype 类型变量
 * @param i int类型变量
 * @return 指向 node 类型变量的指针，头指针 head
 */
node *insert(node *head, datatype x, int i) {
    /**
    * p:动态获取存储空间
    * q:第 i 个结点
    */
    node *p, *q;
    q = find(head, i);
    //如果没有找到
    if (!q) {
        printf("\n带头结点的单链表中不存在第%d个结点！不能插入%d!", i, x);
        return head;
    }
    p = (node *) malloc(sizeof(node));
    p->info = x;
    p->next = q->next;
    q->next = p;
    return head;
}

/**
 * 在带头结点的单链表中删除一个值为 x 的结点
 * @param head 指向 node 类型变量的指针，头指针
 * @param x datatype 类型变量
 * @return 指向 node 类型变量的指针
 */
node *delete(node *head, datatype x) {
    /**
     * pre:q的前驱结点
     * q:要删除的结点
     */
    node *pre = head, *q;
    if (!head->next) {
        printf("带头结点的单链表是空的！");
        return head;
    }
    //从第一个（实际）结点开始
    q = head->next;
    while (q && q->info != x) {
        pre = q;
        q = q->next;
    }
    if (!q) {
        printf("\n没找到值为%d的结点！", x);
    } else {
        printf("\n删除值为%d的结点成功！", x);
        pre->next = q->next;
        free(q);
    }
    return head;
}

#endif //DATASTRUCTURE_LEADINGNODESINGLYLINKEDTABLE_H
