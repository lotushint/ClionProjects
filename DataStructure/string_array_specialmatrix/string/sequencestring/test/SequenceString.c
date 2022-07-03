//
// Created by lotushint on 2022/6/16.
//
#include "../SequenceString.h"

int main() {
    sequenceString *s;
    s = (sequenceString *) malloc(sizeof(sequenceString));
    s->string[0] = 's';
    s->string[1] = 't';
    s->string[2] = 'a';
    s->string[3] = 'r';
    s->string[4] = 't';
    s->string[5] = '\0';
    s->length = 5;

    sequenceString t;
    t.string[0] = 'e';
    t.string[1] = 'n';
    t.string[2] = 'd';
    t.string[3] = '\0';
    t.length = 3;

    printf("将 t 中存放的字符串连接到 s 中存放的字符串的后面构成一个新串 c 返回:");
    sequenceString *c = stringConcat(*s, t);
    printf("\n%s", c->string);

    printf("\n");

    printf("在字符串 c 中，从第 2 个字符开始取 2 个连续字符构成一个子串返回");
    sequenceString *substr = substring(c, 2, 2);
    printf("\n%s", substr);

    printf("\n");

    printf("将字符串 t 插入到字符串 s 的第 1 个字符之前:");
    stringInsert(s, 1, t);
    printf("\n%s", s->string);

    printf("\n");

    printf("将字符串 s 中第 1 个字符开始长度为 2 的子串删除:");
    stringDelete(s, 1, 2);
    printf("\n%s", s->string);
    return 0;
}