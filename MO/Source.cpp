#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>

void MultiplayMatrixToConst(int** x, int n, int m, int c)
{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				x[i][j] = c * x[i][j];
}

void MultiplayMatrixToConstB(int** x, int n, int m, int c)
{
	for (int ii = 0; ii < n; ii += 8)
		for (int jj = 0; jj < m; jj += 8)
			for (int i = ii; i < ii + 8; i++)
				for (int j = jj; j < jj + 8; j++)
					x[i][j] = c * x[i][j];
}

int main()
{
	int n = 12000;
	int m = 12000;
	int **x;
	x = new int *[n];
	for (int i = 0; i < n; i++) {
		x[i] = new int[m];
	}

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			x[i][j] = rand();
		}
	}

	for (int k = 0; k < 100; k++)
		MultiplayMatrixToConst(x, n, m, 2);

	for (int i = 0; i < n; i++) {
		delete[] x[i];
	}
	delete[] x;

	return 0;
}