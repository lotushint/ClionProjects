//
// Created by lotushint on 2022/7/13.
// 穿线二叉树——中序穿线二叉树
// 测试用例：abc##df###c#g##
//
#include "../creation/InorderThreadingBinaryTreeCreation.h"
#include "../traverse/InorderThreadingBinaryTreeTraverse.h"

int main() {
    ThreadBinaryTree root;
    createThreadingBinaryTree(&root);
    inorderThreadingTraversal(root);
    return 0;
}
