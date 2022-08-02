//
// Created by lotushint on 2022/8/1.
// 线性表的检索（链式存储（带头结点））
//

#ifndef DATASTRUCTURE_RETRIEVELINKEDLIST_H
#define DATASTRUCTURE_RETRIEVELINKEDLIST_H

#include "LinkedList.h"

/**
 * 带头结点的单链表的顺序查找算法
 * @param linkList 带头结点的单链表
 * @param key 待查找关键字
 * @return 若查找成功，返回待查找数据在链表中的位置；否则，返回空
 */
LinkList linkListSearch(LinkList linkList, dataType key) {
    LinkNode *p;
    p = linkList->next;
    while (p) {
        if (p->data == key) {
            return p;
        } else {
            p = p->next;
        }
    }
    return NULL;
}

/**
 * 带头结点的单链表的顺序查找算法（书上的）
 * @param linkList 带头结点的单链表
 * @param key 待查找关键字
 * @return 若查找成功，返回待查找数据在链表中的位置；否则，返回空
 */
LinkList linkListSearch2(LinkList linkList, dataType key) {
    LinkNode *p;
    p = linkList->next;
    while (p && p->data != key) {
        p = p->next;
    }
    return p;
}

#endif //DATASTRUCTURE_RETRIEVELINKEDLIST_H
