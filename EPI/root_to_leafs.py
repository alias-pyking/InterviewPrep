def sum_root_to_leafs(tree, partial_path_sum = 0):
    if not tree:
        return 0
    partial_path_sum = partial_path_sum *2 + tree.data
    if not tree.left and not tree.right:
        return partial_path_sum
    return sum_root_to_leafs(tree.left, partial_path_sum) + sum_root_to_leafs(tree.right, partial_path_sum)

class Node:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

root = Node(1)
t1 = root.left = Node(0)
t2 = root.right = Node(1)
t3 = t1.left = Node(0)
t4 = t1.right = Node(1)
t5 = t3.left = Node(0)
t6 = t3.right = Node(1)
t7 = t4.right = Node(1)
t8 = t7.left = Node(0)

t9 = t2.left = Node(0)
t10 = t2.right = Node(0)
t11 = t9.right = Node(0)
t12 = t11.left = Node(1)
t13 = t11.right = Node(0)
t14 = t12.right = Node(1)

t15 = t10.right =  Node(0)
t16 = t15.right = Node(0)
print(sum_root_to_leafs(root))
