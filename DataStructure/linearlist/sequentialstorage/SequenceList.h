//
// Created by hefan on 2022/5/31.
// 线性表-顺序存储
//

#ifndef DATASTRUCTURE_SEQUENCELIST_H
#define DATASTRUCTURE_SEQUENCELIST_H

#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100

typedef int datatype;
typedef struct {
    datatype a[MAXSIZE];
    int size;
} sequence_list;

/**
 * 顺序表的初始化——置空表
 * @param slt 指向sequence_list型变量的指针
 */
void init(sequence_list *slt) {
    slt->size = 0;
};

/**
 * 在顺序表后部插入值为 x的结点
 * @param slt 指向sequence_list型变量的指针
 * @param x datatype型的变量x
 */
void append(sequence_list *slt, datatype x) {
    if (slt->size == MAXSIZE) {
        printf("顺序表是满的！");
        exit(1);
    } else {
        slt->a[slt->size++] = x;
//        slt->size++;
    }
};

/**
 * 打印顺序表的各结点值
 * @param slt sequence_list型变量
 */
void display(sequence_list slt) {
    if (!slt.size) {
        printf("\n顺序表是空的！");
    } else {
        for (int i = 0; i < slt.size; ++i) {
            printf("%5d", slt.a[i]);
        }
    }
};

/**
 * 判断顺序表是否为空
 * @param slt sequence_list型变量
 * @return 1表示空，0表示非空
 */
int empty(sequence_list slt) {
    return slt.size == 0 ? 1 : 0;
};

/**
 * 查找顺序表中值为 x 的结点位置
 * @param slt sequence_list型变量
 * @param x datatype型变量，要查找的值
 * @return 返回 x 的位置值，-1 表示未找到
 */
int find(sequence_list slt, datatype x) {
//    for (int i = 0; i < slt.size; ++i) {
//        if(slt.a[i] == x){
//            return i;
//        }
//    }
//    return -1;

    int i = 0;
    while (i < slt.size && slt.a[i] == x) {
        i++;
    }
    return i < slt.size ? i : -1;
};

/**
 * 查找顺序表中第 position 个结点的位置
 * @param slt sequence_list型变量
 * @param position int型变量，要查找的位置
 * @return 存在返回该位置的值，不存在退出程序
 */
int get(sequence_list slt, int position) {
    if (position < 0 || position >= slt.size) {
        printf("\n指定位置的结点不存在！");
        exit(1);
    }
    return slt.a[position];
};

/**
 * 在顺序表的position位置插入值为x的结点，平均插入元素所需移动次数T(n) = n / 2,时间复杂度O(n)，P15
 * @param slt 指向sequence_list型变量的指针
 * @param x int型变量，要插入的数
 * @param position int型变量，要插入的位置(索引从0开始)
 */
void insert(sequence_list *slt, int x, int position) {
    if (slt->size == MAXSIZE) {
        printf("\n顺序表是满的！没法插入！");
        exit(1);
    }
    if (position < 0 || position > slt->size) {
        printf("\n指定插入的位置不存在！");
        exit(1);
    }

    //position位置后面的元素后移一个单位
    for (int i = slt->size; i > position; i--) {
        slt->a[i] = slt->a[i - 1];
    }
    slt->size++;
    slt->a[position] = x;
};

/**
 * 删除顺序表中第 position 位置的结点
 * @param slt 指向sequence_list型变量的指针
 * @param position int型变量，要删除的位置（索引从0开始）
 */
void delete(sequence_list *slt, int position) {

    if (slt->size == 0) {
        printf("\n顺序表是空的！");
        exit(1);
    }
    if (position < 0 || position >= slt->size) {
        printf("\n指定删除的位置不存在！");
        exit(1);
    }
    for (int i = position; i < slt->size - 1; ++i) {
        slt->a[i] = slt->a[i + 1];
    }
    slt->size--;
};

#endif //DATASTRUCTURE_SEQUENCELIST_H
