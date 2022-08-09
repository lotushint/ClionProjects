//
// Created by lotushint on 2022/8/7.
// 平衡二叉排序树（AVL树）
//

#include "BalancedBinarySortTree.h"

int main() {
    BalancedBinaryTree tree;
    int h;
    insertAvlTree(&tree, 120, &h);
    insertAvlTree(&tree, 80, &h);
    insertAvlTree(&tree, 30, &h);
    insertAvlTree(&tree, 90, &h);
    insertAvlTree(&tree, 45, &h);
    insertAvlTree(&tree, 60, &h);
    return 0;
}