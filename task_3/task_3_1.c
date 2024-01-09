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
                printw("Enter absolute puth file: ");
                scanw("%s", &(*acc));
                printRules(acc);
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

short printRules(char *filename) {   
    FILE * fp;
    if(!(fp = fopen(filename, "r"))) { printw("Invalid path!\n"); return 0; }
    fclose(fp);
    short binary_view = 0;
    struct stat stat_for_file; 
    char char_view[10];
    stat(filename, &stat_for_file);
    printw("Bit representation: ");
    for(int i=8, j=-8; i>=0; i--, j+=2) {
        short temp = stat_for_file.st_mode & (1 << i);
        binary_view |= temp;
        if(temp != 0) {
            printw("1");
            if (i==8 || i==5 || i==2) char_view[i+j]='r';
            else if (i==1 || i==4 || i==7) char_view[i+j]='w';
            else char_view[i+j]='x';
        }
        else {
            printw("0");
            char_view[i+j]='-';
        }
    }
    printw("\n");
    printw("Numeric representation: %ho\n", stat_for_file.st_mode & 511);
    printw("Alphabetic representation: %s\n", char_view);
    return binary_view;
}
