# This function assumes that every node contain the no. of nodes 
# in the subtree rooted at that node
def find_kth_node(tree,k):
    while tree:
        left_size = tree.left.size if tree.left else 0
        if left_size + 1 < k: # node must be in the right subtree
            k -= left_size + 1
            tree = tree.right
        if left_size == k - 1: # iter the node itself
            return tree
        else: # node is in the left subtree
            tree = tree.left
    return None

