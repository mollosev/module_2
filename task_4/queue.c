#include "task_4.h"

queue *addToQueue(queue *head, int value) {
    queue *newItem = (queue*)malloc(sizeof(queue));
    newItem->value = value;
    newItem->next = NULL;
    if(head == NULL) {
        return newItem;
    }
    if(head->value < value) {
        newItem->next = head;
        return newItem;
    }
    queue *tmp = head;
    while(tmp->next != NULL) {
        if (tmp->next->value < value) {
            newItem->next = tmp->next;
            tmp->next = newItem;
            return head;
        }
        tmp = tmp->next;
    }
    tmp->next = newItem;
    return head;
}

queue *extractFromQueue(queue *head, int value) {
    queue *tmp = head;
    queue *tmpPrev = NULL;
    if(value == 0) {
        while(tmp->next != NULL) {
            tmpPrev = tmp;
            tmp = tmp->next;
        }
        tmpPrev->next = NULL;
        printf("Extract value: %d\n", tmp->value);
        free(tmp);
        return head;
    }
    if(value > 0) {
        if(head->value == value) {
            printf("Extract value: %d\n", head->value);
            tmp = head->next;
            free(head);
            return tmp;
        }
        tmp = head->next;
        tmpPrev = head;
        while(tmp != NULL) {
            if (tmp->value == value) {
                tmpPrev->next = tmp->next;
                printf("Extract value: %d\n", tmp->value);
                free(tmp);
                return head;
            }
            tmpPrev = tmp;
            tmp = tmp->next;
        }
        return head;
    }
    if(value < 0) {
        value = abs(value);
        if(head->value < value) {
            printf("Not find\n");
            return head;
        }
        tmp = head->next;
        tmpPrev = head;
        while(tmp->next != NULL) {
            if (tmp->next->value < value) {
                tmpPrev->next = tmp->next;
                printf("Extract value: %d\n", tmp->value);
                free(tmp);
                return head;
            }
            tmpPrev = tmp;
            tmp = tmp->next;
        }
        return head;
    }
    return head;
}

void printQueue(queue *head) {
    queue *tmp = head;
    do {
        printf("%d ", tmp->value);
        tmp=tmp->next;
    } while(tmp != NULL);
    printf("\n");
}