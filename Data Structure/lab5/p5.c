#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

 

typedef struct TreeNode* treeptr;  

typedef struct TreeNode{ 

	int value; 

	treeptr left, right; 

}TreeNode;

 

treeptr Find(int x, treeptr T, FILE* fp);

treeptr Insert(int x, treeptr T, FILE* fp);

treeptr Delete(int x, treeptr T, FILE* fp);

treeptr FindMax(treeptr T);

void PrintInorder(treeptr T, FILE* fp);

void PrintPreorder(treeptr T, FILE* fp);

void PrintPostorder(treeptr T, FILE* fp);

 

 

int main() {

	FILE* fp;

	FILE* fp_out;

	fp = fopen("input.txt","r");

	fp_out = fopen("ouput.txt", "w+");

	treeptr Bst;

	Bst = NULL;

	char oper[3];

	int value;

	while (fscanf(fp, "%s", oper) != EOF) {

		if (oper[0] == 'i') {

			fscanf(fp, "%d", &value);

			Bst = Insert(value, Bst, fp_out);

		}

		else if (oper[0] == 'd') {

			fscanf(fp, "%d", &value);

			Bst = Delete(value, Bst, fp_out);

		}

		else if (oper[0] == 'f') {

			fscanf(fp, "%d", &value);

			Bst = Find(value, Bst, fp_out);

		}

		else if (oper[1] == 'i') {

			fprintf(fp_out, "pi -");

			PrintInorder(Bst, fp_out);

			fprintf(fp_out, "\n");

		}

		else if (oper[1] == 'r') {

			fprintf(fp_out, "pr -");

			PrintPreorder(Bst, fp_out);

			fprintf(fp_out, "\n");

		}

		else if (oper[1] == 'o') {

			fprintf(fp_out, "po -");

			PrintPostorder(Bst, fp_out);

			fprintf(fp_out, "\n");

		}

	}

 

 

	fclose(fp);

	fclose(fp_out);

	return 0;

}

 

treeptr Find(int x, treeptr T, FILE* fp) {

	if (T == NULL) {

		fprintf(fp, "%d is not in the tree\n", x);

		return NULL;

	}

	if (x < T->value)

		return Find(x, T->left, fp);

	else if (x > T->value)

		return Find(x, T->right, fp);

	else {

		fprintf(fp, "%d is in the tree\n", x);

		return T;

	}

}

 

treeptr Insert(int x, treeptr T, FILE* fp) {

	if (T == NULL) {

		T = (treeptr)malloc(sizeof(TreeNode));

		if (T == NULL)

			fprintf(fp, "Out of space!!!\n");

		else {

			T->value = x;

			T->left = T->right = NULL;

		}

	}

	else if (x < T->value)

		T->left = Insert(x, T->left, fp);

	else if (x > T->value)

		T->right = Insert(x, T->right, fp);

	else

		fprintf(fp, "%d already exists\n", x);

	return T;

}

 

treeptr Delete(int x, treeptr T, FILE* fp) {

	if (T == NULL)

		fprintf(fp, "Deletion failed. %d does not exist\n", x);

	else if (x < T->value)

		T->left = Delete(x, T->left, fp);

	else if (x > T->value)

		T->right = Delete(x, T->right, fp);

	else if (T->left && T->right) {

		treeptr TmpCell;

		TmpCell = FindMax(T->left);

		T->value = TmpCell->value;

		T->left = Delete(T->value, T->left, fp);

	}

	else {

		treeptr TmpCell;

		TmpCell = T;

		if (T->left == NULL)

			T = T->right;

		else if (T->right == NULL)

			T = T->left;

		free(TmpCell);

	}

	return T;

}

 

treeptr FindMax(treeptr T) {

	if (T == NULL)

		return NULL;

	else if( T -> right == NULL){

		return T;		

	}

	else

		return FindMax( T -> right);

}

 

void PrintInorder(treeptr T, FILE* fp) {

	if (T) {

		PrintInorder(T->left,fp);

		fprintf(fp,"%2d", T->value);

		PrintInorder(T->right,fp);

	}

}

 

void PrintPreorder(treeptr T, FILE* fp) {

	if (T) {

		fprintf(fp, "%2d", T->value);

		PrintPreorder(T->left, fp);

		PrintPreorder(T->right, fp);

	}

}

 

void PrintPostorder(treeptr T, FILE* fp) {

	if (T) {

		PrintPostorder(T->left, fp);

		PrintPostorder(T->right, fp);

		fprintf(fp, "%2d", T->value);

	}

 

}

