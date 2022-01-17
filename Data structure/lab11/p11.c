#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define INF 99999

 

typedef struct Node {

	int key;

	int weight;

}Node;

 

typedef struct Heap {

	int capacity;

	int size;

	Node* element;

}Heap;

 

FILE *fp, *fp_out;

 

Heap* createMinHeap(int heapSize);

void insert(Heap* minHeap, int vertex, int distance);

Node deleteMin(Heap* minHeap);

void printShortestPath(int* pred, int* node, int start, int end, int size);

Node* find(int X, Heap* minHeap);

 

 

int main() {

	fp = fopen("input.txt", "r");

	fp_out = fopen("output.txt.", "w+");

	int i;

	int size;

	char str[100] = "";

	int _node[100] = { 0 };

	

	i = 0;

	char temp = 0;

	while (temp != '\n') {

		int node;

		fscanf(fp, "%d", &node);

		_node[i++] = node;

		temp = fgetc(fp);

	}

	size = i;

 

	int ** w = (int **)malloc(sizeof(int*)*size);

	for (i = 0; i < size; i++) {

		w[i] = (int*)malloc(sizeof(int)*size);

		for (int j = 0; j < size; j++) {

			w[i][j] = INF;

		}

	}

 

	temp = 0;

	while (temp != '\n') {

		int node1, node2, weight;

		fscanf(fp,"%d-%d-%d", &node1, &node2, &weight);

		for (i = 0; i < size; i++) {

			if (_node[i] == node1) {

				for (int j = 0; j < size; j++) {

					if (_node[j] == node2) {

						w[i][j] = weight;

					}

				}

			}

		}

		temp = fgetc(fp);

	}

	int start, end;

	fscanf(fp, " %d", &start);

	fscanf(fp, " %d", &end);

 

	Heap* heap = createMinHeap(size);

 

	int* d = (int*)malloc(sizeof(int) * size);

	int* pred = (int*)malloc(sizeof(int)* size);

	for (i = 0; i < size; i++) {

		if (_node[i] == start)

			d[i] = 0;

		else

			d[i] = INF;

		pred[i] = -1;

	}

	

	for (i = 0; i < size; i++) {

		if (_node[i] == start) {

			for (int j = 0; j < size; j++) {

				if (w[i][j] != INF) {

					d[j] = w[i][j];

					pred[j] = start;

					insert(heap, _node[j], d[j]);

				}

			}

		}

	}

 

	while (heap->size != 0){

		Node u = deleteMin(heap);

		

 

		for (i = 0; i < size; i++) {

			if (_node[i] == u.key) {

				for (int j = 0; j < size; j++) {

					if (w[i][j] != 99999) {

						if (d[i] + w[i][j] < d[j]) {

							d[j] = d[i] + w[i][j];

							pred[j] = u.key;

							Node* n = find(_node[j], heap);

							if (n) {

								if(d[j] < n->weight)

									n->weight = d[j];

							}

							else 

								insert(heap, _node[j], d[j]);

						}

					}

				}

			}

		}

	}

 

	printShortestPath(pred, &_node[0], start, end, size);

 

	for (i = 0; i < size; i++) {

		free(w[i]);

	}

	free(w);

	free(d);

	free(pred);

	free(heap->element);

	free(heap);

	fclose(fp);

	fclose(fp_out);

	return 0;

 

}

 

Heap* createMinHeap(int heapSize) {

	Heap* heap = (Heap*)malloc(sizeof(Heap));

	heap->capacity = heapSize;

	heap->size = 0;

	heap->element = (Node*)malloc(sizeof(Node)*(heap->capacity + 1));

	return heap;

}

void insert(Heap* minHeap, int vertex, int distance) {

	int i;

	Node node;

	node.key = vertex;

	node.weight = distance;

	for (i = ++minHeap->size; minHeap->element[i / 2].weight > node.weight; i /= 2) {

		minHeap->element[i] = minHeap->element[i / 2];

	}

	minHeap->element[i] = node;

}

Node deleteMin(Heap* minHeap) {

	int i, Child;

	Node minElement, lastElement;

	minElement = minHeap->element[1];

	lastElement = minHeap->element[minHeap->size--];

	for (i = 1; i * 2 <= minHeap->size; i = Child) {

		Child = i * 2;

		if (Child != minHeap->size && minHeap->element[Child + 1].weight < minHeap->element[Child].weight)

			Child++;

		if (lastElement.weight > minHeap->element[Child].weight)

			minHeap->element[i] = minHeap->element[Child];

		else

			break;

	}

	minHeap->element[i] = lastElement;

	return minElement;

}

 

 

void printShortestPath(int* pred, int* node, int start, int end, int size) {

	int cnt = 0;

	int pre = end;

	int mat[100] = { 0 };

	while (pre != -1) {

		for (int i = 0; i < size; i++) {

			if (node[i] == pre) {

				for (int j = 0; j < 100; j++) {

					if (mat[j] == 0) {

						mat[j] = pre;

						pre = pred[i];

						cnt++;

						break;

					}

				}

				break;

			}

		}

	}

	if (mat[cnt-1] != start) {

		fprintf(fp_out, "no path\n");

	}

	else {

		for (int i = cnt - 1; i >= 0; i--) {

			fprintf(fp_out, "%d ", mat[i]);

		}

		fprintf(fp_out, "\n");

	}

}

 

Node* find(int x, Heap* minHeap) {

	for (int i = 0; i < minHeap->size; i++) {

		if (x == minHeap->element[i].key) {

			return &(minHeap->element[i]);

		}

	}

	return NULL;

}

