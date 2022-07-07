//
// Created by lotushint on 2022/7/2.
// 树的孩子表示法（数组方式）
//

#ifndef DATASTRUCTURE_CHILDREPRESENTATION2_H
#define DATASTRUCTURE_CHILDREPRESENTATION2_H
#define m 3 //树的度
#define MAXSIZE 100 //存放树结点的数组大小
typedef char datatype;
typedef struct Node {
    datatype data;
    int child[m];
} TreeNode;
/**
 * 存储树结点的数组
 */
TreeNode treeNode[MAXSIZE];
/**
 * 根结点的下标
 */
int root;
/**
 * 树中实际所含结点的个数
 */
int length;
#endif //DATASTRUCTURE_CHILDREPRESENTATION2_H
