#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

 

struct AVLNode; 

typedef struct AVLNode *Position; 

typedef struct AVLNode *AVLTree;

struct AVLNode { 

	int Element; 

	AVLTree Left; 

	AVLTree Right;  

	int Height; 

};

 

int Height(Position K);

AVLTree Insert(int X, AVLTree T, FILE* fp, int* ptr_inser);

Position SingleRotateWithLeft(Position K);

Position SingleRotateWithRight(Position K);

Position DoubleRotateWithLeft(Position K);

Position DoubleRotateWithRight(Position K);

void PrintInorder(AVLTree T, FILE* fp);

int Max(int h1, int h2);

 

int main() {

	FILE* fp;

	FILE* fp_out;

	fp = fopen("input.txt", "r");

	fp_out = fopen("ouput.txt", "w+");

	AVLTree Avl;

	Avl = NULL;

	int value;

	int inser_suc = 1;

	int* ptr_inser = &inser_suc;

	while (fscanf(fp, "%d", &value) != EOF) {	

		*ptr_inser = 1;

		Avl = Insert(value, Avl, fp_out, ptr_inser);

		if(*ptr_inser)

			PrintInorder(Avl, fp_out);

		fprintf(fp_out, "\n");

	}

	fclose(fp);

	fclose(fp_out);

	return 0;

}

 

 

int Height(Position K) {

	if (K == NULL)

		return -1;

	else

		return K->Height;

}

 

AVLTree Insert(int X, AVLTree T, FILE* fp, int* ptr_inser) {

	if (T == NULL) {

		T = (AVLTree)malloc(sizeof(struct AVLNode));

		if (T == NULL)

			fprintf(fp, "Out of space!!!");

		else {

			T->Element = X;

			T->Height = 0;

			T->Left = T->Right = NULL;

		}

	}

	else if (X < T->Element) {

		T->Left = Insert(X, T->Left, fp, ptr_inser);

		if (Height(T->Left) - Height(T->Right) == 2)

			if (X < T->Left->Element)

				T = SingleRotateWithLeft(T);

			else

				T = DoubleRotateWithLeft(T);

	}

	else if (X > T->Element) {

		T->Right = Insert(X, T->Right, fp, ptr_inser);

		if (Height(T->Right) - Height(T->Left) == 2)

			if (X > T->Right->Element)

				T = SingleRotateWithRight(T);

			else

				T = DoubleRotateWithRight(T);

	}

	else {

		fprintf(fp, "%d already in the tree!", X);

		*ptr_inser = 0;

		return T;

	}

 

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

	return T;

}

 

Position SingleRotateWithLeft(Position K) {

	Position K1;

	K1 = K->Left;

	K->Left = K1->Right;

	K1->Right = K;

 

	K->Height = Max(Height(K->Left), Height(K->Right)) + 1;

	K1->Height = Max(Height(K1->Left), K->Height) + 1;

 

	return K1;

}

 

Position SingleRotateWithRight(Position K) {

	Position K1;

	K1 = K->Right;

	K->Right = K1->Left;

	K1->Left = K;

 

	K->Height = Max(Height(K->Left), Height(K->Right)) + 1;

	K1->Height = Max(Height(K1->Left), K->Height) + 1;

 

	return K1;

}

 

Position DoubleRotateWithLeft(Position K) {

	K->Left = SingleRotateWithRight(K->Left);

	return SingleRotateWithLeft(K);

}

 

Position DoubleRotateWithRight(Position K) {

	K->Right = SingleRotateWithLeft(K->Right);

	return SingleRotateWithRight(K);

}

 

void PrintInorder(AVLTree T, FILE* fp) {

	if (T) {

		PrintInorder(T->Left, fp);

		fprintf(fp, "%d(%d) ", T->Element, T->Height);

		PrintInorder(T->Right, fp);

	}

}

 

int Max(int h1, int h2) {

	if (h1 >= h2)

		return h1;

	else

		return h2;

}

