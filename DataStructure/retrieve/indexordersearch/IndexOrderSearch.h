//
// Created by lotushint on 2022/8/2.
// 分块查找
//

#ifndef DATASTRUCTURE_INDEXORDERSEARCH_H
#define DATASTRUCTURE_INDEXORDERSEARCH_H

#include "../sequentialsearch/sequentiallist/SequentialList.h"

/**
 * 索引表结点类型
 */
typedef struct {
    dataType key;
    int address;
} IndexNode;

/**
 *
 * @param sequenceList 顺序表
 * @param indexNode 索引表
 * @param indexListLength 索引表长度
 * @param key 待查找关键字
 * @return 若查找成功，返回其所在位置；否则，返回 -1
 */
int indexSequentialSearch(SequenceList sequenceList, IndexNode indexNode[], int indexListLength, dataType key) {
    /**
     * 关键字所在块的索引
     */
    int blockIndex = 0;
    int j;
    //找到关键字所在块
    while (blockIndex < indexListLength && key > indexNode[blockIndex].key) {
        blockIndex++;
    }
    //没找到关键字所在块
    if (blockIndex >= indexListLength) {
        return -1;
    } else {
        /*
         * 在顺序表中顺序检索
         */
        if (blockIndex == indexListLength - 1) {
            j = sequenceList.length - 1;
        } else {
            // j 初始时指向本块的最后一个结点（索引表中下一个元素的地址-1 即是该块最后一个元素的索引）
            j = indexNode[blockIndex + 1].address - 1;
        }

        //从后向前逐个查找
        while (j >= indexNode[blockIndex].address && key != sequenceList.data[j]) {
            j--;
        }

        //没找到
        if (j < indexNode[blockIndex].address) {
            return -1;
        } else {
            return j;
        }
    }
}

#endif //DATASTRUCTURE_INDEXORDERSEARCH_H
