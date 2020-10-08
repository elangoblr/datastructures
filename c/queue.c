#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev, *next;
}NODE;

typedef struct queue{
    NODE *front, *tail;
    int size;
}QUEUE;

QUEUE *create_queue(){
    QUEUE *tmp = malloc(sizeof(QUEUE));
    tmp->front = NULL;
    tmp->tail = NULL;
    int size = 0;
    return tmp;
}

NODE *dequeue(QUEUE *q){
    if (q->front == NULL)
        return NULL;
    NODE *tmp = q->front;
    q->front = q->front->next;
    if (q->front == NULL){
        q->tail = NULL;
    }else{
        q->front->prev = NULL;
    }
    tmp->next = NULL;
    q->size--;
    return tmp;
}

void enqueue(QUEUE *q, int item){
    NODE *tmp = malloc(sizeof(NODE));
    tmp->data = item;
    tmp->prev = NULL;
    tmp->next = NULL;
    if (q->front == NULL){
        q->front = tmp;
        q->tail = tmp;
    } else {
        q->tail->next = tmp;
        tmp->prev = q->tail;
        q->tail = tmp;
    }
    q->size++;
}

void printQueue(QUEUE *q){
    if (q->front == NULL){
        printf("Empty Queue\n");
        return;
    }
    NODE *tmp = q->front;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(){
    QUEUE *q1 = create_queue();
    printQueue(q1);
    enqueue(q1, 10);
    printQueue(q1);
    NODE *tmp = dequeue(q1);
    printf("Dequeued element %d\n", tmp->data);
    free(tmp);
    printQueue(q1);
    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    printQueue(q1);
    printf("Current queue size: %d\n", q1->size);
    tmp = dequeue(q1);
    printf("Dequeued element %d\n", tmp->data);
    free(tmp);
    tmp = dequeue(q1);
    printf("Dequeued element %d\n", tmp->data);
    free(tmp);
    tmp = dequeue(q1);
    printf("Dequeued element %d\n", tmp->data);
    free(tmp);
    tmp = dequeue(q1);
    if (tmp != NULL){
        printf("Dequeued element %d\n", tmp->data);
        free(tmp);
    }
    printQueue(q1);
    printf("Current queue size: %d\n", q1->size);
    return 0;
}
