//
// Created by lotushint on 2022/8/14.
// 归并排序
//

#include "../mergesort/MergeSort.h"
int main() {
    Table table;
    table.recordType[1].key = 312;
    table.recordType[2].key = 126;
    table.recordType[3].key = 272;
    table.recordType[4].key = 226;
    table.recordType[5].key = 28;
    table.recordType[6].key = 165;
    table.recordType[7].key = 123;
    table.recordType[8].key = 8;
    table.recordType[9].key = 12;
    table.length = 9;
    mergeSort(&table);
    return 0;
}