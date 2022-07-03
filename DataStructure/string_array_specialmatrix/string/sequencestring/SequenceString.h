//
// Created by lotushint on 2022/6/16.
// 顺序串：字符串——顺序存储
//

#ifndef DATASTRUCTURE_SEQUENCESTRING_H
#define DATASTRUCTURE_SEQUENCESTRING_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef struct {
    char string[MAXSIZE];
    int length;
} sequenceString;

/**
 * 顺序串的插入运算：将字符串 t 插入到字符串 s 的第 i 个字符之前
 * @param s s 为指向 sequenceString 类型的指针变量
 * @param i 整型变量 i 为插入位置
 * @param t t 为 sequenceString 类型，表示插入的子串
 */
void stringInsert(sequenceString *s, int i, sequenceString t) {
    //非法情况处理！！！！！！！！！！实验一下去掉 - 1
    if (i < 1 || i > s->length + 1 || s->length + t.length > MAXSIZE - 1) {
        printf("不能插入！\n");
    } else {
        //s 中从第 i 个元素开始后移 t.length 个单位!!!!!!!!!!!!!!!!!!!!!
        for (int j = s->length - 1; j >= i - 1; j--) {
            s->string[j + t.length] = s->string[j];
        }
        //将字符串 t 写入字符串 s 中第 i 个字符开始的位置
        for (int j = 0; j < t.length; ++j) {
            s->string[i - 1 + j] = t.string[j];
        }
        s->length += t.length;
        //设置字符串 s 新的结束符!!!!!!!!!!!!!!!!!!!!!!!!
        s->string[s->length] = '\0';
    }
}

/**
 * 顺序串的删除运算：将字符串 s 中第 i 个字符开始长度为 length 的子串删除
 * @param s s 为指向 sequenceString 类型的指针变量
 * @param i 整型变量 i 为删除的起始位置
 * @param length 整型变量 length 为所删除的子串长度
 */
void stringDelete(sequenceString *s, int i, int length) {
    //非法情况的处理（注意 - 1 的作用）
    if (i < 1 || i > s->length || i + length - 1 > s->length) {
        printf("不能删除！\n");
    } else {
//        for (int j = 0; j < length; ++j) {
//            s->string[i - 1 + j] = s->string[i - 1 + length + j];
//        }
        //s 从下标为 i- 1 + length 开始的元素前移
        for (int j = i - 1 + length; j < s->length; ++j) {
            s->string[j - length] = s->string[j];
        }
        s->length -= length;
        //设置字符串 s 新的结束符!!!!!!!!!!!!!!!!!!!!!!!!
        s->string[s->length] = '\0';
    }
}

/**
 * 顺序串的连接操作：将 s2 中存放的字符串连接到 s1 中存放的字符串的后面构成一个新串返回
 * @param s1 sequenceString类型
 * @param s2 sequenceString类型
 * @return 指向 sequenceString 的指针类型
 */
sequenceString *stringConcat(sequenceString s1, sequenceString s2) {
    sequenceString *s;
    if (s1.length + s2.length > MAXSIZE - 1) {
        printf("不能连接！");
        return NULL;
    } else {
        s = (sequenceString *) malloc(sizeof(sequenceString));
        //将 s1 保存到新字符串 s 中
        for (int i = 0; i < s1.length; ++i) {
            s->string[i] = s1.string[i];
        }
        s->length = s1.length;

        //将 s2 保存到新字符串 s 中
        for (int i = 0; i < s2.length; ++i) {
            s->string[s->length + i] = s2.string[i];
        }
        s->length += s2.length;

        //设置字符串 s 新的结束符!!!!!!!!!!!!!!!!!!!!!!!!
        s->string[s->length] = '\0';
        return s;
    }
}

/**
 * 求给定顺序串的子串：在字符串 s 中，从第 i 个字符开始取 length 个连续字符构成一个子串返回
 * @param s s为 sequenceString 类型
 * @param i 整型变量 i 为所取子串的起始位置
 * @param length 整型变量 length 为所取子串的长度
 * @return 指向 sequenceString 的指针类型
 */
sequenceString *substring(sequenceString *s, int i, int length) {
    sequenceString *substring;
    if (i < 1 || i > s->length || i + length - 1 > s->length) {
        printf("错误！");
        return NULL;
    } else {
        substring = (sequenceString *) malloc(sizeof(sequenceString));
        for (int j = 0; j < length; ++j) {
            substring->string[j] = s->string[i - 1 + j];
        }
        substring->length = length;
        substring->string[substring->length] = '\0';
    }
    return substring;
}

#endif //DATASTRUCTURE_SEQUENCESTRING_H
