//
// Created by lotushint on 2022/8/11.
// 二分法插入排序
//

#ifndef DATASTRUCTURE_BINARYINSERTIONSORT_H
#define DATASTRUCTURE_BINARYINSERTIONSORT_H

#include "../../table/Table.h"

/**
 * 二分法插入排序算法
 * @param table 待排序文件（结构类型 table 的指针变量）
 */
void binaryInsertionSort(Table *table) {
    int left, right, mid;
    //依次插入从第 2 个元素开始的所有元素（table->recordType[0]用来设置哨兵，table->recordType[1]是第一个元素，默认是排好序的）
    for (int i = 2; i <= table->length; ++i) {
        //设置哨兵， 第 i 个元素 table->recordType[i] 为待插入数据
        table->recordType[0] = table->recordType[i];
        left = 1;
        right = i - 1;
        //查找插入位置
        while (left <= right) {
            mid = (left + right) / 2;
            if (table->recordType[i].key < table->recordType[mid].key) {
                right = mid - 1;
            } else {
                //注意：此分支为 ">="

                //插入位置为 left
                left = mid + 1;
            }
        }
        //后移，空出插入位置
        for (int j = i - 1; j >= left; j--) {
            table->recordType[j + 1] = table->recordType[j];
        }
        //插入第 i 个元素的副本
        table->recordType[left] = table->recordType[0];
    }
}

#endif //DATASTRUCTURE_BINARYINSERTIONSORT_H
