//
// Created by lotushint on 2022/6/17.
// 链式串：字符串——链式存储
//

#ifndef DATASTRUCTURE_LINKEDSTRING_H
#define DATASTRUCTURE_LINKEDSTRING_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct TreeNode *next;
} linkedStringNode;
typedef linkedStringNode *linkedString;

/**
 * 输出链式串
 * @param s linkedstring 类型的变量
 */
void display(linkedString s) {
    linkedStringNode *q;
    q = s;
    while (q != NULL) {
        printf("%3c", q->data);
        q = q->next;
    }
}

/**
 * 链式串的创建
 * @param s 指向 linkedstring 类型的指针变量
 */
void stringCreate(linkedString *s) {
    char c;
    /**
     * p:产生新节点 <br>
     * r:始终指向当前链式串的最后一个字符对应的结点
     */
    linkedStringNode *p, *r;
    *s = NULL;
    r = NULL;
    while ((c = getchar()) != '\n') {
        p = (linkedStringNode *) malloc(sizeof(linkedStringNode));
        p->data = c;
        //新节点插入空表的情况
        if (*s == NULL) {
            *s = p;
        } else {
            //新节点插入非空表的情况
            r->next = p;
        }
        r = p;
    }
    //处理表尾结点指针域
    if (r != NULL) {
        r->next = NULL;
    }
}

/**
 * 链式串的插入
 * @param s 指向 linkString 类型的指针变量
 * @param i 插入的位置
 * @param t 插入的子串
 */
void stringInsert(linkedString *s, int i, linkedString t) {
    int j = 1;
    linkedString p, q;
    p = *s;
    //找到第 i-1 个结点
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    //第 i-1 个元素不存在，则出错
    if (!p) {
        printf("s的第 %d 个元素不存在！\n", i - 1);
    } else {
        q = t;
        //找到 t 最后一个结点
        while (q && q->next) {
            q = q->next;
        }
        //在 s 第 1 个位置插入 t
        if (q && i == 1) {
            q->next = p;
            *s = t;
        } else if (q) {
            q->next = p->next;
            p->next = t;
        }
    }
}

/**
 * 链式串的删除
 * @param s 指向 linkedString 类型的指针变量
 * @param i 删除的起始位置（第 i 个元素）
 * @param length 删除的子串长度
 */
void stringDelete(linkedString *s, int i, int length) {
    //第一个元素之前不存在任何元素，找不到
    if (i < 1) {
        printf("不存在第%d个元素，删除失败！\n", i);
    } else {
        int k = 1;
        /**
         * p:找到第 i-1 个元素<br>
         * q:找到第 i 个元素开始长度为 length 的子串的最后一个结点<br>
         * r:回收被删除的子串<br>
         */
        linkedString p, q, r;
        p = *s;
        //找到第 i 个元素
        while (p && k < i - 1) {
            p = p->next;
            k++;
        }
        //第 i-1 个元素不存在，则出错
        if (!p) {
            printf("s的第%d个元素不存在！", i - 1);
        } else {
            //找到第 i 个元素开始长度为 length 的子串的最后一个结点
            q = p;
            k = 0;
            while (q && k < length) {
                q = q->next;
                k++;
            }
            if (!q) {
                printf("第 %d 个元素开始长度为 %d 的子串不存在!\n", i, length);
            } else if (i == 1) {
                //删除 s 从第 1 个元素开始长度为 length 的子串
                *s = q;
            } else {
                r = p->next;
                //删除 s 不是从第 1 个元素开始长度为 length 长度的子串
                p->next = q->next;
                //回收删除的子串时结束的标志
                q->next = NULL;
                while (r) {
                    p = r;
                    r = r->next;
                    free(p);
                }
            }
        }
    }
}

/**
 * 链式串的连接：s1 + s2
 * @param s1 指向 待连接字符串 s1 类型的指针变量
 * @param s2 待连接字符串 s2
 */
void stringConcat(linkedString *s1, linkedString s2) {
    linkedString p;
    //s1 为空串
    if (!(*s1)) {
        *s1 = s2;
    } else {
        //s1,s2 都不为空串
        if (s2) {
            p = *s1;
            //查找 s1 最后一个元素的位置
            while (p->next) {
                p = p->next;
            }
            //将 s2 连接到 s1 之后
            p->next = s2;
        }
    }
}

/**
 * 求给定链式串的子串
 * @param s 给定链式串
 * @param i 所取子串的起始位置（第 i 个位置）
 * @param length 所取子串的长度
 */
linkedString substring(linkedString s, int i, int length) {
    //第一个元素之前不存在任何元素，找不到
    if (i < 1) {
        printf("不存在第%d个元素，错误！\n", i);
        return NULL;
    } else {
        int k = 1;
        /**
         * p:查找 s 中第 i 个字符<br>
         * q:指向 r 的最后一个结点<br>
         * r:返回的字符串<br>
         * t:新建结点<br>
         */
        linkedString p, q, r, t;
        p = s;
        //找到第 i 个元素
        while (p && k < i) {
            p = p->next;
            k++;
        }
        if (!p) {
            printf("s的第%d个元素不存在！", i - 1);
        } else {
            k = 1;
            r = (linkedString) malloc(sizeof(linkedStringNode));
            r->data = p->data;
            q = r;
            while (p->next && k < length) {
                p = p->next;
                k++;

                t = (linkedString) malloc(sizeof(linkedStringNode));
                t->data = p->data;
                q->next = t;
                q = t;
            }

            if (k != length) {
                printf("s1的从第%d个位置长度为%d的子串不存在！", i, length);
                return NULL;
            } else {
                q->next = NULL;
                return r;
            }
        }
    }
}

#endif //DATASTRUCTURE_LINKEDSTRING_H
