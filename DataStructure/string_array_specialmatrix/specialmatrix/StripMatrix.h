//
// Created by lotushint on 2022/7/2.
//

#ifndef DATASTRUCTURE_STRIPMATRIX_H
#define DATASTRUCTURE_STRIPMATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define N 100
int a[N][N], sa[N * N];
int i, j;
int n, m;

/**
 * 输入矩阵
 */
void input() {
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    }
}

/**
 * 存储矩阵
 */
void store() {
    for (i = 1; i <= n; i++) {
        for (j = i - 1; j <= i + 1; j++)
            sa[1 + 2 * (i - 1) + j - 1] = a[i][j];
    }
}

#endif //DATASTRUCTURE_STRIPMATRIX_H
