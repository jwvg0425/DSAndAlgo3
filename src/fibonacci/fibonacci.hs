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
          
test :: Either String Bool
test
    | fibonacci 0 /= 0 = Left $ "f(0) = 0. but fibonacci 0 = " ++ (show $ fibonacci 0)
    | fibonacci_memo 0 /= 0 = Left $ "f(0) = 0. but fibonacci_memo 0 = " ++ (show $ fibonacci_memo 0)
    | fibonacci 5 /= 5 = Left $ "f(5) = 5. but fibonacci 5 = " ++ (show $ fibonacci 5)
    | fibonacci_memo 5 /= 5 = Left $ "f(5) = 5. but fibonacci_memo 5 = " ++ (show $ fibonacci_memo 5)
    | fibonacci 10 /= 55 = Left $ "f(10) = 55. but fibonacci 10 =" ++ (show $ fibonacci 10)
    | fibonacci_memo 10 /= 55 = Left $ "f(10) = 55. but fibonacci_memo 10 = " ++ (show $ fibonacci_memo 10)
    | otherwise = Right True