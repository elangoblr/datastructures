#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}NODE;

typedef struct list{
    NODE *head;
    NODE *tail;
}LIST;

LIST *create_list(){
    LIST *tmp = malloc(sizeof(LIST));
    tmp->head = NULL;
    tmp->tail = NULL;
    return tmp;
}

void append(LIST *lst, int item){
    NODE *tmp = malloc(sizeof(NODE));
    tmp->data = item;
    tmp->right = NULL;
    if (lst->head == NULL){
        lst->head = tmp;
    	tmp->left = NULL;
    }else{
    	tmp->left = lst->tail;
        lst->tail->right = tmp;
    }
    lst->tail = tmp;
}

void printForward(LIST *lst){
    if (lst->head == NULL){
        printf("Empty List\n");
        return;
    }
    NODE *tmp = lst->head;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->right;
    }
    printf("\n");
}

void printReverse(LIST *lst){
    if (lst->tail == NULL){
        printf("Empty List\n");
        return;
    }
    NODE *tmp = lst->tail;
    while (tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->left;
    }
    printf("\n");
}

int main(){
    LIST *lst = create_list();
    append(lst, 1);
    append(lst, 2);
    append(lst, 3);
    append(lst, 4);
    printForward(lst);
    printReverse(lst);
    return 0;
}
