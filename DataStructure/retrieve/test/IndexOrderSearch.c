//
// Created by lotushint on 2022/8/2.
// 分块查找
//

#include "../indexordersearch/IndexOrderSearch.h"

int main() {
    SequenceList sequenceList;
    IndexNode indexNode[3];

    sequenceList.data[0] = 20;
    sequenceList.data[1] = 4;
    sequenceList.data[2] = 25;
    sequenceList.data[3] = 17;
    sequenceList.data[4] = 3;
    sequenceList.data[5] = 12;
    sequenceList.data[6] = 6;
    sequenceList.data[7] = 40;
    sequenceList.data[8] = 30;
    sequenceList.data[9] = 27;
    sequenceList.data[10] = 55;
    sequenceList.data[11] = 48;
    sequenceList.data[12] = 35;
    sequenceList.data[13] = 70;
    sequenceList.data[14] = 66;
    sequenceList.data[15] = 90;
    sequenceList.data[16] = 60;
    sequenceList.data[17] = 86;
    sequenceList.data[18] = 73;
    sequenceList.data[19] = 69;
    sequenceList.length = 20;

    indexNode[0].address = 0;
    indexNode[0].key = 25;

    indexNode[1].address = 7;
    indexNode[1].key = 55;

    indexNode[2].address = 13;
    indexNode[2].key = 90;


    printf(" %2d ", indexSequentialSearch(sequenceList, indexNode, 3, 27));
    printf(" %2d ", indexSequentialSearch(sequenceList, indexNode, 3, 2789));
    printf(" %2d ", indexSequentialSearch(sequenceList, indexNode, 3, 69));
    return 0;
}