#ifndef TASK_2
#define TASK_2

#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#define N 20

typedef struct phoneBook {
    char lastName[N];
    char firstName[N];
    char fatherName[N];
    char job[N];
    char jobTitle[N];
    long int phone;
    char email[N];
    char socialLinks[N][N];
} phoneBook;

void showMenu();
void addProfile(phoneBook *profile, int *cntSocial);
void printProfile(phoneBook *profile, int cntSocial);
void deleteProfile(phoneBook *profile, int cntSocial);
void editProfile(phoneBook *profile, int cntSocial);

long double sum(long double a, long double b);
long double sub(long double a, long double b);
long double mlp(long double a, long double b);
long double dvs(long double a, long double b);

void init(char *ch, int *cnt, long double *a, long double *b);
long double (*select(char *ch)) (long double a, long double b);

#endif