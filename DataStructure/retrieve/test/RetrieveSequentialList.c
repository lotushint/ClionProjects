//
// Created by lotushint on 2022/7/31.
// 线性表的检索（顺序存储）
//

#include "../sequentialsearch/sequentiallist/RetrieveSequentialList.h"

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
           sequenceListSearch(sequenceList, 2),
           sequenceListSearch(sequenceList, 0), sequenceListSearch(sequenceList, 5),
           sequenceListSearch(sequenceList, 10000));
    printf("第二种查找：\n 2 的位置：%d\n 0 的位置：%d\n 5 的位置：%d\n 10000 的位置：%d\n",
           sequenceListSearch2(sequenceList, 2),
           sequenceListSearch2(sequenceList, 0), sequenceListSearch2(sequenceList, 5),
           sequenceListSearch2(sequenceList, 10000));
    return 0;
}