//
// Created by hefan on 2022/6/1.
//
#include "../LeadingNodeSinglyLinkedList.h"

int main() {
    node *head;
    head = init();
    display(head);
    head = insert(head, 0, 0);
    head = insert(head, 2, 2);
    head = insert(head, 1, 1);
    head = insert(head, 3, 3);
    head = insert(head, 21, 2);
    head = insert(head, 31, 3);
    display(head);
    head = delete(head, 1);
    display(head);
    head = delete(head, 31);
    display(head);
    return 0;
}