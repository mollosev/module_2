#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct queue {
	int data;
	struct queue *next;
} queue;

// struct queue *init (size_t size, int size_prio) {
// 	struct queue * q = calloc (1, sizeof (struct queue));
// 	q->max_prio = size_prio;
// 	q->data = calloc (size_prio, sizeof (void *));
// 	q->low = calloc (size, sizeof (int));
// 	q->high = calloc (size, sizeof (int));
// 	q->max = calloc (size, sizeof (int));
// 	q->count = calloc (size, sizeof (int));
// 	for(int i = 0; i < size_prio; i++) {
// 		q->data[i] = calloc (size, sizeof (int));
// 		q->low[i] = q->high[i] = size - 1;
// 		q->max[i] = size;
// 	}
// 	return q;
// }

queue *queueAdd (queue *queue, int value) {
    queue *newItem = (queue *)malloc(sizeof(queue));
	if (q->min_prio > prio) q->min_prio = prio;
	if (q->count[prio] == q->max[prio]) {
		fprintf (stderr, "not enough queue size\n");
		return -1;
	}
	q->data[prio][q->low[prio]--] = a;
	q->count[prio]++;
	if (q->low[prio] < 0) {
		q->low[prio] = q->max[prio] - 1;
	}
	return 0;
}

int queue_get (struct queue *q, int *val) {
	int a = 0;
	for (int i = q->min_prio; i < q->max_prio; i++) {
		if (q->count[i] > 0) {
			a = q->data[i][q->high[i]--];
			q->count[i]--;

			if (q->high[i] < 0) {
				q->high[i] = q->max[i] - 1;
			}

			q->min_prio = i;

			*val = a;
			return 0;
		}
	}
	printf ("queue is empty\n");
	return -1;
}

int main (int argc, char **argv)
{
	struct queue *q = init (10, 4);

	queue_add (q, 2, 3);
	queue_add (q, 10, 1);
	queue_add (q, 15, 1);
	queue_add (q, 20, 0);

	for (int i = 0; i < 4; i++) {
		int d;
		int ret = queue_get (q, &d);
		printf ("%d: %d\n", i, d);
	}
}