//
// Created by lotushint on 2022/8/11.
// 表插入排序
//

#ifndef DATASTRUCTURE_TABLEINSERTIONSORT_H
#define DATASTRUCTURE_TABLEINSERTIONSORT_H

#include "../../table/Table2.h"

/**
 * 表插入排序
 * @param table 待排序文件（结构类型 table 的指针变量）
 */
void tableInsertionSort(Table2 *table) {
    int p, pre;
    //第一个元素为有序静态表
    table->recordType[0].link = 1;
    table->recordType[1].link = 0;

    //依次插入从第 2 个开始的所有元素
    for (int i = 2; i <= table->length; ++i) {
        // pre 指向 p 的前驱元素位置
        pre = 0;
        // p 指向表中第 1 个元素（初始时 table->recordType[0].link = 1，往后每次外循环开始时 p = table->recordType[0].link 指的是静态表中最小元素的下标）
        p = table->recordType[0].link;
        /*
         * 找插入位置，当 插入元素 大于 静态表中最大元素 时 p=0
         */
        while (p != 0 && table->recordType[i].key >= table->recordType[p].key) {
            pre = p;
            p = table->recordType[p].link;
        }
        /*
         * 将第 i 个元素插入 pre 和 p 所指元素之间
         * pre 为 0 时可以更改最小元素下标
         */
        table->recordType[pre].link = i;
        table->recordType[i].link = p;
    }
}

#endif //DATASTRUCTURE_TABLEINSERTIONSORT_H
