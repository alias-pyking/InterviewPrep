import collections 

def LCA(tree, node0, node1):
    def lca_hleper(tree, node0, node1):
        if not tree:
            return None
        if tree is node0 or tree is node1:
            return tree
        left_lca = lca_hleper(tree.left, node0, node1)
        right_lca = lca_hleper(tree.right, node0,node1)
        if left_lca and right_lca:
            return tree
        return left_lca if left_lca else right_lca
    return lca_hleper(tree, node0, node1)

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

print(LCA(root,t4, t5).data)

        