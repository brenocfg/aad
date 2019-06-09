/*-------------------------- URI Problem 2664 -------------------------------   
------ URL: https://www.urionlinejudge.com.br/judge/en/problems/view/2664   -
------ Author: Breno Campos Ferreira Guimarães                              -   
------ Description: The problem consists in "simulating" workout routines,  -
------ where a difficulty level must go up and down. We essentially need to -
------ count how many sequences of different levels can exist within a		-
------ a given interval of time, and a limit of difficulty levels.          -
------ Brute-force would lead to an exponential number of sequences.        -
------ However, there's lots of overlaps between them, so we use a dynamic  -
------ programming matrix to not recompute sequences. Basically, given a    -
------ current level and level limit, the number of occurrences of this     -
------ sequence is the number of occurrences of the two option "prefixes"   -
------ (increasing or decreasing level in the previous timeframe).          - 
---------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

static int mat[51][100001];

long long int fill(int size, int time, int curr) {
	if (time == 0) {
		if (curr > -1 && curr <= size) {
			return 1;
		}
		else {
			return 0;
		}
	}

	if (curr < 0 || curr > size) {
		return 0;
	}

	if (mat[time][curr] != -1) {
		return mat[time][curr];
	}

	mat[time][curr] = (fill(size, time - 1, curr - 1) % 1000000007L);
	mat[time][curr] += (fill(size, time - 1, curr + 1) % 1000000007L);

	return mat[time][curr];
}

int main() {
	int t, m, n;

	fscanf(stdin, "%d %d %d", &t, &m, &n);

	int size = n - m;

	int i;
	memset(mat, -1, sizeof(mat));

	for (i = 0; i <= size; i++) {
		fill(size, t - 1, i);
	}

	long long int ans = 0;
	for (i = 0; i <= size; i++) {
		ans += mat[t-1][i];
		ans %= 1000000007L;
	}
		
	fprintf(stdout, "%lli\n", ans);

	return 0;
}
