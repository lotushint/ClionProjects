//
// Created by lotushint on 2022/6/19.
// 快速模式匹配（KMP算法）
//

#ifndef DATASTRUCTURE_KMP_H
#define DATASTRUCTURE_KMP_H

#include <stdio.h>
#include <string.h>
#include "../sequencestring/SequenceString.h"

void Next(char *T, int *next) {
    int i = 1;
    next[1] = 0;
    int j = 0;
    while (i < strlen(T)) {
        if (j == 0 || T[i - 1] == T[j - 1]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

#endif //DATASTRUCTURE_KMP_H
