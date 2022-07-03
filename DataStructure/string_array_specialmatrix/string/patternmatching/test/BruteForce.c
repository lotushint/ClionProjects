//
// Created by lotushint on 2022/6/18.
//
#include "../BruteForce.h"

int main() {
    sequenceString p;
    p.string[0] = 'l';
    p.string[1] = 'o';
    p.string[2] = 't';
    p.string[3] = 'u';
    p.string[4] = 's';
    p.string[5] = '\0';
    p.length = 5;

//    sequenceString p;
//    p.string[0] = 't';
//    p.string[1] = 'u';
//    p.string[2] = 's';
//    p.string[3] = 'n';
//    p.string[4] = 't';
//    p.string[5] = '\0';
//    p.length = 5;

//    sequenceString t;
//    t.string[0] = 'h';
//    t.string[1] = 'i';
//    t.string[2] = 'l';
//    t.string[3] = 'o';
//    t.string[4] = 't';
//    t.string[5] = 'u';
//    t.string[6] = 's';
//    t.string[7] = 'n';
//    t.string[8] = 't';
//    t.string[9] = '\0';
//    t.length = 9;

    sequenceString t;
    t.string[0] = 'l';
    t.string[1] = 'o';
    t.string[2] = 't';
    t.string[3] = 'u';
    t.string[4] = 's';
    t.string[5] = 'n';
    t.string[6] = 't';
    t.string[7] = '\0';
    t.length = 7;
    printf("p 在 t 中的位置的第一个字符是 t 的第%d个字符", bruteForce(p, t));

    printf("\n书上的程序：\n");

    printf("p 在 t 中的位置的第一个字符是 t 的第%d个字符", getIndex(p, t) + 1);
    return 0;
}