/*-------------------------- URI Problem 1310 -------------------------------   
------ URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1310   -
------ Author: Breno Campos Ferreira Guimarães                              -   
------ Description: This problem essentially boils down to the maximum value-
------ subarray problem. We simply substract the daily cost from each day,  -
------ then find the maximum subarray value in this new array. This is known-
------ as Kadane's algorithm.                                               - 
---------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
	int nums[50];
	int cost, n;

	while(fscanf(stdin, "%d\n", &n) == 1) {
		fscanf(stdin, "%d\n", &cost);

		int i;
		for (i = 0; i < n; i++) {
			fscanf(stdin, "%d\n", &nums[i]);
			nums[i] -= cost;
		}

		for (i = 1; i < n; i++) {
			if (nums[i - 1] > 0) {
				nums[i] += nums[i-1];
			}
		}

		int max = 0;
		for (i = 0; i < n; i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
		}

		fprintf(stdout, "%d\n", max);
	}
}

