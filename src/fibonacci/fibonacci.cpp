

unsigned int fibonacci(unsigned int n)
{
	if (n < 2)
		return n;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacci_memo(unsigned int n, int* memo)
{
	if (memo[n] != -1)
		return memo[n];

	if (n < 2)
		memo[n] = n;
	else
		memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo);

	return memo[n];
}

int fibonacci_iter(unsigned int n)
{
	int* arr = new int[n + 1];

	for (int i = 0; i <= n; i++)
	{
		if (i < 2)
			arr[i] = i;
		else
			arr[i] = arr[i - 1] + arr[i - 2];
	}
	
	int res = arr[n];
	delete[] arr;

	return res;
}