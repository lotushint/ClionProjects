//
// Created by lotushint on 2022/6/15.
//

#ifndef DATASTRUCTURE_CHAINEDQUEUE_H
#define DATASTRUCTURE_CHAINEDQUEUE_H

#include "stdlib.h"
#include "stdio.h"

typedef int datatype;
typedef struct linkNode {
    datatype info;
    struct linkNode *next;
} node;

typedef struct {
    //定义队首和队尾指针
    node *front, *rear;
} queue;

/**
 * 建立一空的链式队列
 * @return 指向 queue 类型变量的指针
 */
queue *init() {
    queue *qu;
    qu = (queue *) malloc(sizeof(queue));
    qu->front = NULL;
    qu->rear = NULL;
    return qu;
}

/**
 * 判断链式队列是否为空
 * @param queue queue 类型的变量 qu
 * @return int 类型
 */
int empty(queue queue) {
    return queue.front ? 0 : 1;
}

/**
 * 输出链式队列中各个结点的值
 * @param queue 指向 queue 类型的指针变量 queue
 */
void display(queue *queue) {//去 * 试一下
    node *p;
    printf("\n");
    p = queue->front;
    if (!p) {
        printf("\n链式队列是空的！\n");
    }
    while (p) {
        printf("%5d", p->info);
        p = p->next;
    }
}

/**
 * 取得链式队列的队首结点值
 * @param queue queue 类型的变量 queue
 * @return datatype 类型
 */
datatype read(queue queue) {
    if (!queue.front) {
        printf("\n链式队列是空的！\n");
        exit(1);
    }
    return queue.front->info;
}

/**
 * 向链式队列中插入一个值为 x 的结点
 * @param queue queue 类型变量的指针变量 queue
 * @param x datatype 类型的变量 x
 * @return 指向 queue 类型变量的指针
 */
queue *insert(queue *queue, datatype x) {
    node *p;
    p = (node *) malloc(sizeof(node));
    p->info = x;
    //注意！！！！！！！！！
    p->next = NULL;

    //当前队列为空
    if (!queue->front) {
        queue->front = queue->rear = p;
    } else {
        queue->rear->next = p;
        queue->rear = p;
    }
    return queue;
}

/**
 * 删除链式队列中的队首结点
 * @param queue 指向 queue 类型变量的指针变量 queue
 * @return 指向 queue 类型变量的指针
 */
queue *delete(queue *queue) {
    node *q;
    q = queue->front;
    if (!queue->front) {
        printf("\n队列为空，无法删除！\n");
    }
    queue->front = q->next;
    free(q);
    if (!queue->front) {
        //队列中的唯一结点被删除后，队列变空
        queue->rear = NULL;

    }
    return queue;
}

#endif //DATASTRUCTURE_CHAINEDQUEUE_H
