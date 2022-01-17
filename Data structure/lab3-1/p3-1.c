#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

struct Node; 

typedef struct Node *PtrToNode;

typedef PtrToNode Stack;

typedef struct {

	int num;

}ElementType;

 

struct Node {

	ElementType Element;

	PtrToNode Next;

};

 

Stack CreateStack(FILE* fp);

void MakeEmpty(Stack S, FILE* fp);

void Push(ElementType X, Stack S, FILE* fp);

void Pop(Stack S, FILE* fp);

int IsEmpty(Stack S);

 

int main(void) {

	FILE* fp;

	FILE* fp_out;

	fp = fopen("input.txt", "r");

	fp_out = fopen("output.txt", "w+");

	Stack S = CreateStack(fp_out);

	int cnt;

	fscanf(fp, "%d", &cnt);

	while (cnt) {

		char menu[5];

		fscanf(fp, "%s", menu);

		if (menu[1] == 'u') {

			ElementType X;

			fscanf(fp, "%d", &X.num);

			Push(X, S, fp_out);

		}

		else if (menu[1] == 'o') {

			Pop(S, fp_out);

		}

		cnt--;

	}

	MakeEmpty(S, fp_out);
	
	free(S);

	fclose(fp);

	fclose(fp_out);

	return 0;

}

 

Stack CreateStack(FILE* fp) {

	Stack S;

	S = (Stack)malloc(sizeof(struct Node));

	if (S == NULL)

		fprintf(fp, "Out of space!!!\n");

	S->Next = NULL;

	return S;

}

 

void MakeEmpty(Stack S, FILE* fp) {

	if (S == NULL)
	
		fprintf(fp, "No stack exists\n");

	else

	{

		while (!IsEmpty(S)) {

			Pop(S, fp);

		}

	}

}

 

void Push(ElementType X, Stack S, FILE* fp) {

	PtrToNode TmpCell;

	TmpCell = (Stack)malloc(sizeof(struct Node));

	if (TmpCell == NULL) {

		fprintf(fp, "Out of space!!!\n");

	}

	else {

		TmpCell->Element = X;

		TmpCell->Next = S->Next;

		S->Next = TmpCell;

	}

}

 

void Pop(Stack S, FILE* fp) {

	PtrToNode FirstCell;

	if (IsEmpty(S)) {

		fprintf(fp, "Empty\n");

	}

	else {

		FirstCell = S->Next;

		fprintf(fp, "%d\n", FirstCell->Element.num);

		S->Next = S->Next->Next;

		free(FirstCell);

	}

}

 

int IsEmpty(Stack S) {

	return S->Next == NULL;

}
