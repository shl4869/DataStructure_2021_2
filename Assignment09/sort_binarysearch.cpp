#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

int random(int n)
{
	return rand() % n;
}

void insert_node(TreeNode** root, int key)
{
	TreeNode* p, * t;// p: parent node, t: current node
	TreeNode* n;// n: new node to be inserted
	t = *root;
	p = NULL;

	while (t != NULL) {
		
		p = t;
		if (key < t->key) t = t->left;
		else t = t->right;
	}

	n = (TreeNode*)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	n->key = key;
	n->left = n->right = NULL;

	if (p != NULL)
		if (key < p->key)
			p->left = n;
		else p->right = n;
	else *root = n;
}

void inorder_print(TreeNode* root) {
	if (root) {
		inorder_print(root->left); // Left subtree
		printf("%4d\t", root->key); // Visit root node
		inorder_print(root->right);// Right subtree
	}
}

void main() {
	int input_size = 1000;
	int data_maxval = 10000;

	// output: sorted result
	int* input = (int*)malloc(sizeof(int) * input_size);
	TreeNode** output = (TreeNode**)malloc(sizeof(TreeNode*));

	srand(time(NULL));
	*output = NULL;

	// Generate an input data randomly
	for (int i = 0; i < input_size; i++)
		input[i] = random(data_maxval);
	
	// insert each input to binary search tree
	for (int i = 0; i < input_size; i++)
		insert_node(output, input[i]);

	inorder_print(*output);
	
}