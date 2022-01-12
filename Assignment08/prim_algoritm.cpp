#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 8
#define INF 1000L

typedef struct {
	int vertex_id;
	int selected;
	int dist;
	int parent;
	int child[MAX_VERTICES];
	int child_num;
	int heap_id;
}vertex;

int weight[MAX_VERTICES][MAX_VERTICES] =
{ { 0,3,INF,INF,INF,INF,INF,14 },
{ 3,0,8,INF,INF,INF,INF,10 },
{ INF,8,0,15,2,INF,INF,INF },
{ INF,INF,15,0,INF,INF,INF,INF },
{ INF,INF,2,INF,0,9,4,5 },
{ INF,INF,INF,INF,9,0,INF,INF },
{ INF,INF,INF,INF,4,INF,0,6 },
{ 14,10,INF,INF,5,INF,6,0 } };

vertex vertices[MAX_VERTICES];

//has vertices id of the element, min heap of vertices.dist
int minheap[MAX_VERTICES+1];
int heap_size = MAX_VERTICES;

void print_heap(int* A) {
		int a = 2;
		for (int i = 1; i <= heap_size; i++) {
			printf("%5d", vertices[A[i]].dist);
			if (i == a - 1) {
				printf("\n");
				a *= 2;
			}
		}
	}

//decrease the element i¡¯s value to ¡®key¡¯
void Decrease_key_min_heap(int* A, int i, int key)
{
	if (key >= vertices[A[i]].dist) {
		fprintf(stderr, "new key is not smaller than current key");
	}
	int tmp;
	vertices[A[i]].dist = key;
	while (0 < i / 2 && vertices[A[i]].dist < vertices[A[i / 2]].dist)
	{
		SWAP(A[i], A[i / 2], tmp);
		SWAP(vertices[A[i]].heap_id, vertices[A[i / 2]].heap_id, tmp);
		i /= 2;
	}

}


void Increase_key_min_heap(int* A, int i, int key)
{
	if (key <= vertices[A[i]].dist) {
		fprintf(stderr, "new key is not larger than current key");
	}
	int tmp;
	vertices[A[i]].dist = key;
	while (i * 2 <= heap_size && (vertices[A[i]].dist > vertices[A[i * 2]].dist || vertices[A[i]].dist > vertices[A[i * 2 + 1]].dist)) {

		if (vertices[A[i]].dist > vertices[A[i * 2]].dist) {
			SWAP(A[i], A[i * 2], tmp);
			SWAP(vertices[A[i]].heap_id, vertices[A[i * 2]].heap_id, tmp);
			Increase_key_min_heap(A, i, vertices[A[i]].dist--);
			i *= 2;
		}

		else if (i * 2 + 1 <= heap_size && vertices[A[i]].dist > vertices[A[i * 2 + 1]].dist) {
			SWAP(A[i], A[i * 2 + 1], tmp);
			SWAP(vertices[A[i]].heap_id, vertices[A[i * 2 + 1]].heap_id, tmp);
			Increase_key_min_heap(A, i, vertices[A[i]].dist--);
			i = i * 2 + 1;
		}

		else
			break;
	}
}

void build_min_heap(int* A) {
	for (int i = 1; i <= MAX_VERTICES; i++) {
		minheap[i] = i - 1;
		vertices[i - 1].heap_id = i;
	}
}

int delete_min_heap(int* A) {
	int return_id = minheap[1];
	int tmp;
	SWAP(A[1], A[heap_size], tmp);
	SWAP(vertices[A[1]].heap_id, vertices[A[heap_size]].heap_id, tmp);
	heap_size--;
	Increase_key_min_heap(A, 1, vertices[A[1]].dist--);
	return return_id;
}

void prim(int s, int n) {
	int i, u, v;

	for (u = 0; u < n; u++) {
		vertices[u].dist = INF;
		vertices[u].selected = FALSE;
	}

	vertices[s].dist = 0;
	build_min_heap(minheap);
	
	for (i = 0; i < n; i++) {
		u = delete_min_heap(minheap);
		vertices[u].selected = TRUE;
		if (vertices[u].dist == INF) return;
		printf("%d ", u);
		for (v = 0; v < n; v++) {
			if (weight[u][v] != INF)
				if (!vertices[v].selected && weight[u][v] < vertices[v].dist) {
					vertices[v].parent = u;
					Decrease_key_min_heap(minheap, vertices[v].heap_id, weight[u][v]);
				}
		}
	}

	for (i = 0; i < MAX_VERTICES; i++) {
		if (i == s)
			continue;
		int j = 0;
		while (vertices[vertices[i].parent].child[j] != NULL)
			j++;
		vertices[vertices[i].parent].child[j] = i;
	}
}

void print_prim(int s) {
	if (s)
		printf("Vertex %d -> %d\t\tedge: %d\n", vertices[s].parent, s, vertices[s].dist);

	for (int i = 0; i < MAX_VERTICES; i++) {
		if (vertices[s].child[i] == NULL)
			return;
		else
			print_prim(vertices[s].child[i]);
	}
}

void main() {
	prim(0, MAX_VERTICES);
	printf("\n\n\nPrim Algoritm Result:\n\n");
	print_prim(0);
}