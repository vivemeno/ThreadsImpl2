//
// Created by vivemeno on 10/4/19.
//
#include "TCB.h"

struct TCB_t* newQueue() {

    struct TCB_t *head = NULL;
    return head;
}
void AddQueue(struct TCB_t **head, struct TCB_t *item) {
    if (!*head) {
        *head = item;
        (*head)->prev = *head;
        return;
    }
    struct TCB_t *lastNode = (*head)->prev;
    lastNode -> next =item;
    item->next = *head;
    (*head)->prev = item;
}

struct TCB_t* DelQueue(struct TCB_t **head) {
    struct TCB_t *nodeToReturn = *head;

    struct TCB_t *lastNode = (*head)->prev;
    *head = (*head)->next;
    (*head)->prev = lastNode;
    lastNode->next = (*head);

    return nodeToReturn;
}