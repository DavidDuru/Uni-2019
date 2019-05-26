#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
	node* next;
	int v;
};

node* list_init(int v) {
	node* n = malloc(sizeof(node));
	n->v = v;
	n->next = NULL;
	return n;
}

void list_add(node* h, int value) {
	if(h != NULL) {
		node* c = h;
		while(c->next != NULL) {
			c = c->next;
		}
		c->next = list_init(value);
	}
}

void list_delete(node** h, node* n) {
	if(h != NULL) {
		if(*h != NULL) {
			node* p = NULL;
			node* c = *h;
			while(c != n && c != NULL) {
				p = c;
				c = c->next;
			}
			if(c != NULL) {
				if(p != NULL) {
					p->next = c->next;
					free(c);
				} else {
					//node is the head, need to remove it
					node* t = (*h)->next;
					free(*h);
					*h = t;
				}
			}
		}
	}
}

node* list_next(node* n) {
	node* r = NULL;
	if(n) {
		r = n->next;
	}
	return r;
}

void list_free(node* h) {
	node* t = NULL;
	while(h) {
		t = h->next;
		free(h);
		h = t;

	}
}
