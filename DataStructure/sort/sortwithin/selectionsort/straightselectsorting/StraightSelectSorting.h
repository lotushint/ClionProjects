//
// Created by lotushint on 2022/8/12.
// 直接选择排序
//

#ifndef DATASTRUCTURE_STRAIGHTSELECTSORTING_H
#define DATASTRUCTURE_STRAIGHTSELECTSORTING_H

#include "../../table/Table.h"

/**
 * 直接选择排序
 * @param table 待排序文件（结构类型 table 的指针变量）
 */
void straightSelectSorting(Table *table) {
    /**
     * 用来保存无序序列中最小元素的下标
     */
    int k;
    //每次在无序区选择一个最小的元素（k指向的位置），和第 i 个元素交换位置（第 0 个位置不放元素，故 i 从 1 开始）
    for (int i = 1; i < table->length; ++i) {
        //记下当前最小元素的位置
        k = i;
        //在无序区中向右查找更小的元素
        for (int j = i + 1; j <= table->length; ++j) {
            if (table->recordType[j].key < table->recordType[k].key) {
                k = j;
            }
        }

        //如果第 i 次选到的最小元素位置 k 不等于 k 不等于 i，则将第 k，i 个元素交换
        if (k != i) {
            //以没有用到的第 0 个元素作为中间单元进行交换
            table->recordType[0] = table->recordType[k];
            table->recordType[k] = table->recordType[i];
            table->recordType[i] = table->recordType[0];
        }
    }
}

#endif //DATASTRUCTURE_STRAIGHTSELECTSORTING_H
