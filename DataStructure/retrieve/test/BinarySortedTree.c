//
// Created by lotushint on 2022/8/4.
// 二叉排序树
// 输入：
//      30 20 10 25 40 45 -1
// 输出：
//      非递归算法：
//      待查找关键字 25 所在结点的值为 25，父节点值为 20
//
//      递归算法：
//      待查找关键字 25 所在结点的值为 25
//

#include "../binarysortedtree/BinarySortedTree.h"

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    BinarySortedTree tree;
    printf("请输入树的结点值（随便输，会自动排序）：");
    tree = creatBinarySortedTree();

    BinarySortedTree parentPosition, position;
    binarySortedSearch1(tree, 25, &parentPosition, &position);
    printf("非递归算法：\n待查找关键字 25 所在结点的值为 %d，父节点值为 %d\n", position->data, parentPosition->data);


    BinarySortedTreeNode *p;
    p = binarySortedSearch2(tree, 25);
    printf("\n递归算法：\n待查找关键字 25 所在结点的值为 %d\n", p->data);

    return 0;
}