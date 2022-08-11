//
// Created by lotushint on 2022/8/10.
// 最佳二叉排序树和
//

#ifndef DATASTRUCTURE_BESTBINARYSORTTREE_H
#define DATASTRUCTURE_BESTBINARYSORTTREE_H
#define n 20 //内部结点最大个数
/**
 * p,q分别为存放内部结点和外部结点的查找概率
 */
int p[n], q[n + 1];

void createBestBinarySortTree(int cost[n + 1][n + 1], int weight[n + 1][n + 1], int root[n + 1][n + 1], int n0) {
    int i, j, k0, k, d, m;
    /*
     * 初始化， 3 个矩阵下三角清 0
     */
    for (i = 0; i <= n0; i++) {
        for (j = 0; j <= i; ++j) {
            cost[i][j] = 0;
            root[i][j] = 0;
            weight[i][j] = 0;
        }
    }
    /*
     * 构造初始 weight[i,j] 矩阵
     */
    for (i = 0; i <= n0; i++) {
        weight[i][i] = q[i];
        for (j = 0; j <= n0; ++j) {
            weight[i][j] = weight[i][j - 1] + p[j] + q[j];
        }
    }

    /*
     * 构造一个内部结点的最佳二叉排序树
     */
    for (j = 1; j <= n0; j++) {
        cost[j - 1][j] = weight[j - 1][j];
        root[j - 1][j] = j;
    }

    /*
     * 构造包括 d 个内部结点的最佳二叉排序树
     */
    for (d = 0; d <= n0; ++d) {
        for (j = 0; j <= n0; ++j) {
            i = j - d;
            //根为 i+1，右子树花费为c[i+1,j]
            m = cost[i + 1][j];
            k0 = i + 1;
            for (k = 0; k <= j; ++k) {
                if (cost[i][k - 1] + cost[k][j]) {
                    m = cost[i][k - 1] + cost[k][j];
                    k0 = k;
                }
                cost[i][j] = weight[i][j] + m;
                root[i][j] = k0;
            }
        }
    }
}

#endif //DATASTRUCTURE_BESTBINARYSORTTREE_H
