#ifndef TASK_3
#define TASK_3

#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
#include <time.h>
#define N 100

void showMenu();
void bitwiseAccessRights(char *acc);
int alphaToNum(char *str);
int numToBin(int num, int *arr);
void printBin(int *arr);
short printRules(char *filename);

unsigned int convert(char *ip_str);

#endif