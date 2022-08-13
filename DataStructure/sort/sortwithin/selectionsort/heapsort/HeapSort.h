//
// Created by lotushint on 2022/8/13.
// 堆排序
//

#ifndef DATASTRUCTURE_HEAPSORT_H
#define DATASTRUCTURE_HEAPSORT_H

#include "../../table/Table.h"

/**
 * 筛选算法
 * @param table 待排序文件（结构类型 table 的指针变量）
 * @param adjustPosition 调整位置
 * @param heapSize 堆的大小
 */
void sift(Table *table, int adjustPosition, int heapSize) {
    int child, finished;
    //child 为调整处的儿子，初始为左儿子
    child = 2 * adjustPosition;

    //设置哨兵， 第 i 个元素 table->recordType[i] 为待调整数据
    table->recordType[0] = table->recordType[adjustPosition];

    finished = 0;
    while (child <= heapSize && !finished) {
        //选出儿子结点中较小的
        if (child < heapSize && table->recordType[child + 1].key < table->recordType[child].key) {
            child++;
        }

        //待调整元素比左右儿子中较小的还小（即在这三个结点中最小），则不需要调整
        if (table->recordType[0].key <= table->recordType[child].key) {
            finished = 1;
        } else {
            //1.待调整元素比左右儿子中较小的还大，则较小的儿子结点 上浮 到待调整元素位置
            table->recordType[adjustPosition] = table->recordType[child];

            //调整处变为原孩子结点所在位置（假设原待调整元素位置在这，减少一次赋值操作），继续下轮循环调整
            adjustPosition = child;
            //child 为调整处的儿子，初始为左儿子
            child = 2 * child;
        }
    }
    //2.原调整处结点不断 下沉 ，原调整处结点副本移动完成交换
    table->recordType[adjustPosition] = table->recordType[0];
}

/**
 * 堆排序算法
 * @param table 待排序文件（结构类型 table 的指针变量）
 */
void heapSort(Table *table) {
    //对所有元素建堆
    for (int i = table->length / 2; i >= 1; --i) {
        sift(table, i, table->length);
    }

    for (int i = table->length; i >= 2; --i) {
        /*
         * 将当前堆中最小元素和最后一个元素进行交换
         */
        table->recordType[0] = table->recordType[i];
        table->recordType[i] = table->recordType[1];
        table->recordType[1] = table->recordType[0];

        sift(table, 1, i - 1);
    }
}

#endif //DATASTRUCTURE_HEAPSORT_H
