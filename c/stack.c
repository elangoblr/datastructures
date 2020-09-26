#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int item;
    struct node *next;
}NODE;

typedef struct stack{
    NODE *head;
}STACK;

STACK* create_stack(){
    STACK* tmp = malloc(sizeof(STACK));
    tmp->head = NULL;
    return tmp;
}

NODE* create_node(int item){
    NODE* tmp = (NODE*)malloc(sizeof(NODE));
    tmp->item = item;
    tmp->next = NULL;
    return tmp;
}

int push(STACK* st, int item){
    NODE* tmp = create_node(item);
    if (st->head == NULL){
        st->head = tmp;
    }else{
        tmp->next = st->head;
        st->head = tmp;
    }
    return 0;
}

NODE* pop(STACK* st){
    NODE* tmp = st->head;
    if (st->head != NULL)
        st->head = st->head->next;
    else
        printf("Stack is empty\n");
    return tmp;
}

void print_stack(STACK *st){
    NODE *tmp = st->head;
    if (tmp == NULL){
        printf("Empty Stack\n");
        return;
    }
    while(tmp){
        printf("%d ", tmp->item);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(){
    printf("Stack Implementation\n");
    STACK *st1 = create_stack();
    int choice;
    int item;
    NODE *tmp;
    while (1)
    {
        /* code */
        printf("1. Print Stack elements\n");
        printf("2. PUSH to stack\n");
        printf("3. POP from stack\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                print_stack(st1);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &item);
                push(st1, item);
                break;
            case 3:
                tmp = pop(st1);
                if (tmp != NULL){
                    printf("Poped element: %d\n", tmp->item);
                    free(tmp);
                }else
                {
                    printf("Cannot POP, empty stack\n");
                }
                break;
            case 4:
                printf("Good Bye!\n");
                exit(0);
        default:
            printf("Invalid choice, try again\n");
            break;
        }
    }
    return 0;
}