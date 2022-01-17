#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#define order 3

 

typedef struct B_node* nodePointer;

typedef	struct B_node {

	int n_keys;

	nodePointer child[order];

	int key[order - 1];

}B_node;

nodePointer root = NULL;

FILE* fp, *fp_out;

 

 

 

void Insert(int key);

void Inorder(nodePointer ptr);

int ins(nodePointer ptr, int key, int *upkey, nodePointer* newnode);

int SearchPos(int key, int *key_arr, int n);

 

int main() {

	fp = fopen("input.txt", "r");

	fp_out = fopen("ouput.txt", "w+");

	char menu;

	while (fscanf(fp, " %c", &menu) != EOF) {

		if (menu == 'i') {

			int key;

			fscanf(fp, "%d", &key);

			Insert(key);

		}

		else if (menu == 'p') {

			Inorder(root);
			
			fprintf(fp_out, "\n");

		}

	}

	free(root);

	fclose(fp);

	fclose(fp_out);

	return 0;

}

 

void Insert(int key) {

	B_node* newnode;

	int upkey;

	int value;

 

	value = ins(root, key, &upkey, &newnode);

	if (value == 0) {

		nodePointer uproot = root;

		root = (nodePointer)calloc(1, sizeof(B_node));

		root->n_keys = 1;

		root->key[0] = upkey;

		root->child[0] = uproot;

		root->child[1] = newnode;

	}

}

 

int ins(nodePointer ptr, int key, int *upkey, nodePointer* newnode) {

	nodePointer newPtr, lastPtr;

	int pos, i, n, splitPos;

	int newKey, lastKey;

	int value;

 

	if (ptr == NULL) {

		*newnode = NULL;

		*upkey = key;

		return 0;

	}

	n = ptr->n_keys;

	pos = SearchPos(key, ptr->key, n);

 

	value = ins(ptr->child[pos], key, &newKey, &newPtr);

 

	if (value != 0)

		return value;

 

	if (n < order - 1) {

		pos = SearchPos(newKey, ptr->key, n);

		for (i = n; i > pos; i--) {

			ptr->key[i] = ptr->key[i - 1];

			ptr->child[i + 1] = ptr->child[i];

		}

		ptr->key[pos] = newKey;

		ptr->child[pos + 1] = newPtr;

		++ptr->n_keys;

		return 1;

	}

	if (pos == order - 1) {

		lastKey = newKey;

		lastPtr = newPtr;

	}

 

	else

	{

		lastKey = ptr->key[order - 2];

		lastPtr = ptr->child[order - 1];

		for (i = order - 2; i > pos; i--) {

			ptr->key[i] = ptr->key[i - 1];

			ptr->child[i + 1] = ptr->child[i];

		}

		ptr->key[pos] = newKey;

		ptr->child[pos + 1] = newPtr;

	}

	splitPos = (order - 1) / 2;

	*upkey = ptr->key[splitPos];

	*newnode = (nodePointer)calloc(1, sizeof(B_node));

	ptr->n_keys = splitPos;

	(*newnode)->n_keys = order - 1 - splitPos;

	for (i = 0; i < (*newnode)->n_keys; i++) {

		(*newnode)->child[i] = ptr->child[i + splitPos + 1];

		if (i < (*newnode)->n_keys - 1)

			(*newnode)->key[i] = ptr->key[i + splitPos + 1];

		else

			(*newnode)->key[i] = lastKey;

	}

	(*newnode)->child[(*newnode)->n_keys] = lastPtr;

	return 0;

}

 

int SearchPos(int key, int *key_arr, int n) {

	int pos = 0;

	while (pos<n && key > key_arr[pos])

		pos++;

	return pos;

}

 

void Inorder(nodePointer ptr) {

	if (ptr) {

		for (int i = 0; i < ptr->n_keys; i++) {

			Inorder(ptr->child[i]);

			fprintf(fp_out, "%d ", ptr->key[i]);

		}

		Inorder(ptr->child[ptr->n_keys]);

	}

}

