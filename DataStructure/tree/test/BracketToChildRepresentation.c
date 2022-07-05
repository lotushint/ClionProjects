//
// Created by lotushint on 2022/7/3.
// 将树的括号表示转换成树的孩子表示（数组方式）
// 输入：A(B(DEF)C(G))#
// 输出：ABDEFCG
//
#include "stdio.h"
#include "../brackettochild/BracketToChildRepresentation.h"

int main() {
    char c;
    int bracketLength = 0;
    while ((c = getchar()) != '#') {
        bracketTree[bracketLength++] = c;
    }

    bracketToChildRepresentation(bracketTree, &root, &length, treeNode);
    printf("前序遍历的结果:\n");
    preorderTraverse(treeNode, root);
    printf("\n%d", length);
    return 0;
}