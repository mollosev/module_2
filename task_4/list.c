#include "task_4.h"

list *addElem(list *head, phoneBook a) {
    list *newElem = (list*)malloc(sizeof(list));
    list *tmp = head;
    newElem->profile = a;
    if(NULL == head) {
        newElem->prev = newElem;
        newElem->next = newElem;
        head = newElem;
        return head;
    }
    do {
        if(newElem->profile.id <= tmp->profile.id) {
            newElem->next = tmp;
            newElem->prev = tmp->prev;
            tmp->prev->next = newElem;
            tmp->prev = newElem;
            if(tmp == head) head = newElem;
            return head;
        }
        tmp = tmp->next;
    } while(tmp != head);
    newElem->next = tmp;
    newElem->prev = tmp->prev;
    tmp->prev->next = newElem;
    tmp->prev = newElem;
    return head;
}

list *deleteElem(list *head, int val) {
    list *tmp = head;
    if(NULL == head) {
        printw("List empty!\n");
        return head;
    }
    do {
        if(val == tmp->profile.id) {
            if(tmp->next == tmp->prev) {
                free(tmp);
                printw("Single profile is deleted\n");
                return NULL;
            }
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            if(tmp == head) head = head->next;
            free(tmp);
            printw("Profile ID=%d is deleted!\n", val);
            return head;
        }
        tmp = tmp->next;
    } while(tmp != head);
    printw("List does not contain %d!\n", val);
    return head;
}

list *deleteList(list *head) {
    list *tmp = head;
    list *delete;
    if(NULL == head) {
        return NULL;
    }
    do {
        delete = tmp;
        tmp = tmp->next;
        free(delete);
    } while(tmp != head);
    return NULL;
}

list *findInList(list* head, int id) {
    list *tmp = head;
    if(NULL == head) {
        printw("List empty!\n");
        return head;
    }
    do {
        if(tmp->profile.id == id)
            return tmp;
        tmp = tmp->next;
    } while(tmp != head);
    if (tmp == head && tmp->profile.id != id) {
        printw("Wrong id\n");
        return NULL;
    }
    return tmp;
}

void printList(list *head) {
    list *tmp = head;
    if(NULL == head) {
        printw("List empty!\n");
        return;
    }
    do {
        printProfile(tmp->profile);
        tmp = tmp->next;
    } while(tmp != head);
    printw("\n");
}