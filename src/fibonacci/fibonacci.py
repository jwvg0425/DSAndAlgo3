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

# test
def test():
    # f(0) = 0
    value = fibonacci(0)
    if value != 0:
        print("f(0) = 0. but fibonacci(0) = " + str(value))
        return False
    
    value = fibonacci_memo(0, [-1])
    if value != 0:
        print("f(0) = 0. but fibonacci_memo(0) = " + str(value))
        return False
    
    value = fibonacci_iter(0)
    if value != 0:
        print("f(0) = 0. but fibonacci_iter(0) = " + str(value))
        return False
    
    # f(5) = 5
    value = fibonacci(5)
    if value != 5:
        print("f(5) = 5. but fibonacci(5) = " + str(value))
        return False
    
    value = fibonacci_memo(5, [-1, -1, -1, -1, -1, -1])
    if value != 5:
        print("f(5) = 5. but fibonacci_memo(5) = " + str(value))
        return False
    
    value = fibonacci_iter(5)
    if value != 5:
        print("f(5) = 5. but fibonacci_iter(5) = " + str(value))
        return False
    
    # f(10) = 55
    value = fibonacci(10)
    if value != 55:
        print("f(10) = 55. but fibonacci(10) = " + str(value))
        return False
    
    value = fibonacci_memo(10, [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1])
    if value != 55:
        print("f(10) = 55. but fibonacci_memo(55) = " + str(value))
        return False
    
    value = fibonacci_iter(10)
    if value != 55:
        print("f(10) = 55. but fibonacci_iter(10) = " + str(value))
        return False
    
    print("ok.")
    return True