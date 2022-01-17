#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

FILE* fi;

FILE* fo;

 

typedef struct ListNode * Position;

typedef Position List;

typedef struct HashTbl *HashTable;

 

typedef struct ListNode {

	int Element;

}ListNode;

 

 

typedef struct HashTbl {

	int TableSize;

	List* TheLists;

}HashTbl;

 

 

void Insert(HashTable H, int value, int solution);

void Delete(HashTable H, int value, int solution);

int Find(HashTable H, int value, int solution);

void printTable(HashTable H);

int Hash(int value, int Size, int i, int solution);

 

int main() {

	fi = fopen("input.txt", "r");

	fo = fopen("output.txt", "w+");

	HashTable H = NULL;

	char sol[100];

	int solution;

	int inpnum;

	int size;

	int num;

	fscanf(fi, "%d", &num);

	while (num--) {

		fscanf(fi, " %s", sol);

		fprintf(fo, "%s\n", sol);

		if (strcmp(sol, "Linear") == 0)

			solution = 1;

		else if (strcmp(sol, "Quadratic") == 0)

			solution = 2;

		else if (strcmp(sol, "Double") == 0)

			solution = 3;

		H = malloc(sizeof(HashTbl));

		fscanf(fi, " %d", &size);

		H->TableSize = size;

		H->TheLists = (List*)(malloc(sizeof(List)*(H->TableSize)));

		for (int i = 0; i < size; i++) {

			H->TheLists[i] = malloc(sizeof(ListNode));

			H->TheLists[i]->Element = 0;

		}

		char menu;

		while (fscanf(fi, " %c", &menu) != EOF) {

			switch (menu) {

			case 'i':

				fscanf(fi, " %d", &inpnum);

				Insert(H, inpnum, solution);

				break;

			case 'd':

				fscanf(fi, " %d", &inpnum);

				Delete(H, inpnum, solution);

				break;

			case 'f':

				fscanf(fi, " %d", &inpnum);

				if (Find(H, inpnum, solution) == -1) {

					fprintf(fo, "Not found\n");

				}

				else {

					fprintf(fo, "%d", Find(H, inpnum, solution));

				}

				break;

			case 'p':

				printTable(H);

				break;

			default:

				break;

			}

			if (menu == 'q') {

				free(H->TheLists);

				free(H);

				break;

			}

		}

	}

}

 

void Insert(HashTable H, int value, int solution) {

	if (Find(H, value, solution) == -1) {

		int i = 1;

		int size = H->TableSize;

		int index = value % size;

 

		while (1) {

			if (H->TheLists[index]->Element != 0) {

				index = Hash(value, size, i++, solution);

			}

			else {

				H->TheLists[index]->Element = value;

				fprintf(fo, "Inserted %d\n", value);

				break;

			}

		}

	}

	else {

		fprintf(fo, "Already exists\n");

	}

}

 

void Delete(HashTable H, int value, int solution) {

	if (Find(H, value, solution) == -1) {

		fprintf(fo, "%d not exists\n", value);

	}

	else {

		H->TheLists[Find(H, value, solution)]->Element = 0;

		fprintf(fo, "Delete %d\n", value);

	}

}

 

int Find(HashTable H, int value, int solution) {

	for (int i = 0; i < H->TableSize; i++) {

		if (H->TheLists[i]->Element == value)

			return i;

	}

	return -1;

}

 

 

void printTable(HashTable H) {

	int chk = 1;

	for (int i = 0; i < H->TableSize; i++) {

		if (H->TheLists[i]->Element != 0) {

			chk = 0;

		}

	}

	if (chk == 1) {

		fprintf(fo, "0\n");

	}

	else {

		for (int i = 0; i < H->TableSize; i++) {

			fprintf(fo, "%d ", H->TheLists[i]->Element);

		}

		fprintf(fo, "\n\n");

	}

}

 

int Hash(int value, int Size, int i, int solution) {

	int index = value % Size;

	if (solution == 1) {

		index = index + i;

	}

	else if (solution == 2) {

		index = index + i * i;

	}

	else if (solution == 3) {

		index = (index + i * (7 - (value % 7))) % Size;

	}

	return (index % Size);

}
