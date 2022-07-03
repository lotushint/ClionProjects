//
// Created by lotushint on 2022/6/26.
//
#include "../BinaryTree.h"

int main() {
    root = createBinaryTree();
    //测试用例：abd#e##fg###c##
    //输出结果：abdefgc
    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    return 0;
}