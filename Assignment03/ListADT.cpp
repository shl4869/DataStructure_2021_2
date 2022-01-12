#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

typedef struct {
	ListNode* head;// Head pointer
	ListNode* tail;// Tail pointer
	int length;// # of nodes
} ListType;



void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ListType* list) {
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
}

int is_empty(ListType* list)
{
	if (list->head == NULL) return 1;
	else return 0;
}

int get_length(ListType* list)
{
	return list->length;
}

// Return node pointer of ¡®pos¡¯ in the list.
ListNode* get_node_at(ListType* list, int pos)
{
	int i;
	ListNode* tmp_node = list->head;
	if (pos < 0) return NULL;
	for (i = 0; i < pos; i++)
		tmp_node = tmp_node->link;
	return tmp_node;
}

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		if (p == NULL) {
			new_node->link = *phead;
			*phead = new_node;
		}
		else {
			new_node->link = p->link;
			p->link = new_node;
		}
	}
}

// Insert new data at the ¡®position¡¯
void add(ListType* list, int position, element data)
{
	ListNode* p;
	if ((position >= 0) && (position <= list->length)) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		if (node == NULL) error("Memory allocation error");
		node->data = data;
		p = get_node_at(list, position - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}
}

void add_first(ListType* list, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) error("Memory allocation error");
	else {
		node->data = data;
		if (list->tail == NULL)
			list->tail = node;
		insert_node(&(list->head), NULL, node);
		list->length++;
	}

}

void add_last(ListType* list, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) error("Memory allocation error");
	else {
		node->data = data;
		insert_node(&(list->head), list->tail, node);
		list->tail = node;
		list->length++;
	}
}

// phead : pointer to the head pointer
// p: preceding node to be deleted
// removed: node to be deleted
void remove_node(ListNode** phead, ListNode* p, ListNode* removed)
{
	if (*phead == NULL) error("The list is blank.\n");
	else {
		if (p == NULL) { /*error("The preceding node cannot be NULL.\n");*/
			*phead = removed->link;
			free(removed);
		}
		else {
			p->link = removed->link;
			free(removed);
		}
	}
}

void delete_node(ListType* list, int pos)	
//delete was preserved statement, so name of the function was changed.
{
	if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
		ListNode* p = get_node_at(list, pos - 1);
		ListNode* removed = get_node_at(list, pos);
		remove_node(&(list->head), p, removed);
		list->length--;
	}
}

void delete_first(ListType* list) {
	if (list->length==1)
		list->tail = NULL;
	remove_node(&(list->head), NULL, list->head);
	list->length--;
}

void delete_last(ListType* list) {
	ListNode* p = get_node_at(list, list->length - 1);
	remove_node(&(list->head), p, list->tail);
	list->tail = p;
	list->length--;
}

// Return the data at the ¡®pos¡¯.
element get_entry(ListType* list, int pos)
{
	ListNode* p;
	if (pos >= list->length) error("Position error");
		p = get_node_at(list, pos);
	return p->data;
}

// Display data in the buffer. 
void display(ListType* list)
{
	int i;
	ListNode* node = list->head;
	printf("( ");
	for (i = 0; i < list->length; i++) {
		printf("%d ", node->data);
		node = node->link;
	}
	printf(" )\n");
}

// Find a node whose data = item
int is_in_list(ListType* list, element item)
{
	ListNode* p;
	p = list->head;
	while ((p != NULL)) {
		if (p->data == item)
			break;
		p = p->link;
	}
	if (p == NULL) return FALSE;
	else return TRUE;
}



int main()
{
	ListType list1;
	init(&list1);
	add_first(&list1, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);
	add(&list1, 2, 70);
	display(&list1);
	delete_node(&list1, 2);
	delete_first(&list1);
	delete_last(&list1);
	display(&list1);
	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "TRUE" : "FALSE");
	printf("%d\n", get_entry(&list1, 0));
}