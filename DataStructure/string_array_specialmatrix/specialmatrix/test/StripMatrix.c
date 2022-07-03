//
// Created by lotushint on 2022/7/2.
//
#include "../StripMatrix.h"

/*
输入：
5 5
1 2 0 0 0
6 7 8 0 0
0 12 13 14 0
0 0 18 19 20
0 0 0 24 25
 */
int main() {
    printf("请输入矩阵的行数和列数： ");
    scanf("%d%d", &n, &m);
    printf("请输入一个带状矩阵(所有非零元素都集中在以对角线为中心的带状区域)：\n");
    input();
    store();

    printf("Loc[i,j]=Loc[1,1] + 前i-1行非零元素个数 + 第i行中a[i][j]前非零元素个数\n");
    printf("前 i-1 行非零元素个数 = 3*(i-1)-1 ( -1 因为第一行只有两个非零元素)\n");
    printf("第i行中a[i][j]前非零元素个数 = j-i+1\n");
    printf("由此可得:\nLoc[i,j] = Loc[1,1]+3*(i-1)-1+j-i+1=Loc[1,1]+2(i-1)+j-1\n");
    printf("即 sa[Loc[i,j]] = a[i][j]\n\n");
    printf("sa[]中的数据为： \n");
    for (i = 1; i <= 1 + 2 * (n - 1) + m - 1; i++) {
        printf("sa[%d] = %d\n", i, sa[i]);
    }
    printf("\n其对应关系为：\n");
    for (i = 1; i <= n; i++) {
        for (j = i - 1; j <= i + 1; j++)
            if (sa[1 + 2 * (i - 1) + j - 1] != 0) {
                printf("a[%d][%d] = sa[%d] = %d\n", i, j, 1 + 2 * (i - 1) + j - 1, sa[1 + 2 * (i - 1) + j - 1]);
            }
    }
    return 0;
}
