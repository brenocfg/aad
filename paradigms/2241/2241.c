/*-------------------------- URI Problem 2241 -------------------------------   
------ URL: https://www.urionlinejudge.com.br/judge/en/problems/view/2241   -
------ Author: Breno Campos Ferreira Guimarães                              -   
------ Description: We need to compute how many subsquares of a matrix only -
------ have pieces of one single type. To do this, we create two auxiliary  -
------ matrices, each counting how many pieces of each type are in the      -
------ subsquare composed of the entire matrix up to the square [x][y] in   -
------ the matrix. Then, for each subsquare in the board, we compute the    -
------ number of pieces of a type in constant time from the subsquare matrix-
---------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

int max (int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

//this is here for debugging only
void print_board (int n, int board[n][n]) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fprintf(stdout, "%d\t", board[i][j]);
		}
		fprintf(stdout, "\n");
	}

	fprintf(stdout, "\n\n");
}

int main() {
	int n, p;

	fscanf(stdin, "%d %d\n", &n, &p);

	int board[n][n];
	int blacks[n+1][n+1];
	int whites[n+1][n+1];
	memset(blacks, 0, sizeof(blacks));
	memset(whites, 0, sizeof(whites));
	memset(board, 0, sizeof(board));

	int i, j, x, y;
	for (i = 0; i < p; i++) {
		fscanf(stdin, "%d %d\n", &x, &y);
		board[x-1][y-1] = 1;
	}

	for (i = 0; i < p; i++) {
		fscanf(stdin, "%d %d\n", &x, &y);
		board[x-1][y-1] = 2;
	}

	for (j = 1; j < n+1; j++) {
		for (i = 1; i < n+1; i++) {
			if (board[i-1][j-1] == 1) {
				blacks[i][j]=blacks[i-1][j]+blacks[i][j-1]-blacks[i-1][j-1]+1;
			}
			else {
				blacks[i][j]=blacks[i-1][j]+blacks[i][j-1]-blacks[i-1][j-1];
			}

			if (board[i-1][j-1] == 2) {
				whites[i][j]=whites[i-1][j]+whites[i][j-1]-whites[i-1][j-1]+1;
			}
			else {
				whites[i][j]=whites[i-1][j]+whites[i][j-1]-whites[i-1][j-1];
			}
		}
	}

	int score_white = 0, score_black = 0;
	int k, l, numblacks, numwhites;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = i, l = j; k < n && l < n; k++, l++) {
				numblacks = blacks[k+1][l+1] - blacks[i][l+1] - blacks[k+1][j]
															 + blacks[i][j];
				numwhites = whites[k+1][l+1] - whites[i][l+1] - whites[k+1][j]
															+ whites[i][j];
				if (numwhites > 0 && numblacks == 0) {
					score_white++;
				}
				if (numblacks > 0 && numwhites == 0) {
					score_black++;
				}
			}
		}
	}

	fprintf(stdout, "%d %d\n", score_black, score_white);
}
