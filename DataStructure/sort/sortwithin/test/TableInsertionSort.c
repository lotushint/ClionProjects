//
// Created by lotushint on 2022/8/11.
// 表插入排序
//

#include "../insertionsort/tableinsertionsort/TableInsertionSort.h"

int main() {
    Table2 table;
    table.recordType[1].key = 12;
//    table.recordType[1].key = 312;
    table.recordType[2].key = 126;
    table.recordType[3].key = 272;
    table.recordType[4].key = 226;
    table.recordType[5].key = 28;
    table.recordType[6].key = 165;
    table.recordType[7].key = 123;
    table.length = 7;
    /*
     * 初始时， recordType[0].link 用于存放表中第 1 个记录的下标，值为 1；
     * 排序结束后， recordType[0].link 中存放的是所有排序码中值最小的对应记录的下标
     *
     * 最大的排序码对应的 link 为 0
     */
    table.recordType[0].link = 1;
    tableInsertionSort(&table);
    return 0;
}