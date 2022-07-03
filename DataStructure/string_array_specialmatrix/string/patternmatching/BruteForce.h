//
// Created by lotushint on 2022/6/18.
// 朴素的模式匹配算法（暴力模式匹配）
//

#ifndef DATASTRUCTURE_BRUTEFORCE_H
#define DATASTRUCTURE_BRUTEFORCE_H

#include "../sequencestring/SequenceString.h"

/**
 * 字符串朴素模式匹配的算法的实现
 * @param p 模式字符串
 * @param t 正文
 * @return 匹配成功返回 p 在 t 中首次出现的起始位置
 */
int bruteForce(sequenceString p, sequenceString t) {
    if (p.length == 0 || t.length == 0) {
        printf("\n两个字符串至少有一个为空，无法进行匹配！\n");
        return -1;
    }
    /**
     * 记录 t 从第几个字符开始匹配, p 在 t 中的起始位置
     */
    int startIndex = 0;
    /**
     * i:扫描正文 t 的索引<br>
     * j:扫描模式字符串 p 的索引
     */
    int i, j;
    //以 t 中每一个字符为起始开始与 p 匹配
    for (i = 0; i < t.length; ++i) {
        startIndex = i;
        for (j = 0; j < p.length; ++j) {
            //p 已经移动到使 t 中剩余的字符个数小于 p 的长度的位置
            if (t.length - i - 1 < p.length - j - 1) {
                return -1;
            }
            if (t.string[i++] != p.string[j]) {
                break;
            }
        }
        //匹配成功
        if (j == p.length) {
            break;
        } else {
            //从 p 的下一个字符为起始重新匹配
            i = startIndex;
        }
    }
    return startIndex + 1;
}

/**
 * 书上的程序,返回的索引
 * @param p
 * @param t
 * @return
 */
int getIndex(sequenceString p, sequenceString t) {
    int i = 0, j, success = 0;
    while (i <= t.length - p.length && !success) {
        j = 0;
        success = 1;
        while (j <= p.length - 1 && success) {
            if (p.string[j] == t.string[i + j]) {
                j++;
            } else {
                success = 0;
            }
        }
        ++i;
    }
    if (success) {
        return i - 1;
    } else {
        return -1;
    }
}

#endif //DATASTRUCTURE_BRUTEFORCE_H
