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
#include "../binarytreeotheroperations/BinaryTreeOtherOperations.h"

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("请输入二叉树 1 结点的值：");
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

    printf("\n\n二叉树其他操作：\n");
    printf("查找b：%c\n", locate(root, 'b')->data);
    printf("查找e：%c\n", locate(root, 'e')->data);
    printf("统计二叉树结点的个数：%d\n", nodeNumber(root));
    printf("请输入二叉树 2 结点的值：");
    //注意过滤回车符
    getchar();
    BinaryTree root2 = createBinaryTree();
    printf("判断给定的两棵二叉树是否等价（若等价，返回 1 ；否则，返回 0）:%d\n", equal(root, root2));
    printf("二叉树 1 的深度：%d\n", depth(root));
    printf("二叉树 2 的深度：%d\n", depth(root2));
    return 0;
}