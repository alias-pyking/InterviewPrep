"""
This function populates the next field of every node of a perfect binary tree with its right sibling if
any 
"""

def construct_right_sibling(tree):
    def populate_child_next_field(start_node):
        while start_node and start_node.left:
            start_node.left.next = start_node.right
            start_node.right.next = start_node.next and start_node.next.left
            start_node = start_node.next
    
    while tree and tree.left:
        populate_child_next_field(tree)
        tree = tree.left