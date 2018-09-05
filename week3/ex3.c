#include<stdio.h>
#include<string.h>
#include <malloc.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

void insert_node(Node **head, int value){
    Node *t = (Node*)malloc(sizeof(Node));
    t->value = value;
    t->next = (*head);
    (*head) = t;
}

int delete_node(Node **head){
    Node *prev = NULL;

    if(*head != NULL){

    prev = *head;
    int value = (*head)->value;
    *head = (*head)->next;
    free(prev);

    return value;
    }

    return 0;
}

void print_list(Node *head){
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void main(){
    Node* head = NULL;

    insert_node(&head, 10);
    insert_node(&head, 68);
    insert_node(&head, 4);

    print_list(head);

    delete_node(&head);

    print_list(head);
}
