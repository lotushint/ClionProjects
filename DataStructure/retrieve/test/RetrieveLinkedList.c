//
// Created by lotushint on 2022/8/1.
// 线性表的检索——链式表（带头结点）
//

#include <malloc.h>
#include "../sequentialsearch/linkedlist/RetrieveLinkedList.h"

int main() {
    LinkNode *p;

    LinkList linkList = (LinkNode *) malloc(sizeof(LinkNode));

    linkList->next = (LinkNode *) malloc(sizeof(LinkNode));
    p = linkList->next;

    p->data = 0;
    p->next = (LinkNode *) malloc(sizeof(LinkNode));
    p = p->next;

    p->data = 1;
    p->next = (LinkNode *) malloc(sizeof(LinkNode));
    p = p->next;

    p->data = 2;
    p->next = (LinkNode *) malloc(sizeof(LinkNode));
    p = p->next;

    p->data = 3;
    p->next = (LinkNode *) malloc(sizeof(LinkNode));
    p = p->next;

    p->data = 4;
    p->next = NULL;

    p = linkListSearch(linkList, 0);
    printf("%3d", p->data);
    p = linkListSearch(linkList, 3);
    printf("%3d", p->data);
    p = linkListSearch(linkList, 4);
    printf("%3d", p->data);
//    p = linkListSearch(linkList, 5);
//    printf("%3d", p->data);

    p = linkListSearch2(linkList, 0);
    printf("\n%3d", p->data);
    p = linkListSearch2(linkList, 3);
    printf("%3d", p->data);
    p = linkListSearch2(linkList, 4);
    printf("%3d", p->data);
    return 0;
}