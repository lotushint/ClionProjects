//
// Created by lotushint on 2022/7/5.
// 将树的层号表示转换成树的扩充孩子表示（增加一个域指向结点双亲的下标）
//
#include "../leveltochild/LevelToChildRepresentation.h"

int main() {
    level[0].data = 'A';
    level[0].level = 10;

    level[1].data = 'B';
    level[1].level = 20;

    level[2].data = 'C';
    level[2].level = 20;

    level[3].data = 'F';
    level[3].level = 30;

    level[4].data = 'G';
    level[4].level = 30;

    level[5].data = 'H';
    level[5].level = 30;

    level[6].data = 'D';
    level[6].level = 20;

    level[7].data = 'E';
    level[7].level = 20;

    level[8].data = 'J';
    level[8].level = 40;

    level[9].data = 'I';
    level[9].level = 40;
    length = 10;

    levelToChildRepresentation(length, level, tree, &root);
    printf("前序遍历的结果:\n");
    preorderTraverse(tree, root);
    printf("\n%d", length);
    return 0;
}