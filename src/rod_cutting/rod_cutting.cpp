#include <stdio.h>

int rod_cutting(int n, int* product, int* length)
{
	if (n == 0)
	{
		return 0;
	}

	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		int value = product[i] + rod_cutting(n - i, product);

		if (value > res)
		{
			res = value;
			length[n] = i;
		}
	}
	
	return res;
}

int rod_cutting_memo(int n, int* product, int* memo, int* length)
{
	if (memo[n] != -1)
		return memo[n];

	if (n == 0)
		memo[n] = 0;

	for (int i = 1; i <= n; i++)
	{
		int value = product[i] + rod_cutting_memo(n - i, product, memo);

		if (value > memo[n])
		{
			memo[n] = value;
			length[n] = i;
		}
	}

	return memo[n];
}

int rod_cutting_iter(int n, int* product, int* length)
{
	int* arr = new int[n + 1];

	arr[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = 0;
		for (int j = 1; j <= i; j++)
		{
			int value = product[j] + arr[i - j];

			if (value > arr[i])
			{
				arr[i] = value;
				length[i] = j;
			}
		}
	}

	int res = arr[n];

	delete[] arr;

	return res;
}

void printLength(int n, int* length)
{
	while (n > 0)
	{
		printf("%d ", length[n]);
		n = n - length[n];
	}

	printf("\n");
}