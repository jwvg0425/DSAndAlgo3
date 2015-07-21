def rod_cutting(n, price, length):
    if n == 0:
        return 0
    value = 0
    for i in range(1, n + 1):
        newValue = price[i] + rod_cutting(n-i, price, length)
        if newValue > value:
            value = newValue
            length[n] = i
    
    return value

def rod_cutting_memo(n, price, memo, length):
    if memo[n] != -1:
        return memo[n]
    memo[n] = 0
    for i in range(1, n + 1):
        newValue = price[i] + rod_cutting_memo(n-i, price, memo, length)
        if newValue > memo[n]:
            memo[n] = newValue
            length[n] = i
    
    return memo[n]

def rod_cutting_iter(n, price, length):
    memo = [0]
    
    for i in range(1, n + 1):
        value = 0
        for j in range(1, i + 1):
            newValue = price[j] + memo[i-j]
            if newValue > value:
                value = newValue
                length[i] = j
        memo.append(value)
        
    return memo[n]

def printLength(n, length):
    while n > 0:
        print(length[n])
        n = n - length[n]