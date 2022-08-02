//
// Created by lotushint on 2022/8/2.
//

#ifndef DATASTRUCTURE_SEQUENTIALLIST_H
#define DATASTRUCTURE_SEQUENTIALLIST_H

#include "stdio.h"

#define MAXSIZE 1000 //预定义最大数据域空间

typedef int dataType;
/**
 * 线性表类型
 */
typedef struct {
    dataType data[MAXSIZE];
    /**
     * 线性表长度
     */
    int length;
} SequenceList;
#endif //DATASTRUCTURE_SEQUENTIALLIST_H
