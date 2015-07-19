import queue;

class Node:
    def __init__(self, value, adj):
        self.value = value
        self.adj = adj
        self.visited = False

        
def bfs(graph):
    q = queue.Queue()
    for source in graph:
        q.put(source)
        source.visited = True
        while q.qsize() != 0:
            top = q.get();
            print(top.value)
            
            for e in top.adj:
                if not e.visited:
                    e.visited = True
                    q.put(e)