def inorder_without_recursion(tree):
    s,result = [],[]
    while s or tree:
        if tree:
            s.append(tree)
            tree = tree.left
        else:
            tree = s.pop()
            result.append(tree.data)
            tree = tree.right
    return result

def preorder_without_recursion(tree):
    s, result = [],[]
    while s or tree:
        if tree:
            result.append(tree.data)
            s.append(tree)
            tree = tree.left
        else:
            tree = s.pop()
            tree = tree.right
    return result
class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

t1 = tree = Node(314)
t2 = t1.left = Node(6)
t3 = t1.right = Node(6)

t4 = t2.left = Node(271)
t5 = t2.right = Node(561)

t6 = t3.left = Node(2)
t7 = t3.right = Node(271)
t6.right = Node(1)

print(inorder_without_recursion(tree))
print(preorder_without_recursion(tree))

 