//
// Created by lotushint on 2022/6/15.
//
#include "../ChainedQueue.h"

int main() {
    queue *queue;
    queue = init();
//    display(queue);

    queue = insert(queue, 1);
    queue = insert(queue, 2);
    queue = insert(queue, 3);
    queue = insert(queue, 4);
    queue = insert(queue, 5);
    printf("\n链式队列各个元素：");
    display(queue);

    printf("\n读链式队列第一个元素：");
    printf("%d\n", read(*queue));
    printf("\n删除链式队列第一个元素：");
    queue = delete(queue);
    display(queue);

    printf("\n读链式队列第一个元素：");
    printf("%d\n", read(*queue));
    printf("\n删除链式队列第一个元素：");
    queue = delete(queue);
    display(queue);

    printf("\n读链式队列第一个元素：");
    printf("%d\n", read(*queue));
    printf("\n删除链式队列第一个元素：");
    queue = delete(queue);
    display(queue);


}