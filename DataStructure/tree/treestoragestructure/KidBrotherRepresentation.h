//
// Created by lotushint on 2022/7/3.
// 孩子兄弟表示法
//

#ifndef DATASTRUCTURE_KIDBROTHERREPRESENTATION_H
#define DATASTRUCTURE_KIDBROTHERREPRESENTATION_H
typedef char datatype;
typedef struct node {
    datatype data;
    struct TreeNode *firstChild, *rightBrother;
} TreeNode, *pNode;
pNode root;
#endif //DATASTRUCTURE_KIDBROTHERREPRESENTATION_H
