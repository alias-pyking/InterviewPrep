def has_path(tree, rem_weight):
    if not tree:
        return False
    if not tree.left and not tree.right:
        return rem_weight - tree.data == 0
    return has_path(tree.left, rem_weight - tree.data) or has_path(tree.right, rem_weight - tree.data)


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
t6.right = Node(1)
print(has_path(root,323))

