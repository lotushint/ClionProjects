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
    int i = 0, j, last;

}

#endif //DATASTRUCTURE_INDEXORDERSEARCH_H
