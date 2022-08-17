//
// Created by lotushint on 2022/8/17.
// 基数排序
//

#ifndef DATASTRUCTURE_RADIXSORT_H
#define DATASTRUCTURE_RADIXSORT_H

#include <stdio.h>
#include <string.h>

#define  SIZE 100    // 数组最大长度
#define  N 10       // 最大位数

/**
 * 取整数 number 的第 i 位数
 * @param number 待操作数
 * @param i 第 i 位
 * @return 待操作数的第 i 位
 */
int getDigit(int number, int i) {
    while (i > 1) {
        number /= 10;
        i--;
    }
    return number % 10;
}

/**
 * 基数排序
 * @param num 数组指针
 * @param len 数组长度
 * @return
 */
void radixSort(int *num, int len) {
    int i, j, k, l, digit;
    /**
     * 分配数组
     */
    int allot[10][N];

    // 初始化分配数组全为 0
    memset(allot, 0, sizeof(allot));

    // 遍历 num[j]，对不同位数 i 进行分配和收集
    for (i = 1; i <= N; i++) {
        /*
         * 1.将每个数据的第 i 位数分配到 allot 数组中、
         */
        for (j = 0; j < len; j++) {
            // 获取当前数据 num[j] 的第 i 位数
            digit = getDigit(num[j], i);
            /*
             * 将 num[j] 添加到分配数组 allot 的第 digit 行中
             */
            k = 0;
            // 在第 digit 行找到 第一个不为 0 的位置
            while (allot[digit][k]) {
                k++;
            }
            // 将 num[j] 放入分配数组，同位相同的放入同一行
            allot[digit][k] = num[j];
        }

        /*
         * 2.将分配数组的数据收集到原数组中
         */
        l = 0;
        for (j = 0; j < 10; j++) {
            k = 0;
            // 获取数组allot的每一行的数据 到 原数组中
            while (allot[j][k]) {
                num[l++] = allot[j][k++];
            }
        }
        // 重置分配数组
        memset(allot, 0, sizeof(allot));
    }
}

/*
 * 书上的
 */
//#define N 20 //设待排序的记录个数为 20
//#define B 5  //设排序码最多为 5 位数
//
//typedef struct {
//    /**
//     * key[i] 为待排序码从右向左（最低位）开始的第 i 位数
//     */
//    int key[B + 1];
//    /**
//     * 指针域
//     */
//    int link;
//} Node;
//
//typedef Node list[N + 1];
//typedef int staticList[10];
///**
// * 用 front[i] 和 rear[i] 分别作为第 i 个队列的队首和队尾指针
// */
//staticList front, rear;
//
///**
// * 静态链式基数排序分配算法
// * @param list
// * @param i
// */
//void distribute(list *list, int i) {
//    int j, p;
//    // 各子表初始化为空表
//    for (j = 0; j <= 9; ++j) {
//        front[j] = 0;
//        rear[j] = 0;
//    }
//
//    p = list[0]->link;
//    while (p != 0) {
//        j = list[p]->key[i];
//        if (!front[j]) {
//            front[j] = p;
//        } else {
//            list[rear[j]]->link = p;
//        }
//        rear[j] = p;
//        //继续指向下一个结点进行
//        p = list[p]->link;
//    }
//}
//
///**
// * 静态链式基数排序收集算法
// * @param list
// */
//void collect(list *list) {
//    int j = 0, t;
//    // 找第一个非空子表
//    while (!front[j]) {
//        j++;
//    }
//    //指向第一个非空子表中第一个结点
//    list[0]->link = front[j];
//    t = rear[j];
//    while (j < 9) {
//        j++;
//        // 找下一个非空子表
//        while (j < 9 && !front[j]) {
//            j++;
//        }
//        // 链接非空子表
//        if (front[j]) {
//            list[t]->link = front[j];
//            t = rear[j];
//        }
//    }
//    // t 指向最后一个非空子表中的最后一个结点，置所有非空子表合并后的链表最后一个结点的指针域为 0
//    list[t]->link = 0;
//}
//
///**
// * 静态链式基数排序算法
// * @param list
// */
//void radixSort(list *list) {
//    for (int i = 0; i < N; ++i) {
//        list[i]->link = i + 1;
//    }
//    //建立初始静态链表
//    list[N]->link = 0;
//    /*
//     * 按最低位优先依次对各关键字进行分配和收集
//     */
//    for (int i = B; i >= 1; --i) {
//        distribute(list, i);
//        collect(list);
//    }
//}

#endif //DATASTRUCTURE_RADIXSORT_H
