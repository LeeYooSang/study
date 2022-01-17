#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>


struct QueueRecord; 

typedef struct QueueRecord *Queue;

typedef struct {

	int num;

}ElementType;

 

struct QueueRecord {

	int Capacity;

	int Front;     

	int Rear;    

	int Size;    

	ElementType *Array;

};

 

void MakeEmpty(Queue Q);

void Enqueue(ElementType X, Queue Q, FILE* fp);

void Dequeue(Queue Q, FILE* fp);

 

int main(void) {

	FILE* fp;

	FILE* fp_out;

	fp = fopen("input.txt", "r");

	fp_out = fopen("output.txt", "w+");

	Queue Q;

	Q = (Queue)malloc(sizeof(struct QueueRecord));

	Q->Array = (ElementType*)malloc(sizeof(ElementType)*100);

	MakeEmpty(Q);

	Q->Capacity = 100;

	int cnt;

	fscanf(fp,"%d",&cnt);

	while (cnt) {

		char menu[4];

		fscanf(fp, "%s", menu);

		if (menu[0] == 'e') {

			ElementType X;

			fscanf(fp, "%d", &X.num);

			Enqueue(X, Q, fp_out);

		}

		else if (menu[0] == 'd') {

			Dequeue(Q, fp_out);

		}

 

		cnt--;

	}

	MakeEmpty(Q);

	free(Q->Array);

	free(Q);

	fclose(fp);

	fclose(fp_out);

	return 0;

}

 

void MakeEmpty(Queue Q) { 

	Q->Size = 0;     

	Q->Front = 1;     

	Q->Rear = 0; 

}

 

 

void Enqueue(ElementType X, Queue Q, FILE* fp) { 

	if (Q->Size == Q->Capacity)

		fprintf(fp, "Full\n");     

	else { 

		Q->Size++;            

		Q->Rear = (Q->Rear + 1) % Q->Capacity;   

		Q->Array[Q->Rear] = X; 

	} 

}

 

void Dequeue(Queue Q, FILE* fp) {

	if (Q->Size == 0) {

		fprintf(fp, "Empty\n");

	}

	else {

		Q->Size--;

		fprintf(fp, "%d\n", Q->Array[Q->Front].num);

		Q->Front = (Q->Front + 1) % Q->Capacity;

	}

}
