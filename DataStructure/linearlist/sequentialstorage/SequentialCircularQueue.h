//
// Created by hefan on 2022/5/31.
// 循环队列的顺序存储结构的 c 语言描述和一般队列一致
// 主要区别在判断队空和队满的条件以及相关操作中指针增 1 的表达上
// 牺牲一个数组元素空间
//

#ifndef DATASTRUCTURE_SEQUENTIALCIRCULARQUEUE_H
#define DATASTRUCTURE_SEQUENTIALCIRCULARQUEUE_H

#include "SequentialQueue.h"

/**
 * 判断循环队列（顺序存储）是否为空
 * @param sq sequence_queue 类型变量
 * @return 返回 1 表示空， 0 表示非空
 */
int emptyCircularQueue(sequence_queue sq) {
    return sq.front == sq.rear ? 1 : 0;
};

/**
 * 打印循环队列（顺序存储）的结点值
 * @param sq sequence_queue 类型变量
 */
void displayCircularQueue(sequence_queue sq) {
    int i;
    if (emptyCircularQueue(sq)) {
        printf("\n顺序循环队列是空的！");
    } else {
        for (i = sq.front; i < sq.rear; ++i) {
            printf("%5d", sq.a[i]);
        }
    }
};

/**
 * 循环队列（顺序存储）的插入操作
 * @param sq 指向 sequence_queue 类型变量的指针变量
 * @param x datatype类型的变量，要插入的数
 */
void insertCircularQueue(sequence_queue *sq, datatype x) {
    if ((sq->rear + 1) % MAXSIZE == sq->front) {
        printf("\n顺序循环队列是满的！无法进行插入操作！");
        exit(1);
    }
//    下面不能简单的 rear++,不然会变的很大
//    sq->a[sq->rear++] = x;
    sq->a[sq->rear] = x;
    sq->rear = (sq->rear + 1) % MAXSIZE;
}

/**
 * 循环队列（顺序存储）的删除操作
 * @param sq 指向 sequence_queue 类型变量的指针变量
 */
void deleteCircularQueue(sequence_queue *sq) {
    if (emptyCircularQueue(*sq)) {
        printf("\n顺序循环队列是空的！无法进行删除操作！");
        exit(1);
    }
    sq->front = (sq->front + 1) % MAXSIZE;
}

#endif //DATASTRUCTURE_SEQUENTIALCIRCULARQUEUE_H
