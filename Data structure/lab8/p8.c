#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

 

struct HeapStruct;

typedef struct HeapStruct* PriorityQueue;

struct HeapStruct {

	int Capacity;

	int Size;

	int *Elements;

}HeapStruct;

 

void Insert(int X, PriorityQueue H, FILE* fp);

void Find(int X, PriorityQueue H, FILE* fp);

void Print(PriorityQueue H, FILE* fp);

 

int main() {

	FILE* fp;

	FILE* fp_out;

	fp = fopen("input.txt", "r");

	fp_out = fopen("ouput.txt", "w+");

	char menu;

	PriorityQueue PQ;

	PQ = (PriorityQueue)malloc(sizeof(HeapStruct));

	PQ->Size = 0;

	fscanf(fp, "%d", &PQ->Capacity);

	PQ->Elements = (int *)malloc(sizeof(int)*(PQ->Capacity + 1));

	for (int i = 0; i < PQ->Capacity + 1; i++) {

		PQ->Elements[i] = 2147483647;

	}

 

	while (fscanf(fp, " %c", &menu) != EOF) {

		if (menu == 'i') {

			int X;

			fscanf(fp, "%d", &X);

			Insert(X, PQ, fp_out);

		}

		else if (menu == 'f') {

			int X;

			fscanf(fp, "%d", &X);

			Find(X, PQ, fp_out);

		}

		else if (menu == 'p') {

			Print(PQ, fp_out);

		}

	}

 

	free(PQ->Elements);

	free(PQ);

	fclose(fp);

	fclose(fp_out);

	return 0;

}

 

void Insert(int X, PriorityQueue H, FILE* fp) {

	int i;    

	if (H->Capacity == H->Size) {

		fprintf(fp, "heap is full.\n");

		return;

	}

	for (i = 1; i <= H->Size; i++) {

		if (X == H->Elements[i]) {

			fprintf(fp, "%d is already in the heap.\n", X);

			return;

		}

	}

 

	for (i = ++H->Size; H->Elements[i / 2] < X; i /= 2) {

		H->Elements[i] = H->Elements[i / 2];

	}

	H->Elements[i] = X;

	fprintf(fp, "insert %d\n", X);

}

 

void Find(int X, PriorityQueue H, FILE* fp) {

	for (int i = 1; i <= H->Size; i++) {

		if (X == H->Elements[i]) {

			fprintf(fp, "%d is in the heap.\n", X);

			return;

		}

	}

	fprintf(fp, "%d is not in the heap.\n", X);

}

 

void Print(PriorityQueue H, FILE* fp) {

	for (int i = 1; i <= H->Size; i++) {

		if (H->Elements[i] != 2147483647)

			fprintf(fp, "%d ", H->Elements[i]);

		else

			break;

	}

	fprintf(fp, "\n");

}

