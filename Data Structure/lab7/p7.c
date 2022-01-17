#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

 

int Find(int X, int* S);

void Union(int* S, int r1, int r2);

 

int main() {

	FILE* fp;

	FILE* fp_out;

	fp = fopen("input.txt", "r");

	fp_out = fopen("output.txt", "w+");

	srand((unsigned int)time(NULL));

	int num, i, j, k, rnd_num;

	int S[101];

	for (i = 0; i < 101; i++) {

		S[i] = 0;

	}

	fscanf(fp, "%d", &num);

 

	int arr[10][10] = { 0 };

	for (i = 0; i < num; i++) {

		for (j = 0; j < num; j++) {

			arr[i][j] = i * num + j + 1;

		}

	}

 

	int S_edge[180][2] = { 0 };

	i = 0;

	while (i < num*(num - 1)) {

		for (j = 0; j < num; j++) {

			for (k = 0; k < num - 1; k++) {

				S_edge[i][0] = arr[j][k];

				S_edge[i][1] = arr[j][k + 1];

				i++;

			}

		}

	}

	i = num * (num - 1);

	while (i < num*(num - 1) * 2) {

		for (int j = 0; j < num - 1; j++) {

			for (int k = 0; k < num; k++) {

				S_edge[i][0] = arr[j][k];

				S_edge[i][1] = arr[j + 1][k];

				i++;

			}

		}

	}

 

	char** maze;

	maze = (char**)malloc(sizeof(char*)*num * 2 + 1);

	for (i = 0; i < num * 2 + 1; i++) {

		maze[i] = (char*)malloc(sizeof(char)*num * 2 + 1);

	}

	for (i = 0; i < num * 2 + 1; i++) {

		for (j = 0; j < num * 2 + 1; j++) {

			maze[i][j] = ' ';

		}

	}

 

	for (i = 0; i < num * 2 + 1; i++) {

		for (j = 0; j < num * 2 + 1; j++) {

			if (i % 2 == 0) {

				if (j % 2 == 0)

					maze[i][j] = '+';

				else

					maze[i][j] = '-';

			}

			else {

				if (j % 2 == 0)

					maze[i][j] = '|';

			}

		}

	}

	maze[1][0] = ' ';

	maze[2 * num - 1][2 * num] = ' ';

 

	while ((Find(1, &S[0]) != Find(num*num, &S[0])) || (S[1] == 0 && S[num*num] == 0)) {

		rnd_num = rand() % (num*(num - 1) * 2);

		int x, y;

		x = S_edge[rnd_num][0];

		y = S_edge[rnd_num][1];

		int x_x, x_y, y_x, y_y;

		if (x%num == 0) {

			x_x = 2 * (x / num - 1) + 1;

			x_y = 2 * num - 1;

		}

		else {

			x_x = 2 * (x / num) + 1;

			x_y = 2 * (x%num) - 1;

		}

		if (y%num == 0) {

			y_x = 2 * (y / num - 1) + 1;

			y_y = 2 * num - 1;

		}

		else {

			y_x = 2 * (y / num) + 1;

			y_y = 2 * (y%num) - 1;

		}

 		if (Find(x, &S[0]) != Find(y, &S[0])) {

			Union(&S[0], Find(x,&S[0]), Find(y,&S[0]));

			maze[(x_x + y_x) / 2][(x_y + y_y) / 2] = ' ';

		}

	}

 

	for (i = 0; i < 2 * num + 1; i++) {

		for (j = 0; j < 2 * num + 1; j++) {

				fprintf(fp_out, "%c", maze[i][j]);

		}

		fprintf(fp_out, "\n");

	}

	

	for (i = 0; i < 2 * num + 1; i++) {

		free(maze[i]);

	}

	free(maze);

	fclose(fp);

	fclose(fp_out);

	return 0;

}

 

 

int Find(int X, int* S) {

	while (S[X] > 0)

		X = S[X];

	return X;

}

 

void Union(int* S, int r1, int r2) {

	if (S[r2] < S[r1])

		S[r1] = r2;

	else {

		if (S[r2] == S[r1])

			S[r1]--;

		S[r2] = r1;

	}

}

