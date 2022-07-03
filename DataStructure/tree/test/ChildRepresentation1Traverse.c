//
// Created by lotushint on 2022/7/3.
// 输入：ab###ce###fh###i####g###d###

// 输出：
// 前序遍历结果：
//abcefhigd
//后序遍历结果：
//behifgcda
//层次遍历结果：
//abcdefghi
//
#include "../traverse/Traverse.h"

int main() {
    root = createTree();

    printf("前序遍历结果：\n");
    preorderTraversal(root);
    printf("\n");

    printf("后序遍历结果：\n");
    postorderTraversal(root);
    printf("\n");

    printf("层次遍历结果：\n");
    levelTraversal(root);
    printf("\n");

    return 0;
}