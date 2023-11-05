#include "task_2.h"

int main() {
    while(1) {
        char ch[4] = {"0"};
        int cnt = 0;
        long double a = 0, b = 0;
        init(ch, &cnt, &a, &b);
        long double (*operation) (long double a, long double b);
        for(int i = 0; i < cnt; i++) {
            operation = select(&ch[i]);
            printf("Result \"%c\": %Lf\n", ch[i], operation(a, b));
        }
    }
    
}

void init(char *ch, int *cnt, long double *a, long double *b) {
    printf("Enter the number of possible commands: ");
    scanf("%d", cnt);
    for(int i = 0; i < *cnt; i++) {
        getchar();
        printf("Enter %d action (+ - * /): ", i + 1);
        scanf("%c", &ch[i]);
    }
    printf("Enter first argument: ");
    scanf("%Lf", a);
    printf("Enter second argument: ");
    scanf("%Lf", b);
}

long double (*select(char *ch)) (long double a, long double b) {
    switch(*ch) {
        case '+':
            return sum;
            break;
        case '-':
            return sub;
            break;
        case '*':
            return mlp;
            break;
        case '/':
            return dvs;
            break;
        default:
            return sum;
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