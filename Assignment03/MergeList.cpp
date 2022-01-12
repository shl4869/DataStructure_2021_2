#include <stdio.h>
#include <stdlib.h>


typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

typedef struct ListInfo {
	ListNode** phead;	//pointer of the headnode pointer
	ListNode** plast;	//pointer of the lastnode pointer
}ListInfo;


void init(ListInfo* list) {
	list->phead = (ListNode**)malloc(sizeof(ListNode*));
	list->plast = (ListNode**)malloc(sizeof(ListNode*));
	*list->phead = NULL;
	*list->plast = NULL;
}

void insert_last(ListInfo list, element new_data) {
	//insert a new node to the last of the list

	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = new_data;
	new_node->link = NULL;

	if (*list.phead == NULL) {
		*list.phead = new_node;
		*list.plast = new_node;
	}
	else {
		(*list.plast)->link = new_node;
		*list.plast = new_node;
	}
}

void display_list(ListInfo list){
	//display the linked list untill the last node

	ListNode* current_node = *list.phead;
	while (current_node != NULL) {
		printf("%d", current_node->data);
		current_node = current_node->link;
		if (current_node!=NULL)
			printf(" ");
	}
}

ListInfo merge_list(ListInfo listA, ListInfo listB) {
	//merge the two list by ascending order

	ListInfo listMerged;
	init(&listMerged);

	ListNode* cntA = *listA.phead;
	ListNode* cntB = *listB.phead;

	while (cntA != NULL || cntB != NULL) {
		if (cntA == NULL) {
			insert_last(listMerged, cntB->data);
			cntB = cntB->link;
		}
		else if (cntB == NULL) {
			insert_last(listMerged, cntA->data);
			cntA = cntA->link;
		}
		else {
			if (cntA->data > cntB->data) {
			insert_last(listMerged, cntB->data);
			cntB = cntB->link;
			}
			else {
			insert_last(listMerged, cntA->data);
			cntA = cntA->link;
			}
		}
	}

	return listMerged;
}

void main() {
	ListInfo listA, listB;

	init(&listA);
	init(&listB);
	
	int elementA[7] = { 1,2,5,10,15,20,25 };
	int elementB[6] = { 3,7,8,15,18,30 };

	for (int i = 0; i < 7; i++) {
		if (i == 6)
			insert_last(listA, elementA[i]);
		else {
			insert_last(listA, elementA[i]);
			insert_last(listB, elementB[i]);
		}
	}

	ListInfo mergedList = merge_list(listA, listB);

	printf("listA:\n");
	display_list(listA);
	printf("\n\n");
	printf("listB\n");
	display_list(listB);
	printf("\n\n");
	printf("A and B merged:\n");
	display_list(mergedList);

}