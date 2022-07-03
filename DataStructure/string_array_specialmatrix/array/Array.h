//
// Created by lotushint on 2022/6/20.
// 数组（顺序存储）——三维数组,假设每个元素占用 4 个存储单元（4个字节）——L=4
//

#ifndef DATASTRUCTURE_ARRAY_H
#define DATASTRUCTURE_ARRAY_H

#define L 4
#include <stdlib.h>
#include <stdio.h>

typedef int datatype;
typedef struct {
    /**
     * 数组存储区的首地址指针
     */
    datatype *base;
    /**
     * 存放三维数组各维的长度
     */
    int index[3];
    /**
     * 存放三维数组各维的 ci 值
     */
    int c[3];
} array;

/**
 * 三维数组的初始化
 * @param a 指向结构类型 array 的指针变量
 * @param b1 @param b2 @param b3 三维数组中每维的大小
 * @return 数组初始化成功返回 1，否则返回 0
 */
int initArray(array *a, int b1, int b2, int b3) {
    int elementsNumber;
    //处理非法情况（int a[2][0];允许）
    if (b1 < 0 || b2 < 0 || b3 < 0) {
        return 0;
    }
    a->index[0] = b1;
    a->index[1] = b2;
    a->index[2] = b3;
    elementsNumber = b1 * b2 * b3;
    a->base = (datatype *) malloc(elementsNumber * sizeof(datatype));
    if (!a->base) {
        return 0;
    }
    a->c[0] = b2 * b3;
    a->c[1] = b3;
    a->c[2] = 1;
    return 1;
}

/**
 * 访问数组元素值
 * @param a 数组
 * @param i1 @param i2 @param i3 访问元素的下标
 * @param x 保存访问元素
 * @return
 */
int getValue(array a, int i1, int i2, int i3, datatype *x) {
    int offset;
    //处理非法情况
    if (i1 < 0 || i2 < 0 || i3 < 0 || i1 > a.index[0] || i2 > a.index[1] || i3 > a.index[2]) {
        printf("索引下标越界！");
        return 0;
    }
    offset = a.c[0] * i1 + a.c[1] * i2 + a.c[2] * a.index[2] * i3;
    *x = *(a.base + offset * L);
    return 1;
}

/**
 * 对数组元素赋值
 * @param a 数组
 * @param e 值
 * @param i1 @param i2 @param i3 要赋值的元素下标
 * @return 赋值成功返回 1，否则返回 0
 */
int assign(array *a, datatype e, int i1, int i2, int i3) {
    int offset;
    //处理非法情况
    if (i1 < 0 || i2 < 0 || i3 < 0 || i1 > a->index[0] || i2 > a->index[1] || i3 > a->index[2]) {
        printf("索引下标越界！");
        return 0;
    }
    offset = a->c[0] * i1 + a->c[1] * i2 + a->c[2] * a->index[2] * i3;
    *(a->base + offset * L) = e;
    return 1;
}

#endif //DATASTRUCTURE_ARRAY_H
