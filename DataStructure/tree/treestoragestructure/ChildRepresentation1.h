//
// Created by lotushint on 2022/7/2.
// 树的孩子表示法（指针方式）
//

#ifndef DATASTRUCTURE_CHILDREPRESENTATION1_H
#define DATASTRUCTURE_CHILDREPRESENTATION1_H
#define m 3 //树的度

typedef char datatype;
typedef struct node {
    datatype data;
    /**
     * 指向子女的指针数组
     */
    struct TreeNode *child[m];
} TreeNode, *treeNode;

treeNode root;
#endif //DATASTRUCTURE_CHILDREPRESENTATION1_H
