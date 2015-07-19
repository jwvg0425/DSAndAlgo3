class Node:
    def __init__(self, value, adj):
        self.value = value
        self.adj = adj
        self.visited = False

def dfs(graph):
    for source in graph:
        source.visited = True
        dfs_node(source)

def dfs_node(node):
    print(node.value)
    for e in node.adj:
        if not e.visited:
            e.visited = True
            dfs_node(e)