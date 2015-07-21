import Data.List

data Node = Node { value :: Int, adj :: [Node] } deriving Eq

instance Show Node where
    show node = show $ value node

-- source node의 집합
type Graph = [Node]

topological_sort :: Graph -> [Node]
topological_sort graph = reverse . concat $ [topological_sort_node x [] | x <-graph]
    where topological_sort_node source visited = (concat [topological_sort_node a (source:visited) | a <- adj source, a `notElem` visited]) ++ [source]