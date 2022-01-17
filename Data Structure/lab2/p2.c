#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

typedef struct Node* PtrToNode;

typedef PtrToNode List; 

typedef PtrToNode Position;

typedef struct Student

{

	int studentID;

	char studentName[100];

} ElementType;

 

struct Node

{

	ElementType element;

	PtrToNode next;

};

 

void printcurrent(List L, FILE* fp);

void Insert(ElementType X, List L, Position P, FILE* fp);

Position findprevious(ElementType X, List L);

int islast(Position P, List L);

Position Find(ElementType X, List L);

void Delete(ElementType X, List L, FILE* fp);

void PrintList(List L, FILE* fp);

Position findposition(ElementType X, List L);

void deletelist(List L);

 

int main() {

	FILE* fp;

	FILE* fp_out;

	fp = fopen("input.txt", "r");

	fp_out = fopen("output.txt", "w+");

	List li;

	li = (List)malloc(sizeof(struct Node));

	li->next = NULL;

	while (1) {		

		char menu;

		fscanf(fp, "%c", &menu);

		if(menu=='i') {

			ElementType st;

			fscanf(fp, "%d", &st.studentID);

			fgets(st.studentName, 100, fp);

			for (int i = 1; i <= strlen(st.studentName); i++) {

				st.studentName[i-1] = st.studentName[i];

			}

			st.studentName[strlen(st.studentName) - 2] = '\0';

			Insert(st, li, findposition(st,li), fp_out);

		}

		else if (menu == 'd') {

			ElementType st;

			fscanf(fp,"%d", &st.studentID);

			Delete(st,li, fp_out);

		}

		else if (menu == 'f') {

			ElementType st;

			fscanf(fp, "%d", &st.studentID);

			Position P = Find(st, li);

			if (P)

				fprintf(fp_out, "Find Success : %d %s\n", P->element.studentID, P->element.studentName);

			else

				fprintf(fp_out, "Find %d Failed. There is no student ID\n", st.studentID);

		}

		else if (menu == 'p') {

			PrintList(li, fp_out);

			break;

		}

	}

	deletelist(li);

	free(li);

	fclose(fp);

	fclose(fp_out);

	return 0;

}

 

void printcurrent(List L, FILE* fp) {

	Position current;

	current= L->next;

	fprintf(fp,"Current List > ");

	while (current != NULL) {

		fprintf(fp,"%d %s", current->element.studentID, current->element.studentName);

		if (current->next != NULL)

			fprintf(fp,"-");

		current = current->next;

	}

	fprintf(fp ,"\n");

}

 

 

void Insert(ElementType X, List L, Position P, FILE* fp) {

	if (Find(X, L)) {

		fprintf(fp,"Insertion Failed. ID %d already exists.\n", X.studentID);

	}

	else {

		Position TmpCell;

		TmpCell = (List)malloc(sizeof(struct Node));
		
		if(TmpCell == NULL)

			fprintf(fp,"Out of space!!");

		TmpCell->element = X;

		TmpCell->next = P->next;

		P->next = TmpCell;

		fprintf(fp,"Insertion Success : %d\n", TmpCell->element.studentID);

		printcurrent(L, fp);

	}

}

 

Position findprevious(ElementType X, List L) {

	Position P;

	P = L;

	while (P->next != NULL && P->next->element.studentID != X.studentID)

		P = P->next;

	return P;

}

 

int islast(Position P, List L) {

	return P->next == NULL;

}

 

Position Find(ElementType X, List L) {

	Position P;

	P = L->next;

	while (P != NULL && P->element.studentID != X.studentID)

		P = P->next;

	return P;

}

 

void Delete(ElementType X, List L, FILE* fp) {

	Position P, TmpCell;

	if (Find(X, L)) {

		P = findprevious(X, L);

		if (!islast(P, L)) {

			TmpCell = P->next;

			P->next = TmpCell->next;

			fprintf(fp,"Deletion Success : %d\n", TmpCell->element.studentID);

			free(TmpCell);

			printcurrent(L, fp);

		}

	}

	else

		fprintf(fp, "Deletion Failed : Student ID %d is not in the list.\n", X.studentID);

}

 

 

void PrintList(List L, FILE* fp) {

	fprintf(fp,"-------LIST-------\n");

	while (L->next != NULL) {

		L = L->next;

		fprintf(fp,"%d %s\n", L->element.studentID, L->element.studentName);

	}

	fprintf(fp, "------------------\n\n");

}

 

Position findposition(ElementType X, List L) {

	Position P;

	P = L;

	while (P->next != NULL && X.studentID > P->next->element.studentID) {

		P = P->next;

	}

	return P;

}

 

void deletelist(List L) {

	Position P, TmpCell;

	P = L->next;

	L->next = NULL;

	while (P != NULL) {

		TmpCell = P->next;

		free(P);

		P = TmpCell;

	}

}
