//
// Created by hefan on 2022/5/31.
//
#include "../SequentialCircularQueue.h"

int main() {
    sequence_queue sq;
    init(&sq);
    printf("循环队列是否为空：%d\n", emptyCircularQueue(sq));

    printf("队尾插入1：");
    insertCircularQueue(&sq, 1);
    displayCircularQueue(sq);
    printf("\n队尾插入3：");
    insertCircularQueue(&sq, 3);
    displayCircularQueue(sq);
    printf("\n队尾插入8：");
    insertCircularQueue(&sq, 8);
    displayCircularQueue(sq);
    printf("\n队首：%d", get(sq));

    deleteCircularQueue(&sq);
    printf("\n删除队首：");
    displayCircularQueue(sq);

    return 0;
}