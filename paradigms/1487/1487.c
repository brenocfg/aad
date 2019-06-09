/*-------------------------- URI Problem 1487 -------------------------------
------ URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1487   -
------ Author: Breno Campos Ferreira Guimarães                              -
------ Description: This is essentially the Unbounded Knapsack Problem. We  -
------ have N items each with an associated cost and value, but we can      -
------ can take the same item as many times as we want. We can solve it     -
------ easily with a one-dimensional dynamic programming array. Each        -
------ position i in the array holds the maximum value we can achieve by    -
------ considering all items and a knapsack of capacity i.                  -
---------------------------------------------------------------------------*/


#include <stdio.h>
#include <string.h>

/*returns maximum of two numbers*/
int max(int a, int b) {
	if (a > b) {
		return a;
	}

	return b;
}

int main() {
	int dp[601];
	int weight[601], value[601];
	int numItems, sizeKnap, v, w, inst = 0;

	while(1) {
		fscanf(stdin, "%d %d\n", &numItems, &sizeKnap);

		if (numItems == 0) {
			break;
		}

		/*fill cost and value arrays*/
		int i, j;
		for (i = 0; i < numItems; i++) {
			fscanf(stdin, "%d %d\n", &w, &v);
			weight[i] = w;
			value[i] = v;
		}

		/*reset dynamic programming array*/
		memset(dp, 0, sizeof(dp));

		for (i = 0; i <= sizeKnap; i++) {
			for (j = 0; j < numItems; j++) {
				/*if an item fits in the knapsack*/
				if (weight[j] <= i) {
					/*new value either takes current item or not*/
					dp[i] = max(dp[i], dp[i-weight[j]] + value[j]);
				}
			}
		}

		fprintf(stdout, "Instancia %d\n%d\n\n", ++inst, dp[sizeKnap]);
	}
}
