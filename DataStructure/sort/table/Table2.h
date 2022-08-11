//
// Created by lotushint on 2022/8/11.
// 表插入算法的头文件
//

#ifndef DATASTRUCTURE_TABLE2_H
#define DATASTRUCTURE_TABLE2_H

#define MAXSIZE 100 //文件中记录个数的最大值
typedef int keyType; //定义排序码类型为整数类型
/**
 * 记录类型的定义
 */
typedef struct {
    keyType key;
    /**
     * 指针域，静态链表中下一个结点位置
     */
    int link;
    /**
     * 此处还可以定义记录中除排序码的其他域
     */
    int other;
} RecordType;
/**
 * 待排序文件类型
 */
typedef struct {
    /**
     * 排序码，为了和平时的习惯一致，recordType[0]一般不用于存放排序码，在一些排序算法中它可以用来存放临时数据
     */
    RecordType recordType[MAXSIZE + 1];
    /**
     * 待排序文件中记录的个数
     */
    int length;
} Table2;
#endif //DATASTRUCTURE_TABLE2_H
