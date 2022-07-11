//
// Created by lotushint on 2022/7/11.
// 二叉树的遍历（非递归方式）
//

#ifndef DATASTRUCTURE_BINARYTRAVERSALNON_RECURSIVE_H
#define DATASTRUCTURE_BINARYTRAVERSALNON_RECURSIVE_H

#include <stdio.h>
#include "../binarytreestorage/linkedstorage/BinaryTreeStructure2.h"

typedef struct stack {
    BinaryTree data[100];
    /**
     * 为栈中每个元素设计的标记，用于后序遍历
     */
    int tag[100];
    /**
     * 栈顶指针
     */
    int top;
} SequentialStack;

/**
 * 进栈
 * @param stack 类型为 SequentialStack 的指针
 * @param tree 类型为 BinaryTree 的变量（类型为 BinaryTreeNode 的指针）
 */
void push(SequentialStack *stack, BinaryTree tree) {
    stack->data[stack->top++] = tree;
};

/**
 * 出栈
 * @param stack 类型为 SequentialStack 的指针
 * @return 若栈不为空，则返回栈顶元素；否则，返回空
 */
BinaryTree pop(SequentialStack *stack) {
    if (stack->top != 0) {
        stack->top--;
        return stack->data[stack->top];
    } else {
        return NULL;
    }
}

/**
 * 非递归实现二叉树的前序遍历
 * @param tree 类型为 BinaryTree 的变量（类型为 BinaryTreeNode 的指针）
 */
void preorderTraversalNon_Recursive(BinaryTree tree) {
    SequentialStack stack;
    stack.top = 0;

    while (tree || stack.top) {
        if (tree) {
            printf("%c", tree->data);
            push(&stack, tree);
            tree = tree->leftChild;
        } else {
            //访问栈顶元素的右子树
            tree = pop(&stack);
            tree = tree->rightChild;
        }
    }
}

/**
 * 非递归实现二叉树的中序遍历
 * @param tree 类型为 BinaryTree 的变量（类型为 BinaryTreeNode 的指针）
 */
void inorderTraversalNon_Recursive(BinaryTree tree) {
    SequentialStack stack;
    stack.top = 0;

    while (tree || stack.top) {
        if (tree) {
            push(&stack, tree);
            tree = tree->leftChild;
        } else {
            //访问栈顶元素根节点和右子树
            tree = pop(&stack);
            printf("%c", tree->data);
            tree = tree->rightChild;
        };
    }
}

/**
 * 非递归实现二叉树的后序遍历
 * @param tree 类型为 BinaryTree 的变量（类型为 BinaryTreeNode 的指针）
 */
void postorderTraversalNon_Recursive(BinaryTree tree) {
    SequentialStack stack;
    stack.top = 0;

    while (tree || stack.top) {
        if (tree) {
            push(&stack, tree);
            //注意！！！！！！！！！！！！！！！！！！！！（c语言 int 类型默认赋值不一定为 0，故要赋值）
            stack.tag[stack.top - 1] = 0;
            tree = tree->leftChild;
        } else if (stack.tag[stack.top - 1] == 1) {
            //tag 为 1 访问栈顶元素
            tree = pop(&stack);
            printf("%c", tree->data);
            //注意！！！！！！！！！！！！！！！！！！！！
            tree = NULL;
        } else if (stack.tag[stack.top - 1] == 0) {
            //访问右子树不能 出栈 ，因为根结点还没有被访问
            tree = stack.data[stack.top - 1];
            //tag 为 0 访问栈顶元素的右子树（注意根节点还没有访问，tag = 1）
            tree = tree->rightChild;
            //接下来还要访问根结点将 tag 置为 1
            stack.tag[stack.top - 1] = 1;
        }
    }
}

#endif //DATASTRUCTURE_BINARYTRAVERSALNON_RECURSIVE_H
