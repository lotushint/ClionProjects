//
// Created by lotushint on 2022/7/3.
// 将树的括号表示转换成树的孩子表示（数组方式）
//

#ifndef DATASTRUCTURE_BRACKETTOCHILDREPRESENTATION_H
#define DATASTRUCTURE_BRACKETTOCHILDREPRESENTATION_H
#define BRACKETMAXSIZE 50

#include <stdbool.h>
#include "../treestoragestructure/ChildRepresentation2.h"

/**
 * 存放树括号表示的数组
 */
char bracketTree[BRACKETMAXSIZE];

/**
 * 将树的括号表示法转换为孩子表示法
 * @param bracket 树括号表示的数组
 * @param rootPointer 树根的地址
 * @param lengthPointer 树的实际结点长度
 * @param tree 树结点数组
 */
void bracketToChildRepresentation(char bracket[], int *rootPointer, int *lengthPointer, TreeNode tree[]) {
    /**
     * 存放树或子树根结点的栈
     */
    int stack[MAXSIZE];
    /**
     * 栈顶指针
     */
    int top = 0;
    /**
     * 程序结束的标志
     */
//    int done = 1;
    int i, j = 0, k = 0, l;
    *rootPointer = 0;
    /**
     * 产出孩子表示法的根结点,此时 j = 0
     */
    tree[j].data = bracket[k++];
    for (i = 0; i < m; ++i) {
        tree[j].child[i] = -1;
    }

    while (true) {
        if (bracket[k] == '(') {
            //遇到左括号，其前面的元素对应的结点进栈
            stack[top++] = j;
            k++;
        } else if (bracket[k] == ')') {
            //遇到右括号，栈顶元素出栈
            --top;
            if (top == 0) {
                //栈为空，算法结束
                return;
            } else {
                k++;
            }
        } else if (bracket[k] == ',') {
            //遇到逗号，跳过
            k++;
        } else {
            //将当前被扫描的元素作为栈顶元素的子女
            tree[++j].data = bracket[k];
            for (i = 0; i < m; ++i) {
                tree[j].child[i] = -1;
            }

            //栈顶元素
            l = stack[top - 1];
            i = 0;
            //寻找栈顶元素当前的第一个空子女
            while (tree[l].child[i] != -1) {
                i++;
            }
            //为栈顶元素对应的树结点挂上子女
            tree[l].child[i] = j;
            k++;
        }
        *lengthPointer = j + 1;
    }
}

/**
 * 树的前序遍历
 * @param treeNodes 树的结点数组
 * @param treeRoot 树根的下标
 */
void preorderTraverse(TreeNode node[], int treeRoot) {
    printf("%c", node[treeRoot].data);
    for (int i = 0; i < m; ++i) {
        if (node[treeRoot].child[i] != -1) {
            preorderTraverse(node, node[treeRoot].child[i]);
        }
    }
}

#endif //DATASTRUCTURE_BRACKETTOCHILDREPRESENTATION_H
