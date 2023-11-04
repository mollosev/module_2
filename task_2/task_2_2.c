#include "task_2.h"

int main() {
    while(1) {
        char ch = '0';
        printf("Enter the required action (+ - * /): ");
        scanf("%c", &ch);
        long double a = 0, b = 0;
        printf("Enter first argument: ");
        scanf("%Lf", &a);
        printf("Enter second argument: ");
        scanf("%Lf", &b);
        switch(ch) {
            case '+':
                printf("Result: %Lf", sum(a, b));
                break;
            case '-':
                printf("Result: %Lf", sub(a, b));
                break;
            case '*':
                printf("Result: %Lf", mlp(a, b));
                break;
            case '/':
                printf("Result: %Lf", dvs(a, b));
                break;
        }
        printf("\n");
        getchar();
    }
    
}

long double sum(long double a, long double b) {
    return a + b;
}

long double sub(long double a, long double b) {
    return a - b;
}

long double mlp(long double a, long double b) {
    return a * b;
}

long double dvs(long double a, long double b) {
    return a / b;
}