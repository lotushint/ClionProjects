//
// Created by lotushint on 2022/8/17.
// 基数排序
//

#include "RadixSort.h"

int main() {
    int i;
    int num[10] = {52, 20, 4, 10, 17, 39, 8, 300, 60, 81};

//    int num[SIZE] = {502, 200, 400, 100, 107, 309, 108, 300, 600, 801};

    //下面数据排序失败，排序后没有 0 ，且125重复两次
//    int num[SIZE] = {64,8,216,512,27,729,0,1,343,125};
    radixSort(num, 10);

    for (i = 0; i < 10; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}