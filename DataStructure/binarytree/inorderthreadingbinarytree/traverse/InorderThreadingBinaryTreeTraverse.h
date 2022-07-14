//
// Created by lotushint on 2022/7/13.
// 穿线二叉树中序遍历
//

#ifndef DATASTRUCTURE_INORDERTHREADINGBINARYTREETRAVERSE_H
#define DATASTRUCTURE_INORDERTHREADINGBINARYTREETRAVERSE_H

/**
 * 寻找结点 tree 在中序遍历下的后继结点
 * @param tree 指向穿线二叉树根结点的指针
 * @return tree 在中序遍历下的后继结点的地址
 */
ThreadBinaryTree inorderTraversalSuccessorNode(ThreadBinaryTree tree) {
    ThreadBinaryTree q;
    if (tree->rightTag == 1) {
        //tree 的右指针为线索，指向 tree 的后继结点
        return tree->rightChild;
    } else {
        //寻找 tree 的右子树中最左下的结点
        q = tree->rightChild;
        while (q->leftTag == 0) {
            q = q->leftChild;
        }
        return q;
    }
}

/**
 * 中序遍历中序穿线二叉树
 * @param tree 指向二叉树根结点的指针
 */
void inorderThreadingTraversal(ThreadBinaryTree tree) {
    if (tree) {
        //找到中序遍历的第一个结点
        while (tree->leftTag == 0) {
            tree = tree->leftChild;
        }
        do {
            printf("%c", tree->data);
            tree = inorderTraversalSuccessorNode(tree);
        } while (tree);
    }
}

#endif //DATASTRUCTURE_INORDERTHREADINGBINARYTREETRAVERSE_H
