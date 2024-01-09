#ifndef TASK_6
#define TASK_6

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <dlfcn.h>

#define N 20
#define cntSocial 2

typedef struct phoneBook {
    int id;
    char lastName[N];
    char firstName[N];
    char fatherName[N];
    char job[N];
    char jobTitle[N];
    long int phone;
    char email[N];
    char socialLinks[cntSocial][N];
} phoneBook;

typedef struct list {
    phoneBook profile;
    struct list *next;
    struct list *prev;
} list;

list *addElem(list *head, phoneBook a);
list *deleteElem(list *head, int val);
list *deleteList(list *head);
list *findInList(list* head, int id);
void printList(list *head);

void showMenu();
list *addProfile(list *head);
void printProfile(phoneBook profile);
void deleteProfile(phoneBook *profile);
list *editProfile(list *head, int id);

void init(char *ch, int *cnt, long double *a, long double *b);
long double (*select(char *ch)) (long double a, long double b);

#endif