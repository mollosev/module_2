#include "task_3.h"

int main() {
    initscr();
    char acc[N];
    char ch = '0';
    while(ch != '4') {
        showMenu();
        switch(ch) {
            case '1':
                bitwiseAccessRights(acc);
                break;
            case '2':
                printw("2\n");
                break;
            case '3':
                printw("3\n");
                break;
        }
        ch = getch();
        refresh();
    }
    endwin();
    return 0;
}

void showMenu() {
    clear();
    printw("Menu:\n");
    printw("1. Bitwise representation of access rights\n");
    printw("2. Obtaining access rights information\n");
    printw("3. Changing access rights\n");
    printw("4. Exit\n\n");
}

void bitwiseAccessRights(char *acc) {
    char ch = '0';
    int cnt = 0;
    printw("Enter access rights in alphabetic (1) or numeric (2) format: ");
    switch(ch = getch()) {
        case '1':
            printw("\nEnter access rights in alphabetic format (rwxrwxrwz): ");
            scanw("%s", &(*acc));
            cnt = alphaToNum(acc);
            if(cnt != -1) {
                int arr[3];
                if(numToBin(cnt, arr) != -1)
                    printBin(arr);
            }
            break;
        case '2':
            printw("\nEnter access rights in numeric format (777): ");
            scanw("%d", &cnt);
            int arr[3];
            if(numToBin(cnt, arr) != -1)
                printBin(arr);
            break;
    }
}

int alphaToNum(char *str) {
    int rez = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if((str[i] != 'r') && (str[i] != 'w') && (str[i] != 'x') && (str[i] != '-')) {
            printw("Invalid aplphabet format\n");
            return -1;
        }
        if((str[i] == 'r') || (str[i] == 'w') || (str[i] == 'x') || (str[i] != '-')) {
            if(str[i] == 'r')
                rez += 4;
            if(str[i] == 'w')
                rez += 2;
            if(str[i] == 'x')
                rez += 1;
            if(str[i] == '-')
                rez += 0;
        }
        if((((i + 1) % 3) == 0) && i != 8)
            rez *= 10; 
    }
    return rez;
}

int numToBin(int num, int *arr) {
    int rez;
    int cnt = 100;  
    for (int i = 0; i < 3; i++) {
        rez = num / cnt;
        num = num % cnt;
        cnt = cnt / 10;
        if(rez < 0 || rez > 7) {
            printw("Invalid decimal format\n");
            return -1;
        }
        else {
            if(rez == 7) arr[i] = 111;
            if(rez == 6) arr[i] = 110;
            if(rez == 5) arr[i] = 101;
            if(rez == 4) arr[i] = 100;
            if(rez == 3) arr[i] = 011;
            if(rez == 2) arr[i] = 010;
            if(rez == 1) arr[i] = 001;
            if(rez == 0) arr[i] = 000;
        }
    }
    return 1;
}

void printBin(int *arr) {
    printw("Result: ");
    for(int i = 0; i < 3; i++) {
        printw("%d", arr[i]);
        if(i < 2) printw(".");
    }
    printw("\n");
}