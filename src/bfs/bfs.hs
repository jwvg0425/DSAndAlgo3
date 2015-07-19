data Node = Node { value :: Int, adj :: [Node] } deriving Eq

instance Show Node where
    show node = show $ value node

-- source node의 집합
type Graph = [Node]

bfs :: Graph -> [Node]
bfs graph = [y | x <- graph, y <- bfs_node [x] [x] ]
    where bfs_node [] _ = []
          bfs_node queue visited = queue ++ bfs_node [y | x <- queue, y <- adj x, y `notElem` visited] (visited ++ queue)