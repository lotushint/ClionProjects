//
// Created by lotushint on 2022/8/11.
// 直接插入排序
//

#ifndef DATASTRUCTURE_STRAIGHTINSERTIONSORT_H
#define DATASTRUCTURE_STRAIGHTINSERTIONSORT_H

#include "../table.h"

/**
 * 直接插入排序算法
 * @param table 待排序文件（结构类型 table 的指针变量）
 */
void directInsertionSort(Table *table) {
    int i, j;
    //依次插入从第 2 个元素开始的所有元素（table->recordType[0]用来设置哨兵，table->recordType[1]是第一个元素，默认是排好序的）
    for (i = 2; i <= table->length; ++i) {
        j = i - 1;
        //设置哨兵， 第 i 个元素 table->recordType[i] 为待插入数据
        table->recordType[0] = table->recordType[i];
        while (table->recordType[0].key < table->recordType[j].key) {
            //比较完后，记录后移
            table->recordType[j + 1] = table->recordType[j];
            //继续向左寻找
            j--;
        }
        //插入第 i 个元素 table->recordType[i] 的副本，即哨兵
        table->recordType[j + 1] = table->recordType[0];
    }
}

#endif //DATASTRUCTURE_STRAIGHTINSERTIONSORT_H
