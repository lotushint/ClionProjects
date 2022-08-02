//
// Created by lotushint on 2022/8/2.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H

#include "stdio.h"

typedef int dataType;
typedef struct node {
    dataType data;
    struct node *next;
} LinkNode;
typedef LinkNode *LinkList;
#endif //DATASTRUCTURE_LINKEDLIST_H
