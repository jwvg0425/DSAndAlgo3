import Data.List

data Node = Node { value :: Int, adj :: [Node] } deriving Eq

instance Show Node where
    show node = show $ value node

-- source node의 집합
type Graph = [Node]

dfs :: Graph -> [Node]
dfs graph = concat [dfs_node x [] | x <-graph]
    where dfs_node source visited = source:(concat [dfs_node a (source:visited) | a <- adj source, a `notElem` visited])