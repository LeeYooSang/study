# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

typedef struct _Graph {

	int size;

	int * node;

	int **matrix;

}Graph;

 

typedef struct _Queue {

	int* key;

	int first;

	int rear;

	int qsize;

	int max_queue_size;

}Queue;

 

 

FILE *fp, *fp_out;

 

Graph CreateGraph(int* nodes, int size);

void InsertEdge(Graph* G, int a, int b);

void Topsort(Graph* G);

Queue MakeNewQueue(int X);

void Enqueue(Queue* Q, int X);

int Dequeue(Queue* Q);

void DelGraph(Graph* G);

void DelQueue(Queue* Q);

 

int main() {

	fp = fopen("input.txt", "r");

	fp_out = fopen("output.txt.", "w+");

	int i;

	int size;

	char str[100] = "";

	int node[100] = { 0 };

	fgets(str, sizeof(str), fp);

	str[strlen(str) - 1] = '\0';

	char *ptr = strtok(str, " ");

	i = 0;

	while (ptr != NULL) {

		node[i++] = *ptr - 48;

		ptr = strtok(NULL, " ");

	}

	size = i;

 

	Graph *graph = (Graph*)malloc(sizeof(Graph));

	*graph = CreateGraph(&node[0], size);

 

	char edge[200];

	fgets(edge, sizeof(edge), fp);

	ptr = strtok(edge, " ");

	while (ptr != NULL) {

		InsertEdge(graph, (int)ptr[0] - 48, (int)ptr[2] - 48);

		ptr = strtok(NULL, " ");

	}

 

	fprintf(fp_out, "Adjacency matrix\n");

	fprintf(fp_out, " ");

	for (int i = 0; i < graph->size; i++) {

		fprintf(fp_out, " %d", graph->node[i]);

	}

	fprintf(fp_out, "\n");

	for (int i = 0; i < graph->size; i++) {

		fprintf(fp_out, "%d", graph->node[i]);

		for (int j = 0; j < graph->size; j++) {

			fprintf(fp_out, " %d", graph->matrix[i][j]);

		}

		fprintf(fp_out, "\n");

	}

 

	Topsort(graph);

	DelGraph(graph);

	fclose(fp);

	fclose(fp_out);

	return 0;

}

 

Graph CreateGraph(int* nodes, int size) {

	Graph graph;

	graph.size = size;

	graph.node = nodes;

	graph.matrix = (int **)calloc(size, sizeof(int*));

	for (int i = 0; i < size; i++) {

		graph.matrix[i] = (int*)calloc(size, sizeof(int));

	}

	return graph;

}

 

void InsertEdge(Graph* G, int a, int b) {

	int row, col;

	for (int i = 0; i < G->size; i++) {

		if (G->node[i] == a) {

			row = i;

			break;

		}

	}

	for (int i = 0; i < G->size; i++) {

		if (G->node[i] == b) {

			col = i;

			break;

		}

	}

	G->matrix[row][col] = 1;

}

 

void Topsort(Graph *G) {

	fprintf(fp_out, "\n\n\nTopSort Result : ");

	Queue* queue = (Queue*)malloc(sizeof(Queue));

	*queue = MakeNewQueue(G->size);

 

	int q_arr[10] = { 0 };

	int size_arr = 0;

	int temp;

	int V;

	int* indegree;

	indegree = (int *)calloc(G->size, sizeof(int));

	for (int i = 0; i < G->size; i++) {

		for (int j = 0; j < G->size; j++) {

			indegree[i] += G->matrix[j][i];

		}

	}

	for (int i = 0; i < G->size; i++) {

		if (indegree[i] == 0) {

			for (int j = 0; j < 10; j++) {

				if (q_arr[j] == 0) {

					q_arr[j] = G->node[i];

					size_arr++;

					break;

				}

			}

		}

	}

	for (int i = 0; i < size_arr; i++) {

		for (int j = 0; j < size_arr - i - 1; j++) {

			if (q_arr[j] > q_arr[j + 1]) {

				temp = q_arr[j];

				q_arr[j] = q_arr[j + 1];

				q_arr[j + 1] = temp;

			}

		}

	}

	for (int i = 0; i < size_arr; i++) {

		Enqueue(queue, q_arr[i]);

		q_arr[i] = 0;

	}

	size_arr = 0;

	while (queue->qsize != 0) {

		V = Dequeue(queue);

		fprintf(fp_out, "%d ", V);

		for (int i = 0; i < G->size; i++) {

			if (G->node[i] == V) {

				for (int j = 0; j < G->size; j++) {

					if (G->matrix[i][j] == 1) {

						if (--indegree[j] == 0) {

							for (int k = 0; k < 10; k++) {

								if (q_arr[k] == 0) {

									q_arr[k] = G->node[j];

									size_arr++;

									break;

								}

							}

						}

					}

				}

			}

		}

		for (int i = 0; i < size_arr; i++) {

			for (int j = 0; j < size_arr - i - 1; j++) {

				if (q_arr[j] > q_arr[j + 1]) {

					temp = q_arr[j];

					q_arr[j] = q_arr[j + 1];

					q_arr[j + 1] = temp;

				}

			}

		}

		for (int i = 0; i < size_arr; i++) {

			Enqueue(queue, q_arr[i]);

			q_arr[i] = 0;

		}

		size_arr = 0;

	}

	fprintf(fp_out, "\n");

	free(indegree);

	DelQueue(queue);

}

 

Queue MakeNewQueue(int X) {

	Queue queue;

	queue.qsize = 0;

	queue.first = 0;

	queue.rear = -1;

	queue.max_queue_size = X;

	queue.key = (int*)calloc(X, sizeof(int));

	return queue;

}

 

void Enqueue(Queue* Q, int X) {

	Q->qsize++;

	Q->rear = (Q->rear + 1) % Q->max_queue_size;

	Q->key[Q->rear] = X;

}

 

int Dequeue(Queue* Q) {

	Q->qsize--;

	int key = Q->key[Q->first];

	Q->first = (Q->first + 1) % Q->max_queue_size;

	return key;

}

void DelGraph(Graph* G) {

	for (int i = 0; i < G->size; i++) {

		free(G->matrix[i]);

	}

	free(G->matrix);

	free(G);

}

 

void DelQueue(Queue* Q) {

	free(Q->key);

	free(Q);

}

