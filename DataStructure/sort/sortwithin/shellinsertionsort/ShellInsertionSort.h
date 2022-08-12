//
// Created by lotushint on 2022/8/12.
// shell插入排序
//

#ifndef DATASTRUCTURE_SHELLINSERTIONSORT_H
#define DATASTRUCTURE_SHELLINSERTIONSORT_H

#include "../../table/Table.h"

/**
 * shell 插入排序算法
 * @param table 待排序文件（结构类型 table 的指针变量）
 */
void shellInsertionSort(Table *table) {
    int i, j, gap;
    gap = table->length / 2;
    while (gap >= 1) {
        //从第 d+i 个元素开始，将所有元素有序插入相应分组中
        for (i = gap + 1; i <= table->length; ++i) {
            //保存第 i 个元素
            table->recordType[0] = table->recordType[i];

            //向前找插入位置
            j = i - gap;
            //排序码比较找插入位置并后移
            while (j > 0 && table->recordType[0].key < table->recordType[j].key) {
                //记录后移（在分组中后移）
                table->recordType[j + gap] = table->recordType[j];
                //继续向前查找
                j = j - gap;
            }
            //插入第 i 个元素的副本
            table->recordType[j + gap] = table->recordType[0];
        }
        gap = gap / 2;
    }
}

#endif //DATASTRUCTURE_SHELLINSERTIONSORT_H
