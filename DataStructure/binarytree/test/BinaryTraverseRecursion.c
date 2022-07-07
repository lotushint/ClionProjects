//
// Created by lotushint on 2022/6/26.
// 二叉树的遍历（前中后序遍历）\
// 测试用例：abd#e##fg###c##
// 输出结果：abdefgc
//
#include "../traverse/BinaryTraverse.h"
#include "../binarytreecreation/BinaryTreeCreation.h"

int main() {
    root = createBinaryTree();

    printf("前序遍历结果：");
    preorderTraversal(root);
    printf("\n");
    printf("中序遍历结果：");
    inorderTraversal(root);
    printf("\n");
    printf("后序遍历结果：");
    postorderTraversal(root);
    return 0;
}