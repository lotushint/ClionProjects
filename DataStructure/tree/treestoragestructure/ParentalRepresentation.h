//
// Created by lotushint on 2022/7/2.
// 树的双亲表示法
//

#ifndef DATASTRUCTURE_PARENTALREPRESENTATION_H
#define DATASTRUCTURE_PARENTALREPRESENTATION_H
#define MAXSIZE 100 //树中结点的最大值
typedef char datatype;
/**
 * 树的双亲表示法
 */
typedef struct node {
    datatype data;
    /**
     * 结点双亲的下标
     */
    int parent;
} TreeNode;
typedef struct tree {
    /**
     * 存放结点的数组
     */
    TreeNode treeList[MAXSIZE];
    /**
     * length：树中实际结点的个数<br>
     * root；根结点的位置
     */
    int length, root;
} treeNode;
#endif //DATASTRUCTURE_PARENTALREPRESENTATION_H
