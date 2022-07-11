//
// Created by lotushint on 2022/6/26.
//
// 二叉树的遍历（前中后序遍历（递归和非递归））
// 测试用例：abd#e##fg###c##
// 输出结果：
//      递归方式：
//      前序遍历结果：abdefgc
//      中序遍历结果：debgfac
//      后序遍历结果：edgfbca
//
//      非递归方式：
//      前序遍历结果：abdefgc
//      中序遍历结果：debgfac
//      后序遍历结果：edgfbca
//
#include "../traverse/BinaryTraverse.h"
#include "../binarytreecreation/BinaryTreeCreation.h"
#include "../traverse/BinaryTraversalNon_Recursive.h"

int main() {
    root = createBinaryTree();

    printf("递归方式：\n");
    printf("前序遍历结果：");
    preorderTraversal(root);
    printf("\n");
    printf("中序遍历结果：");
    inorderTraversal(root);
    printf("\n");
    printf("后序遍历结果：");
    postorderTraversal(root);


    printf("\n\n非递归方式：\n");
    printf("前序遍历结果：");
    preorderTraversalNon_Recursive(root);
    printf("\n");
    printf("中序遍历结果：");
    inorderTraversalNon_Recursive(root);
    printf("\n");
    printf("后序遍历结果：");
    postorderTraversalNon_Recursive(root);
    return 0;
}