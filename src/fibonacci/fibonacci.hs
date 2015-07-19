-- recursion
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = (fibonacci (n-1)) + (fibonacci (n-2))

-- memoization
fibonacci_memo n = memo !! n
    where memo = map f [0..]
          f 0 = 0
          f 1 = 1
          f n = (memo !! (n-1)) + (memo !! (n-2))