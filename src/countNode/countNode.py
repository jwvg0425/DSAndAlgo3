import random

class Node:
    def __init__(self):
        self.data = 0
        self.left = None
        self.right = None

def count(node):
    if node is None:
        return 0
    return count(node.left) + count(node.right) + 1