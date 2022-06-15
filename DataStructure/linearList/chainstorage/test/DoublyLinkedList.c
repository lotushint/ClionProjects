//
// Created by lotushint on 2022/6/9.
//
#include "../DoublyLinkedList.h"

int main() {
    doubleNode *head;
    head = init();
    display(head);
    //7,1,21,31,9,3,2,0
    head = insert(head, 0, 0);
    head = insert(head, 7, 0);
    head = insert(head, 9, 1);
    head = insert(head, 2, 2);
    head = insert(head, 1, 1);
    head = insert(head, 3, 3);
    head = insert(head, 21, 2);
    head = insert(head, 31, 3);
    display(head);
    printf("\n删除3：");
    delete(head, 3);
    display(head);
    printf("\n删除7：");
    delete(head, 7);
    display(head);
    printf("\n删除2：");
    delete(head, 2);
    display(head);
    printf("\n删除1：");
    delete(head, 1);
    display(head);
//    printf("\n删除0：");
//    delete(head, 0);
//    display(head);
}