#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>

void AddConstToMatrix(int** x, int n, int m, int c)
{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				x[i][j] = c + x[i][j];
}

int main()
{
	int n = 800;
	int m = 800;
	int **x;
	x = new int *[n];
	for (int i = 0; i < n; i++) {
		x[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			x[i][j] = i;
		}
	}

	for (int k = 0; k < 30000; k++)
		AddConstToMatrix(x, n, m, 2);

	for (int i = 0; i < n; i++) {
		delete[] x[i];
	}
	delete[] x;

	return 0;
}