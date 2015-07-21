rod_cutting :: [Int] -> Int -> Int
rod_cutting price n = if n == 0 then 0 else foldl max 0 [(price !! x) + rod_cutting price (n-x) | x <- [1..n]]

rod_cutting_memo :: Int -> [Int] -> Int
rod_cutting_memo n price = memo !! n
    where memo = map f [0..]
          f k = if k == 0 then 0 else foldl max 0 [(price !! x) + (memo !! (k-x)) | x <- [1..k]]