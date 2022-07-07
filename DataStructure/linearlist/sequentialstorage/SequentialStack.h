//
// Created by hefan on 2022/5/31.
// 栈（顺序存储）是特殊的顺序表（顺序存储的线性表）
//

#ifndef DATASTRUCTURE_SEQUENTIALSTACK_H
#define DATASTRUCTURE_SEQUENTIALSTACK_H

#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100

typedef int datatype;
typedef struct {
    datatype a[MAXSIZE];
    int top;
} sequence_stack;

/**
 * 栈（顺序存储）初始化
 * @param st 指向 sequence_stack 型变量的指针变量 st
 */
void init(sequence_stack *st) {
    st->top = 0;
};

/**
 * 判断栈（顺序存储）是否为空
 * @param st sequence_stack型变量st
 * @return 返回 1 表示空，0 表示非空
 */
int empty(sequence_stack st) {
    return st.top == 0 ? 1 : 0;
};

/**
 * 读栈顶（顺序存储）结点值
 * @param st sequence_stack型变量st
 * @return 返回栈顶结点值
 */
datatype read(sequence_stack st) {
    if (empty(st)) {
        printf("\n栈是空的");
        exit(1);
    } else {
        return st.a[st.top - 1];
    }
};

/**
 * 栈（顺序存储）的插入（进栈）操作
 * @param st 指向 sequence_stack 型变量的指针变量 st
 * @param x datatype型变量 x，要插入的值
 */
void push(sequence_stack *st, datatype x) {
    if (st->top == MAXSIZE) {
        printf("\n栈是满的");
        exit(1);
    }
    st->a[st->top++] = x;
//    st->top++;
};

/**
 * 栈（顺序存储）的删除（出栈）操作
 * @param st 指向 sequence_stack 型变量的指针变量 st
 */
void pop(sequence_stack *st) {
    if (st->top == 0) {
        printf("\n栈是空的!");
        exit(1);
    }
    st->top--;
};
#endif //DATASTRUCTURE_SEQUENTIALSTACK_H
