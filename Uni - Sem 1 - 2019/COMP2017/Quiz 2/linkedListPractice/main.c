#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

struct node{
    int value;
    void * next;
};

void printList(struct node * curr);

int main(int argc, char *argv[]){

    printf("AIDAN'S LINKED LIST\n\n");

    struct node * list = list_init(10);
    puts("created new list head\n");
    printList(list);

    list_add(list, 9);
    printList(list);

    return 0;

}

struct node* list_init(int value){
    struct node * newList = malloc(sizeof(struct node));
    newList->value = value;
    newList->next = NULL;
    return newList;
}

void list_add(struct node* head, int value){
    struct node * curr = head;

    while(curr->next != NULL){
        curr = curr->next;
    }

    struct node * newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;

    curr->next = newNode;

}

void list_delete(struct node** head, struct node* n){
    
}

void printList(struct node * curr){
    puts("Printing List");

    while(curr != NULL){
        printf("[address: %p, value: %d]->", curr, curr->value);
        curr = curr->next;
    }

    if(curr == NULL){
        printf("[X]\n");
    }
}

