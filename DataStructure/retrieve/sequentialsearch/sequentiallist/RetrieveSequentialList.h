//
// Created by lotushint on 2022/7/31.
// 线性表的检索——顺序表
//

#ifndef DATASTRUCTURE_RETRIEVESEQUENTIALLIST_H
#define DATASTRUCTURE_RETRIEVESEQUENTIALLIST_H

#include "stdio.h"

#define MAXSIZE 1000 //预定义最大数据域空间

typedef int dataType;
/**
 * 线性表类型
 */
typedef struct {
    dataType data[MAXSIZE];
    /**
     * 线性表长度
     */
    int length;
} SequenceList;

/**
 * 顺序查找非递归算法
 * @param sequenceList 顺序表
 * @param key 待查找关键字
 * @return 若查找成功，则返回关键字在顺序表中的位置；否则，返回 -1
 */
int sequenceListSearch(SequenceList sequenceList, dataType key) {
    for (int i = 0; i < sequenceList.length; ++i) {
        if (sequenceList.data[i] == key) {
            return i;
        }
    }
    return -1;
}

/**
 * 顺序查找非递归算法（书上的）
 * @param sequenceList 顺序表
 * @param key 待查找关键字
 * @return 若查找成功，则返回关键字在顺序表中的位置；否则，返回 -1
 */
int sequenceListSearch2(SequenceList sequenceList, dataType key) {
    int k = sequenceList.length - 1;
    while (k >= 0 && sequenceList.data[k] != key) {
        k--;
    }
    return k;
}

#endif //DATASTRUCTURE_RETRIEVESEQUENTIALLIST_H
