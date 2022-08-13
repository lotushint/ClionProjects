//
// Created by lotushint on 2022/8/13.
// 快速排序
//

#ifndef DATASTRUCTURE_QUICKSORT_H
#define DATASTRUCTURE_QUICKSORT_H

#include "../../table/Table.h"

/**
 * 快速排序算法
 * @param table 待排序文件（结构类型 table 的指针变量）
 * @param low 数组下限
 * @param high 数组上限
 */
void quickSort(Table *table, int low, int high) {
    int pos, t;
    if (low < high) {
        pos = low;
        //保留标准值
        table->recordType[0] = table->recordType[pos];

        for (int i = low + 1; i <= high; ++i) {
            if (table->recordType[i].key > table->recordType[0].key) {
                pos++;
                t = table->recordType[pos].key;
                table->recordType[pos].key = table->recordType[i].key;
                table->recordType[i].key = t;
            }
        }
        t = table->recordType[low].key;
        table->recordType[low].key = table->recordType[pos].key;
        table->recordType[pos].key = t;

        quickSort(table, low, pos - 1);
        quickSort(table, pos + 1, high);
    }
}

/**
 * 快速排序算法（书上的）
 * @param table 待排序文件（结构类型 table 的指针变量）
 */
void quickSort2(Table *table, int left, int right) {
    int i, j;
    if (left < right) {
        i = left;
        j = right;
        //准备本次以最左边的元素为标准进行划分，先保存其值
        table->recordType[0] = table->recordType[i];

        do {
            //从右向左找第一个不小于标准值的位置
            while (table->recordType[j].key > table->recordType[0].key && i < j) {
                j--;
            }
            //将第 j 个元素置于左端并重置 i
            if (i < j) {
                table->recordType[i].key = table->recordType[j].key;
                i++;
            }

            //从右向左找第一个不小于标准值的位置
            while (table->recordType[i].key < table->recordType[0].key && i < j) {
                i++;
            }
            //将第 j 个元素置于左端并重置 j
            if (i < j) {
                table->recordType[j].key = table->recordType[i].key;
                j--;
            }
        } while (i != j);
        //将标准值放入它的最终位置，本次划分结束
        table->recordType[i] = table->recordType[0];
        //对标准值左半部分递归调用本函数
        quickSort(table, left, i - 1);
        //对标准值有半部分递归调用本函数
        quickSort(table, i + 1, right);
    }
}

#endif //DATASTRUCTURE_QUICKSORT_H
