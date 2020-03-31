def binary_tree_depth_order(tree):
    queue = [tree]
    result = list()
    while queue:
        result.append([node.data for node in queue])
        queue = [node for cur in queue for node in (cur.left, cur.right) if node]
    return result

class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

t1 = root = Node(314)
t2 = t1.left = Node(6)
t3 = t1.right = Node(6)

t4 = t2.left = Node(271)
t5 = t2.right = Node(561)

t6 = t3.left = Node(2)
t7 = t3.right = Node(271)
print(binary_tree_depth_order(root))




