#include "task_4.h"

int main() {
    queue *queue = NULL;
    int value;
    srand(time(NULL));
    for(int i = 0; i < 100; i++) {
        value = rand() % 255 + 1;
        queue = addToQueue(queue, value);
    }
    printQueue(queue);
    for(int i = 0; i < 50; i++) {
        int ext_or_not = rand() % 2;
        if(ext_or_not) {
            int priority = rand() % 256;
            int neg_or_not = rand() % 2;
            if(neg_or_not) queue = extractFromQueue(queue, -priority);
            else queue = extractFromQueue(queue, priority);
        }
    }
    return 0;
}
