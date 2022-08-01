//
// Created by lotushint on 2022/6/9.
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
} DoubleNode;

/**
 * 建立一个空的单链表
 * @return 指向 DoubleNode 类型变量的指针
 */
DoubleNode *init() {
    return NULL;
}

/**
 * 输出单链表中各个结点的值
 * @param head 指向 DoubleNode 类型变量的指针 head
 */
void display(DoubleNode *head) {
    DoubleNode *p;
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
 * @param head 指向 DoubleNode 类型变量的指针 head
 * @param i int 类型的变量 i
 * @return 指向 DoubleNode 类型变量的指针
 */
DoubleNode *find(DoubleNode *head, int i) {
    DoubleNode *p;
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
 * @param head 指向 DoubleNode 类型变量的指针 head
 * @param x datatype 类型的变量 x
 * @param i int 类型的变量 i
 * @return 指向 DoubleNode 类型变量的指针
 */
DoubleNode *insert(DoubleNode *head, datatype x, int i) {
    DoubleNode *p, *q;
    p = (DoubleNode *) malloc(sizeof(DoubleNode));
    p->info = x;

    if (i == 0) {
        //第一个结点之前插入
        p->leftLink = NULL;
        p->rightLink = head;
        if (!head) {
            //注意此时表为空的情形！
            head = p;
        } else {
            head->leftLink = p;
            head = p;
        }
        return head;
    } else {
        /* 找到第 i 个结点 */
        q = find(head, i);
//        while (q && i != j) {
//            q = q->rightLink;
//            j++;
//        }

        if (!q) {
            //q 为最后一个结点的 rightLink（为 NULL）,即第 i 个结点不存在
            printf("\n第%d个结点不存在,无法进行插入！\n", i);
            free(p);
            return head;
        }

        if (q->rightLink == NULL) {
            /* 最后一个结点后插入 */
            //即为 NULL,新插入的结点没有后继
            p->rightLink = q->rightLink;
            q->rightLink = p;
            p->leftLink = q;
            return head;
        } else {
            /* 插入结点 p，一般情况下的插入 */
            p->rightLink = q->rightLink;
            p->leftLink = q;
            q->rightLink->leftLink = p;
            q->rightLink = p;
            return head;
        }
    }
}

/**
 * 在双链表中删除一个值为 x 的结点
 * @param head 指向 DoubleNode 类型变量的指针 head
 * @param x datatype 类型的变量 x
 * @return 指向 DoubleNode 类型变量的指针
 */
DoubleNode *delete(DoubleNode *head, datatype x) {
    /**
     * 待指向值为 x 的结点的指针（被删除的结点）
     */
    DoubleNode *q;
    if (!head) {
        printf("双链表为空，无法进行删除操作！");
        return head;
    } else {
        q = head;
        while (q && q->info != x) {
            //循环结束后 q 指向的是值为 x 的结点
            q = q->rightLink;
        }
        if (!q) {
            //q 为最后一个结点的 rightLink（为 NULL）,即值为 x 的结点不存在
            printf("\n没有找到值为%d的结点！不做删除操作！", x);
            //return head;
        } else if (q == head && head->rightLink) {
            //q 为第一个结点,且表中不止一个结点
            head = head->rightLink;
            head->leftLink = NULL;
            free(q);
            return head;
        } else if (q == head && !head->rightLink) {
            //q 为第一个结点,且表中只有一个结点
            free(q);
            //双链表置空
            return NULL;
        } else {
            if (!q->rightLink) {
                //q 为最后一个结点
                q->leftLink->rightLink = NULL;
                free(q);
                return head;
            } else {
                //q 为两个以上结点的双链表中的一个非开始也非终端结点
                q->leftLink->rightLink = q->rightLink;
                q->rightLink->leftLink = q->leftLink;
                free(q);
                return head;
            }
        }
    }
}

#endif //DATASTRUCTURE_DOUBLYLINKEDLIST_H
