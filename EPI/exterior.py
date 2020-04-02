def exterior_of_binary_tree(tree):
    def is_leaf(subtree):
        return not subtree.left and not subtree.right
    
    def left_boundary_and_leaves(subtree, is_boundary):
        if not subtree:
            return []
        return (([subtree] if is_boundary or is_leaf(subtree) else []) + \
            left_boundary_and_leaves(subtree.left, is_boundary) + \
            left_boundary_and_leaves(subtree.right, is_boundary and not subtree.left) )
    def right_boundary_and_leaves(subtree, is_boundary):
        if not subtree:
            return []
        return ([subtree] if is_leaf or is_leaf(subtree) else[]) +\
            right_boundary_and_leaves(subtree.left, is_boundary and not subtree.right) +\
            right_boundary_and_leaves(subtree.right, is_boundary)
    
    return [tree] + left_boundary_and_leaves(tree.left,is_boundary=True) + \
        right_boundary_and_leaves(tree.right,is_boundary=True) if tree else []

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
    exterior = exterior_of_binary_tree(tree)
    print([i.data for i in exterior])