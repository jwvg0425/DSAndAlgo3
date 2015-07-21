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

bool test()
{
    int memo1[1] = {-1};
    int memo2[6] = {-1, -1, -1, -1, -1, -1};
    int memo3[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    
    if(fibonacci(0) != 0)
    {
        printf("f(0) = 0. but fibonacci(0) = %d\n", fibonacci(0));
        return false;
    }
    
    if(fibonacci_memo(0, memo1) != 0)
    {
        printf("f(0) = 0. but fibonacci_memo(0) = %d\n", fibonacci_memo(0, memo1));
        return false;
    }
    
    if(fibonacci_iter(0) != 0)
    {
        printf("f(0) = 0. but fibonacci_iter(0) = %d\n", fibonacci_iter(0));
        return false;
    }
    
    if(fibonacci(5) != 5)
    {
        printf("f(5) = 5. but fibonacci(5) = %d\n", fibonacci(5));
        return false;
    }
    
    if(fibonacci_memo(5, memo2) != 5)
    {
        printf("f(5) = 5. but fibonacci_memo(5) = %d\n", fibonacci_memo(5, memo2));
        return false;
    }
    
    if(fibonacci_iter(5) != 5)
    {
        printf("f(5) = 5. but fibonacci_iter(5) = %d\n", fibonacci_iter(5));
        return false;
    }
    
    if(fibonacci(10) != 55)
    {
        printf("f(10) = 55. but fibonacci(10) = %d\n", fibonacci(10));
        return false;
    }
    
    if(fibonacci_memo(10, memo3) != 55)
    {
        printf("f(10) = 55. but fibonacci_memo(10) = %d\n", fibonacci_memo(10, memo3));
        return false;
    }
    
    if(fibonacci_iter(10) != 55)
    {
        printf("f(10) = 55. but fibonacci_iter(10) = %d\n", fibonacci_iter(10));
        return false;
    }
    
    printf("Ok.\n");
    return true;
}