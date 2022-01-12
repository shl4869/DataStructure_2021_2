// linked_stack.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int element;

typedef struct DlistNode {
	element item;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

//typedef struct StackNode {
//	element item;
//	struct StackNode *link;
//} StackeNode;

typedef struct {
	DlistNode* head;
} LinkedStackType;

void init(DlistNode* s)
{
	//headnode creation
	s->llink = s->rlink = s;
}

int is_empty(DlistNode* s)
{
	return (s->rlink == s);
}

void push(DlistNode* s, element item)
{
	DlistNode* temp = (DlistNode*)malloc(sizeof(DlistNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return;
	}

	else {
		
		temp->item = item;
		temp->llink = s->llink;
		temp->rlink = s;
		s->llink->rlink = temp;
		s->llink = temp;
	}
}

element pop(DlistNode* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		DlistNode* temp = s->llink;
		int item = temp->item;
		s->llink = s->llink->llink;
		temp->llink->rlink = s;
		free(temp);
		return item;
	}
}

element peek(DlistNode* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->llink->item;
	}
}

void main()
{
	DlistNode s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}




