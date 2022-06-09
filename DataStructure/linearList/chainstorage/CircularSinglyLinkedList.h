//
// Created by hefan on 2022/6/4.
// 循环单链表
//

#ifndef DATASTRUCTURE_circularSINGLYLINKEDLIST_H
#define DATASTRUCTURE_circularSINGLYLINKEDLIST_H

#include "SinglyLinkedList.h"

/**
 * 建立一个空的循环单链表
 * @return 指向 node 类型变量的指针
 */
node *circularInit() {
    return NULL;
}

/**
 * 获得循环单链表的最后一个结点的存储地址
 * @param head 指向 node 类型的指针变量 head
 * @return 指向 node 类型变量的指针
 */
node *circularRear(node *head) {
    node *p;
    p = head;
    while (p && p->next != head) {
        p = p->next;
    }
    return p;
}

/**
 * 输出循环单链表中各个结点的值
 * @param head 指向 node 类型的指针变量 head
 */
void circularDisplay(node *head) {
    node *p;
    if (!head) {
        printf("\n循环单链表是空的！\n");
    } else {
//        printf("\n循环单链表各个结点的值分别为：\n");
//        //输出非空表达中第一个结点的值
//        printf("%5d", head->info);
//        p = head->next;
//        //p 指向头结点结束
//        while (p != head) {
//            printf("%5d", p->info);
//            p = p->next;
//        }

        p = head;
        printf("\n循环单链表各个结点的值分别为：\n");
        while (p != circularRear(head)) {
            printf("%5d", p->info);
            p = p->next;
        }
        //输出非空表达中最后一个结点的值
        printf("%5d", p->info);
    }
}

/**
 * 循环单链表中查找值为 x 的结点的存储地址
 * @param head 指向 node 类型变量的指针变量 head
 * @param x datatype 类型的变量 x，要查找的值
 * @return 指向 node 类型变量的指针
 */
node *circularFind(node *head, datatype x) {
    node *p;
    p = head;
    if (!head) {
        printf("\n循环单链表是空的！无法找指定结点！\n");
        return NULL;
    }
//    p = head;
//    while (p->next != head && p->info != x) {
//        p = p->next;
//    }

    while (p != circularRear(head)) {
        if (p->info == x) {
            return p;
        }
        p = p->next;
    }

    if (p->info == x) {
        return p;
    }
    return NULL;
}

/**
 * 循环单链表第 i 个结点后插入值为 x 的新结点<br>
 * 注意：插入的结点成为表中第一个结点，那么必须修改表中最后一个结点的指针域
 * @param head 指向 node 类型变量的指针变量 head
 * @param x 类型的变量 x，要插入的值
 * @param i 要插入的结点的前驱结点位置
 * @return 指向 node 类型变量的指针
 */
node *circularInsert(node *head, datatype x, int i) {
    /**
     * 待插入结点
     */
    node *p;
    /**
     * 指针
     */
    node *q;
    /**
     * 尾结点指针
     */
    node *rear;
    p = (node *) malloc(sizeof(node));
    p->info = x;

    if (i < 0) {
        printf("\n无法找到指定的插入位置！\n");
        free(p);
        return head;
    } else if (i == 0) { //在单链表的最前面插入
        //head 为空，即单链表是空的
        if (!head) {
            head = p;
            head->next = head;
            return head;
        } else {//head 非空，即单链表是非空的
            rear = circularRear(head);
            p->next = head;
            head = p;
            rear->next = head;
            return head;
        }
    } else if (i > 0) {
        if (!head) {
            printf("\n无法找到指定的插入位置！\n");
            free(p);
            return head;
        } else {
            q = head;
            int j = 1;
            //找到第 i 个结点
            for (; j != i && q != circularRear(head); ++j) {
                q = q->next;
            }
            //找不到指定插入位置，即 i 的值超过表中结点的个数，则不进行插入
            if (i != j) {
                printf("\n表中不存在第%d个结点，无法进行插入！\n", i);
                free(p);
                return head;
            } else {
                p->next = q->next;
                q->next = p;
                return head;
            }
        }
    }
}

/**
 * 在循环单链表中删除一个值为 x 的结点
 * @param head 指向 node 类型变量的指针变量 head
 * @param x datatype类型的变量 x，要删除的数值
 * @return 指向 node 类型变量的指针
 */
node *circularDelete(node *head, datatype x) {
    /**
     * 指针
     */
    node *q, *pre = NULL;
    q = head;
    //表为空，则无法做删除操作
    if (!head) {
        printf("\n循环单链表为空，无法做删除操作！\n");
        return head;
    } else {
        while (q->info != x && q != circularRear(head)) {
            pre = q;
            q = q->next;
        }
        //没找到 x
        if (q->info != x) {
            printf("没有找到值为%d的结点！", x);
        } else {//找到了下面要删除 q
            if (q != head) {//删除非第一个结点（包括最后一个结点）
                pre->next = q->next;
                free(q);
            } else if (head->next == head) {//删除第一个结点，表中只有一个结点——头结点
                free(q);
                head = NULL;
            } else {//删除第一个结点
                //第一种方法
//                pre = head->next;
//                //找 q 的前驱结点的位置,当删除第一个结点时，前面 while 循环可能不执行
//                while (pre->next != q) {
//                    pre = pre->next;
//                }

                //第二种方法
                //表中第一个结点的前驱结点是最后一个结点
                pre = circularRear(head);

                head = head->next;
                pre->next = head;
                free(q);
            }
        }
    }
    return head;
}

#endif //DATASTRUCTURE_circularSINGLYLINKEDLIST_H
