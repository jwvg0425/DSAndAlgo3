def fibonacci(n):
    if n < 2:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

def fibonacci_memo(n, memo):
    if memo[n] != -1:
        return memo[n]
    if n < 2:
        memo[n] = n
    else:
        memo[n] = fibonacci_memo(n-1,memo) + fibonacci_memo(n-2,memo)
    
    return memo[n]

def fibonacci_iter(n):
    arr = []
    
    for i in range(0,n+1):
        if i < 2:
            arr.append(i)
        else:
            arr.append(arr[i-1] + arr[i-2])
    
    return arr[n]