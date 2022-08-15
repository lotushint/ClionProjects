//
// Created by lotushint on 2022/8/14.
// 归并排序
//

#ifndef DATASTRUCTURE_MERGESORT_H
#define DATASTRUCTURE_MERGESORT_H

#include "../table/Table.h"

/**
 * 一次归并算法，将有序段 inputTable[low-mid] 和 outputTable[mid+1-high] 合并成有序段 table[low-high]
 * @param inputTable 排序前的数组
 * @param outputTable 每次排序后数组
 * @param low 第一段序列的起始下标
 * @param mid 第一段序列的结束下标，mid+1 为第二段序列的起始下标
 * @param high 第二段序列的结束下标
 */
void merge(Table *inputTable, Table *outputTable, int low, int mid, int high) {
    int i, j, k;
    // i 从第 1 块起始位置开始，一直到最终位置 mid
    i = low;
    // j 从第 2 块起始位置开始，一直到最终位置 high
    j = mid + 1;
    // k 表示的是目标 outputTable 的起始位置
    k = low;

    /*
     * 将两块有序元素中元素值较小的元素依次放入目标 outputTable 中
     */
    while (i <= mid && j <= high) {
        // 第一块第 i 个值比第二块第 j 值小
        if (inputTable->recordType[i].key <= inputTable->recordType[j].key) {
            // 把小的值存入第二个数组，即第一块第 i 个值
            outputTable->recordType[k++] = inputTable->recordType[i++];
        } else {
            // 小的值存入第二个数组，即第二块第 j 个值
            outputTable->recordType[k++] = inputTable->recordType[j++];
        }
    }

    //第一块没遍历完，而第二块遍历结束，说明第一块剩余值都大于第二块
    while (i <= mid) {
        //直接把剩余第一块数据都存入第二个数组
        outputTable->recordType[k++] = inputTable->recordType[i++];
    }
    //第二块没遍历完，而第一块遍历结束，说明第二块剩余值都大于第一块
    while (j <= high) {
        //直接把剩余第二块数据都存入第二个数组
        outputTable->recordType[k++] = inputTable->recordType[j++];
    }
//    if (i <= mid) {
//        //将第一块剩余元素放入目标 outputTable 中
//        for (int t = i; t <= mid; ++t) {
//            outputTable->recordType[k + t - i] = inputTable->recordType[t];
//        }
//    } else {
//        //将第二块剩余元素放入目标 outputTable 中
//        for (int t = j; t <= high; ++t) {
//            outputTable->recordType[k + t - j] = inputTable->recordType[t];
//        }
//    }
}

/**
 * 一趟归并算法，将 inputTable 中长度为 length 的连续有序段使用 merge() 函数归并成长度为 2*length 的有序段存入
 * outputTable 中
 * @param inputTable 排序前的数组
 * @param outputTable 每次排序后数组
 * @param length inputTable 中有序段的长度
 */
void mergePass(Table *inputTable, Table *outputTable, int length) {
    int i, size;
    size = outputTable->length = inputTable->length;
    // i 指向第一个分块归并的起始点
    i = 1;
    //将以 i 为起点，长度为 length 的相邻两个有序段依次进行归并
    while (i + 2 * length - 1 <= size) {
        merge(inputTable, outputTable, i, i + length - 1, i + 2 * length - 1);
        //置下一个一次归并的起始位置
        i = i + 2 * length;
    }

    /*
     * 1. 不足以分成两个完整块
     *      - 前一个满足 length   (i + length - 1) < size
     *      - 后一个小于 length   (i + 2 * length - 1) > size
     */
    if (i + length - 1 < size) {
        //对剩下的 1 个长度为 length ，另一个长度不足 length ，终点为 size 的两个有序段归并
        merge(inputTable, outputTable, i, i + length - 1, size);
    } else {
        /*
         * 2. 剩下分块小于等于一个分块
         *      - 将剩余数据复制到 output 中
         */
        for (int j = i; j <= size; ++j) {
            outputTable->recordType[j] = inputTable->recordType[j];
        }
    }
}

/**
 * 归并排序算法
 * @param table 待排序表（结构类型 table 的指针变量 table）
 */
void mergeSort(Table *table) {
    int length;
    /**
     * 中间变量
     */
    Table temp;
    //初始时有序段的长度为 1
    length = 1;
    //有序段的长度小于待排序元素的个数，继续归并
    while (length < table->length) {
        //一趟归并，结果在 temp 中
        mergePass(table, &temp, length);
        //有序段的长度翻倍
        length = 2 * length;
        //一趟归并，结果在 table 中
        mergePass(&temp, table, length);
        //有序段的长度翻倍
        length = 2 * length;
    }
}

#endif //DATASTRUCTURE_MERGESORT_H
