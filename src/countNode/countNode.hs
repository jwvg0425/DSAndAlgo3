data Node = Node {value :: Int, left :: Maybe Node, right :: Maybe Node}

count :: Maybe Node -> Int
count Nothing = 0
count (Just node) = 1 + (count $ left node) + (count $ right node)