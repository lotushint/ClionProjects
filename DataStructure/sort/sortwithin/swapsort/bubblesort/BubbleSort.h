//
// Created by lotushint on 2022/8/13.
// 冒泡排序
//

#ifndef DATASTRUCTURE_BUBBLESORT_H
#define DATASTRUCTURE_BUBBLESORT_H

#include "../../table/Table.h"

/**
 * 冒泡排序算法
 * @param table 待排序文件（结构类型 table 的指针变量）
 */
void bubbleSort(Table *table) {
    for (int i = 1; i < table->length; ++i) {
        for (int j = 1; j <= table->length - i; ++j) {
            //相邻两排序码不符合排序要求，则进行交换
            if (table->recordType[j + 1].key < table->recordType[j].key) {
                /*
                 * 以第 0 个元素为中间单元进行交换
                 */
                table->recordType[0] = table->recordType[j];
                table->recordType[j] = table->recordType[j + 1];
                table->recordType[j + 1] = table->recordType[0];
            }
        }
    }
}

/**
 * 冒泡排序算法（书上的）
 * @param table 待排序文件（结构类型 table 的指针变量）
 */
void bubbleSort2(Table *table) {
    int i, j, done;
    i = 1;
    done = 1;
    while (i < table->length && done) {
        done = 0;
        for (j = 1; j <= table->length - i; ++j) {
            if (table->recordType[j + 1].key < table->recordType[j].key) {
                /*
                 * 以第 0 个元素为中间单元进行交换
                 */
                table->recordType[0] = table->recordType[j];
                table->recordType[j] = table->recordType[j + 1];
                table->recordType[j + 1] = table->recordType[0];
                done = 1;
            }
        }
        i++;
    }
}

#endif //DATASTRUCTURE_BUBBLESORT_H
