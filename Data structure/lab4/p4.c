#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

 

typedef struct threaded_tree* threaded_ptr;  

typedef struct threaded_tree{ 

	short int left_thread; 

	threaded_ptr left_child;  

	char data;

	int num;

	threaded_ptr right_child;  

	short int right_thread;

}threaded_tree;

 

void InsertNode(threaded_ptr node, threaded_ptr tree);

threaded_ptr insucc(threaded_ptr tree);

void tinorder(threaded_ptr tree, FILE* fp);

void LeftThread(threaded_ptr node, threaded_ptr* arr);

void RightThread(threaded_ptr node, threaded_ptr* arr);

 

int main() {

	FILE* fp;

	FILE* fp_out;

	fp = fopen("input.txt", "r");

	fp_out = fopen("output.txt", "w+");

	threaded_ptr root;

	root = (threaded_ptr)malloc(sizeof(threaded_tree));

	root->data = 0;

	root->left_child = NULL;

	root->right_child = root;

	root->left_thread = 1;

	root->right_thread = 0;

	threaded_ptr arr[101];

	arr[0] = root;

	int num;

	int cnt = 0;

	char data;

	fscanf(fp, "%d", &num);

	for(int i=0;i<num;i++){

		cnt++;

		threaded_ptr tmp;

		tmp = (threaded_ptr)malloc(sizeof(threaded_tree));

		fscanf(fp, " %c", &data);

		tmp->data = data;

		tmp->num = cnt;

		InsertNode(tmp, arr[cnt / 2]);

		arr[cnt] = tmp;

	}

	for (int i = 0; i < num + 1; i++) {

		if (arr[i]->left_child== NULL) {

			LeftThread(arr[i], arr);

		}

		if (arr[i]->right_child == NULL) {

			RightThread(arr[i], arr);

		}

	}

	tinorder(root, fp_out);

	fclose(fp);

	fclose(fp_out);

	free(root);

	return 0;

}

 

void InsertNode(threaded_ptr node, threaded_ptr tree) {

	threaded_ptr tmp = node;

	if (tree->left_child == NULL) {

		tree->left_child = tmp;

		tree->left_thread = 0;

	}

	else {

		tree->right_child = tmp;

		tree->right_thread = 0;

	}

	tmp->left_child = NULL;

	tmp->left_thread = 1;

	tmp->right_child = NULL;

	tmp->right_thread = 1;

}

 

void tinorder(threaded_ptr tree, FILE* fp) {

	threaded_ptr tmp = tree;

	for (;;) {

		tmp = insucc(tmp);

		if (tmp == tree) {

			break;

		}

		fprintf(fp, "%-3c", tmp->data);

	}
	fprintf(fp,"\n");

}

 

void LeftThread(threaded_ptr node, threaded_ptr* arr) {

	threaded_ptr tmp1, tmp2;

	int index = node->num / 2;

	tmp1 = arr[index];

	tmp2 = node;

	while (index != 0 && tmp1->right_child != tmp2) {

		tmp2 = arr[index];

		index = index / 2;

		tmp1 = arr[index];

	}

	node->left_child = tmp1;

}

 

void RightThread(threaded_ptr node, threaded_ptr* arr) {

 

	threaded_ptr tmp1, tmp2;

	int index = node->num / 2;

	tmp1 = arr[index];

	tmp2 = node;

	while (index != 0 && tmp1->left_child != tmp2) {

		tmp2 = arr[index];

		index = index / 2;

		tmp1 = arr[index];

	}

	node->right_child = tmp1;

}

 

threaded_ptr insucc(threaded_ptr tree) {

	threaded_ptr tmp;

	tmp = tree->right_child;

	if (!tree->right_thread) {

		while (!tmp->left_thread) {

			tmp = tmp->left_child;

		}

	}

	return tmp;

}
