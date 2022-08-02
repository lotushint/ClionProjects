//
// Created by lotushint on 2022/8/2.
// 二分查找
//

#ifndef DATASTRUCTURE_BINARYSEARCH_H
#define DATASTRUCTURE_BINARYSEARCH_H

#include "../sequentialsearch/sequentiallist/SequentialList.h"

/**
 * 二分查找的非递归实现算法
 * @param sequenceList 顺序表
 * @param key 待查找关键字
 * @return 若查找成功，则返回所在位置；否则返回 -1
 */
int binarySearch1(SequenceList sequenceList, dataType key) {
    int low = 0, high = sequenceList.length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (sequenceList.data[mid] == key) {
            return mid;
        } else if (sequenceList.data[mid] > key) {
            //继续在前半部分进行二分检索
            high = mid - 1;
        } else {
            //继续在后半部分进行二分检索
            low = mid + 1;
        }
    }
    return -1;
}

/**
 * 二分查找的递归算法
 * @param sequenceList 顺序表
 * @param key 待查找关键字
 * @param low 顺序表起点
 * @param high 顺序表终点
 * @return 若查找成功，则返回所在位置；否则返回 -1
 */
int binarySearch2(SequenceList sequenceList, dataType key, int low, int high) {
    int mid = low + high;
    if (low > high) {
        return -1;
    }
    if (sequenceList.data[mid] == key) {
        return mid;
    } else if (sequenceList.data[mid] > key) {
        //继续在前半部分进行二分检索
        return binarySearch2(sequenceList, key, low, mid - 1);
    } else {
        //继续在后半部分进行二分检索
        return binarySearch2(sequenceList, key, mid + 1, high);
    }
}

#endif //DATASTRUCTURE_BINARYSEARCH_H
