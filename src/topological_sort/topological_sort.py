class Node:
    def __init__(self, value, adj):
        self.value = value
        self.adj = adj
        self.visited = False

def topological_sort(graph):
    sort_list = []
    for source in graph:
        source.visited = True
        topological_sort_node(source, sort_list)
    return sort_list

def topological_sort_node(node, sort_list):
    for e in node.adj:
        if not e.visited:
            e.visited = True
            topological_sort_node(e)
    sort_list.insert(0, node.value)