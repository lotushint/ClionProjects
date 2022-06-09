//
// Created by hefan on 2022/5/31.
// 队列（顺序存储）是一种特殊的顺序表（顺序存储的线性表）
//

#ifndef DATASTRUCTURE_SEQUENTIALQUEUE_H
#define DATASTRUCTURE_SEQUENTIALQUEUE_H

#include <stdlib.h>
#include "stdio.h"

#define MAXSIZE 100

typedef int datatype;
typedef struct {
    datatype a[MAXSIZE];
    int front;
    int rear;
} sequence_queue;

/**
 * 队列（顺序存储）初始化
 * @param sq 指向 sequence_queue 类型变量的指针变量
 */
void init(sequence_queue *sq) {
    sq->front = sq->rear = 0;
};

/**
 * 判断队列（顺序存储）是否为空
 * @param sq sequence_queue 类型变量
 * @return 返回 1 表示空， 0 表示非空
 */
int empty(sequence_queue sq) {
    return sq.front == sq.rear ? 1 : 0;
};

/**
 * 打印队列（顺序存储）的结点值
 * @param sq sequence_queue 类型变量
 */
void display(sequence_queue sq) {
    int i;
    if (empty(sq)) {
        printf("\n顺序队列是空的！");
    } else {
        for (i = sq.front; i < sq.rear; ++i) {
            printf("%5d", sq.a[i]);
        }
    }
};

/**
 * 取得队列（顺序存储）的队首结点值
 * @param sq sequence_queue 类型变量
 * @return 返回队首结点值
 */
datatype get(sequence_queue sq) {
    if (empty(sq)) {
        printf("\n顺序队列是空的！无法获得队首结点值！");
        exit(1);
    }
    return sq.a[sq.front];
};

/**
 * 队列（顺序存储）的插入（进队）操作
 * @param sq 指向 sequence_queue 类型变量的指针变量
 * @param x datatype 类型的变量 x ，要插入的数
 */
void insert(sequence_queue *sq, datatype x) {
    if (sq->rear == MAXSIZE) {
        printf("\n顺序队列是满的！");
        exit(1);
    }
    sq->a[sq->rear++] = x;
};

/**
 * 队列（顺序存储）的删除（出队）操作
 * @param sq 指向 sequence_queue 类型变量的指针变量
 */
void delete(sequence_queue *sq) {
    if (empty(*sq)) {
        printf("顺序队列是空的！不能做删除操作！");
        exit(1);
    }
    sq->front++;
};
#endif //DATASTRUCTURE_SEQUENTIALQUEUE_H
