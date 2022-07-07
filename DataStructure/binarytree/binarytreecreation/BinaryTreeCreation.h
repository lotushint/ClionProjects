//
// Created by lotushint on 2022/7/7.
// 二叉树的创建（前序遍历）
//

#ifndef DATASTRUCTURE_BINARYTREECREATION_H
#define DATASTRUCTURE_BINARYTREECREATION_H
/**
 * 根据 前序遍历 结果创建一颗给定二叉树
 * @return 二叉树树根地址
 */
BinaryTree createBinaryTree() {
    char c;
    BinaryTree tree;
    if ((c = getchar()) == '#') {
        tree = NULL;
    } else {
        tree = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
        tree->data = c;
        tree->leftChild = createBinaryTree();
        tree->rightChild = createBinaryTree();
    }
    return tree;
}
#endif //DATASTRUCTURE_BINARYTREECREATION_H
