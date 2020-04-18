#define QUEUE_SIZE 32

typedef struct queue {
    int head;
    int tail;
    int buffer[QUEUE_SIZE];
} queue_t;

void init_queue(queue_t *que);

int enqueue(queue_t *que, int data);

int dequeue(queue_t *que);

int queue_empty(queue_t *que);