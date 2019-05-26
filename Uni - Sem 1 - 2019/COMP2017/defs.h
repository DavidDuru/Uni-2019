#include<stdio.h>
#include<stdlib.h>


/*
list_init
Creates a new list by creating and head node
:: int value :: The value to be stored in the head node
Returns a pointer to the newly created node
*/
struct node* list_init(int value);

/*
list_add
Adds a node containing a specified value to an existing list
:: int value :: The value to be stored in the new node
Does not return anything
*/
void list_add(struct node* head, int value);

/*
list_delete
Removes the specified node from the list and updates the list accordingly
:: struct node* n :: The pointer to the node to be deleted
Does not return anything
*/
void list_delete(struct node** head, struct node* n);

/*
list_next
Returns a pointer to the next node in the list
:: const struct node* n :: The node
Returns a pointer to the next node
*/
struct node* list_next(const struct node* n);

/*
list_free
Frees all existing nodes in a list
:: struct node* n :: The pointer to the head node of the list
Does not return anything
*/
void list_free(struct node* head);