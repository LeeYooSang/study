#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include<string.h>

#define EmptyTos -1

 

typedef struct StackRecord *Stack;

typedef struct {

	char oper;

}ElementType;

struct StackRecord { 

	int Capacity;    

	int TopOfStack;    

	ElementType *Array; 

};

 

 

Stack CreateStack(FILE* fp);

void Push(ElementType X, Stack S, FILE* fp);

char Pop(Stack S, FILE* fp);

int InStackPriority(char oper);

int GetPriority(char oper);

int Calculate(char* exp);

 

int main(void) {

	FILE* fp;

	FILE* fp_out;

	fp = fopen("input.txt", "r");

	fp_out = fopen("output.txt", "w+");

	Stack S = CreateStack(fp_out);

	char infix[100];

	char postfix[100] = "";

	fscanf(fp, "%s", infix);

	int cnt = 0;

	for (int i = 0; i < strlen(infix); i++) {

		if (infix[i] == '#') {
		
			infix[i] = '\0';

			break;

		}

		else {

			if (infix[i] >= '0' && infix[i] <= '9') {

				postfix[cnt++] = infix[i];

			}

			else {

				if (infix[i] == ')') {

					do {

						postfix[cnt++] = Pop(S, fp_out);

					} while (postfix[cnt - 1] != '(');

					cnt--;

					continue;

				}

				while (InStackPriority(S->Array[S->TopOfStack].oper) >= GetPriority(infix[i]))

				{

					postfix[cnt++] = Pop(S, fp_out);

				}

				ElementType X;

				X.oper = infix[i];

				Push(X, S, fp_out);

			}

		}

	}

	do {

		postfix[cnt++] = Pop(S, fp_out);

	} while (S->TopOfStack != -1);

	fprintf(fp_out, "Infix Form : %s\n", infix);

	fprintf(fp_out, "Postfix Form : %s\n", postfix);

	fprintf(fp_out, "Evaluation Result : %d\n", Calculate(&postfix[0]));

	fclose(fp);

	fclose(fp_out);

	free(S->Array);

	free(S);

	return 0;

}

 

 

 

Stack CreateStack(FILE* fp) {

	Stack S;

	S = (Stack)malloc(sizeof(struct StackRecord));  

	if (S == NULL)        

		fprintf(fp,"Out of space!!!\n");

	S->Array = (ElementType*)malloc(sizeof(ElementType) * 100);    

	if (S->Array == NULL)        

		fprintf(fp,"Out of space!!!");

	S->Capacity = 100;    

	S->TopOfStack = EmptyTos;

	return S;

}

 

 

void Push(ElementType X, Stack S, FILE* fp) {

	if (S->TopOfStack == EmptyTos - 1) {

		fprintf(fp, "Full\n");

	}

	else

		S->Array[++S->TopOfStack] = X;

}

 

char Pop(Stack S, FILE* fp) {

	if (S->TopOfStack == -1)

		fprintf(fp, "Empty\n");

	else

		S->TopOfStack--;

	return S->Array[S->TopOfStack + 1].oper;

}

 

int InStackPriority(char oper) {

	switch (oper)

	{

	case '(' :

		return 0;

	case ')':

		return 3;

	case '*':

	case '/':

	case '%':

		return 2;

	case '+':

	case '-':

		return 1;

	}

}

 

int GetPriority(char oper) {

	switch (oper) {

	case '(':

	case ')':

		return 3;

	case '*':

	case '/':

	case '%':

		return 2;

	case '+':

	case '-':

		return 1;

 

	}

}

 

int atoi_(char *str) {

	int tmp = 0;

	while (*str) {

		tmp = tmp * 10 + (int)(*str - 48);

		str++;

	}

}

 

int Calculate(char* postfix) {

	char  operand1, operand2;

	int arr[100];

	int cnt = 0;

	char tmp[10];

	for (int i = 0; i<strlen(postfix); i++) {

		if (postfix[i] >= '0' && postfix[i] <= '9') {

			arr[cnt++] = (int)(postfix[i] - 48);

		}

		else {

			operand1 = arr[cnt - 2];

			operand2 = arr[cnt - 1];

			switch (postfix[i]) {

			case '+':

				operand1 = operand1 + operand2;

				arr[--cnt] = 0;

				arr[cnt - 1] = operand1;

				break;

			case '-':

				operand1 = operand1 - operand2;

				arr[--cnt] = 0;

				arr[cnt - 1] = operand1;

				break;

			case '*':

				operand1 = operand1 * operand2;

				arr[--cnt] = 0;

				arr[cnt - 1] = operand1;

				break;

			case '/':

				operand1 = operand1 / operand2;

				arr[--cnt] = 0;

				arr[cnt - 1] = operand1;

				break;

			case '%':

				operand1 = operand1 % operand2;

				arr[--cnt] = 0;

				arr[cnt - 1] = operand1;

				break;

			}

		}

	}

	return arr[0];

}

