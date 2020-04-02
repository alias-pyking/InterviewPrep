def find_successor(node):
    if node.right:
        node = node.right
        while node.left:
            node = node.left
        return node
    elif node.parent and node.parent.left is node:
        return node.parent
    else:
        while node.parent and node.parent.left is not node:
            node = node.parent
        return node.parent
    return None
class Node:
    def __init__(self,data):
        self.data = data
        self.parent = None
        self.left = None
        self.right = None

if __name__ == "__main__":
    t1 = tree = Node(314)
    t2 = t1.left = Node(6)
    t2.parent = t1
    t3 = t1.right = Node(6)
    t3.parent = t1

    t4 = t2.left = Node(271)
    t5 = t2.right = Node(561)
    t4.parent = t2
    t5.parent = t2

    t6 = t3.left = Node(2)
    t7 = t3.right = Node(271)
    t6.parent = t3
    t7.parent = t3
    t8 = t6.right = Node(1)
    t8.parent = t6


print(find_successor(t4).data)
