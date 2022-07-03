//
// Created by hefan on 2022/6/4.
//
#include "../CircularSinglyLinkedList.h"

int main() {
    TreeNode *head;
    head = circularInit();
    //7,1,21,31,9,3,2,0,
    head = circularInsert(head, 0, 0);
    head = circularInsert(head, 7, 0);
    head = circularInsert(head, 9, 1);
    head = circularInsert(head, 2, 2);
    head = circularInsert(head, 1, 1);
    head = circularInsert(head, 3, 3);
    head = circularInsert(head, 21, 2);
    head = circularInsert(head, 31, 3);
    circularDisplay(head);
    printf("\n删除3：");
    head = circularDelete(head,3);
    circularDisplay(head);
    printf("\n删除7：");
    head = circularDelete(head,7);
    circularDisplay(head);
    printf("\n删除0：");
    head = circularDelete(head,0);
    circularDisplay(head);
//    head = circularDelete(head, 1);
//    circularDisplay(head);
//    head = circularDelete(head, 31);
//    circularDisplay(head);
    return 0;
}