#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node * next;
} n;

struct curr {
    struct node * curr;
    struct node * next;
    struct node * prev;
    struct node * head;
    struct node * tail;
};

struct node* list_init(int value){
    struct node * newHead;
    newHead = (struct node *)malloc(sizeof(n));
    newHead->value = value;
    newHead->next = NULL;
    return newHead;
}

struct node* list_add(struct node* head, int value){
    struct node * newNode;
    newNode = (struct node *)malloc(sizeof(n));
    while(head->next != NULL){
        head = head -> next;
    }
    newNode->value = value;
    newNode->next = NULL;
}

int main(void){
    struct node * testHead = list_init(33);
    printf("newHead is: %p\n", testHead);
    printf("newHead->value is: %d\n", testHead->value);
    printf("newHead->next is: %p\n", testHead->next);
}