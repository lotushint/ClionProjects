//
// Created by lotushint on 2022/8/2.
// 二分查找
//

#include "../binarysearch/BinarySearch.h"

int main() {
    SequenceList sequenceList;
    sequenceList.data[0] = 0;
    sequenceList.data[1] = 1;
    sequenceList.data[2] = 2;
    sequenceList.data[3] = 3;
    sequenceList.data[4] = 4;
    sequenceList.data[5] = 5;
    sequenceList.length = 6;

    printf("第一种查找：\n 2 的位置：%d\n 0 的位置：%d\n 5 的位置：%d\n 10000 的位置：%d\n",
           binarySearch1(sequenceList, 2),
           binarySearch1(sequenceList, 0),
           binarySearch1(sequenceList, 5),
           binarySearch1(sequenceList, 10000));
    printf("第二种查找：\n 2 的位置：%d\n 0 的位置：%d\n 5 的位置：%d\n 10000 的位置：%d\n",
           binarySearch2(sequenceList, 2, 0, sequenceList.length - 1),
           binarySearch2(sequenceList, 0, 0, sequenceList.length - 1),
           binarySearch2(sequenceList, 5, 0, sequenceList.length - 1),
           binarySearch2(sequenceList, 10000, 0, sequenceList.length - 1));
    return 0;
}