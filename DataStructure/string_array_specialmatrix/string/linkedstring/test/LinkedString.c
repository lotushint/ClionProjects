//
// Created by lotushint on 2022/6/17.
//
#include "../LinkedString.h"

int main() {
    linkedString s;
    printf("创建字符串s：\n");
    stringCreate(&s);
    display(s);

    printf("\n");

    printf("再次创建字符串s：\n");
    stringCreate(&s);
    display(s);

    printf("\n");

    linkedString t;
    printf("创建字符串t：\n");
    stringCreate(&t);
    display(t);

    printf("\n");

    /*
     * 以下在 s 插入 t 的注释语句不能连用，会形成闭环
     */

//    printf("在s第1个位置插入t：\n");
//    stringInsert(&s, 1, t);
//    display(s);

    printf("\n");

    printf("在s第2个位置插入t：\n");
    stringInsert(&s, 2, t);
    display(s);

    printf("\n");

//    printf("在s第4个位置插入t：\n");
//    stringInsert(&s, 4, t);
//    display(s);

    printf("删除s从第2个位置开始长度为2的子串：\n");
    stringDelete(&s, 2, 2);
    display(s);

    printf("\n");

    printf("删除s从第3个位置开始长度为2的子串：\n");
    stringDelete(&s, 3, 2);
    display(s);

    printf("\n");

    printf("删除s从第3个位置开始长度为100的子串：\n");
    stringDelete(&s, 3, 100);
    display(s);

    printf("\n");
    /*
     * 测试 s1 和 s2 连接
     */
    linkedString s1, s2;
    printf("创建字符串s1：\n");
    stringCreate(&s1);
    display(s1);

    printf("\n");

    printf("创建字符串s2：\n");
    stringCreate(&s2);
    display(s2);

    printf("\n");

    printf("测试 s1 和 s2 连接:\n");
    stringConcat(&s1, s2);
    display(s1);

    printf("\n");

    printf("输出是s1的从第2个位置长度为3的子串:\n");
    linkedString sub;
    sub = substring(s1, 3, 3);
    display(sub);
    return 0;
}
/*
输入:

lotus
hint
12345
lotushint
hefan
 */