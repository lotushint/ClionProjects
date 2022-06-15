//
// Created by lotushint on 2022/6/15.
//
#include "../ChainStack.h"
#include "stdio.h"

int main() {
    node *top;
    top = init();
//    display(top);

    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    printf("栈元素分别为：");
    display(top);

    printf("出栈：");
    top = pop(top);
    display(top);

    printf("出栈：");
    top = pop(top);
    display(top);

    printf("出栈：");
    top = pop(top);
    display(top);

    return 0;
}