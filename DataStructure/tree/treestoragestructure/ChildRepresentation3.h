//
// Created by lotushint on 2022/7/2.
// 树的孩子表示法（链表方式）
//

#ifndef DATASTRUCTURE_CHILDREPRESENTATION3_H
#define DATASTRUCTURE_CHILDREPRESENTATION3_H
#define MAXSIZE 50
typedef char datatype;
/**
 * 孩子结点类型
 */
typedef struct childNode {
    /**
     * 孩子结点下标
     */
    int child;
    struct childNode *next;
} childNode, *child;
/**
 * 树的结点类型
 */
typedef struct Node {
    datatype data;
    child firstChild;
} TreeNode;
/**
 * 树的类型
 */
typedef struct tree {
/**
 * 存储树结点的数组
 */
    TreeNode treeList[MAXSIZE];
/**
 * 根结点的下标
 */
    int root;
/**
 * 树中实际所含结点的个数
 */
    int length;
} treeNode;
#endif //DATASTRUCTURE_CHILDREPRESENTATION3_H
