
def reconstruct_from_preorder_inorder(inorder, preorder):
    node_to_inorder_idx = {data:i for i,data in enumerate(inorder)}

    def reconstruct_helper(preorder_start, preorder_end, inorder_start, inorder_end):
        if preorder_end <= preorder_start or inorder_end <= inorder_start:
            return None
        root_inorder_idx = node_to_inorder_idx[preorder[preorder_start]]
        left_subtree_size = root_inorder_idx - inorder_start
        return BinaryTreeNode(preorder[preorder_start],\
            reconstruct_helper(preorder_start + 1,preorder_start + 1 + left_subtree_size,inorder_start,root_inorder_idx),
            reconstruct_helper(left_subtree_size + 1 + preorder_start, preorder_end, root_inorder_idx + 1, inorder_end))
    
    return reconstruct_helper(0, len(preorder), 0, len(inorder))

class BinaryTreeNode:
    def __init__(self,data, left = None, right = None):
        self.data = data
        self.left,self.right = left,right


def inorder_iter(root):
    s, res = [],[] 
    while s or root:
        if root:
            s.append(root)
            root = root.left
        else:
            root = s.pop()
            res.append(root.data)
            root = root.right
    return res
if __name__ == "__main__":
    inorder = ['D','C','E','B','F','H','G','A','J','L','M','K','N','I','O','P']
    preorder = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P']
    tree = reconstruct_from_preorder_inorder(inorder,preorder)
    print(inorder_iter(tree))
