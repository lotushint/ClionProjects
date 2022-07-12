//
// Created by lotushint on 2022/7/12.
// 二叉树其他运算的实现
//

#ifndef DATASTRUCTURE_BINARYTREEOTHEROPERATIONS_H
#define DATASTRUCTURE_BINARYTREEOTHEROPERATIONS_H

/**
 * 二叉树的查找
 * @param tree 指向二叉树根结点的指针
 * @param x 被查找的元素值
 * @return 若找到值为 x 的元素，则返回该结点的指针；若没找到，则返回空
 */
BinaryTree locate(BinaryTree tree, datatype x) {
    BinaryTree p;

    if (!tree) {
        return NULL;
    } else if (tree->data == x) {
        //先找根结点
        return tree;
    } else {
        //再进入根结点的左子树
        p = locate(tree->leftChild, x);

        if (p) {
            //找到了
            return p;
        } else {
            //根结点和左子树没找到再进入根结点的右子树
            return locate(tree->rightChild, x);
        }
    }
}

/**
 * 统计二叉树结点的个数
 * @param tree 指向二叉树根结点的指针
 * @return 返回二叉树中结点的个数
 */
int nodeNumber(BinaryTree tree) {
    //树中没有结点
    if (!tree) {
        return 0;
    } else {
        //左子树结点个数 + 右子树结点个数 + 根结点（1）
        return nodeNumber(tree->leftChild) + nodeNumber(tree->rightChild) + 1;
    }
}

/**
 * 判断给定的两棵二叉树是否等价
 * @param tree1 指向二叉树根结点的指针
 * @param tree2 指向二叉树根结点的指针
 * @return 若等价，返回 1 ；否则，返回 0 ；
 */
int equal(BinaryTree tree1, BinaryTree tree2) {
    /**
     * 等价的标志
     */
    int result = 0;
    //两棵子树都为空！！！！！！！！！！！！！！！！！！！！！！！
    if (!tree1 && !tree2) {
        result = 1;
    } else if (tree1 && tree2) {
        //两棵树都不为空，先比较根结点，再比较左子树是否相同，相同则比较右子树是否相同
        if (tree1->data == tree2->data) {
            if (equal(tree1->leftChild, tree2->leftChild)) {
                result = equal(tree1->rightChild, tree2->rightChild);
            }
        }
    }
    return result;
}

/**
 * 求给定二叉树的高度
 * @param tree 指向二叉树根结点的指针
 * @return 返回二叉树的高度
 */
int depth(BinaryTree tree) {
    int h, leftHigh, rightHigh;
    //二叉树为空
    if (!tree) {
        return 0;
    } else {
        leftHigh = depth(tree->leftChild);
        rightHigh = depth(tree->rightChild);
        if (leftHigh > rightHigh) {
            h = leftHigh + 1;
        } else {
            h = rightHigh + 1;
        }
        return h;
    }
}

#endif //DATASTRUCTURE_BINARYTREEOTHEROPERATIONS_H
