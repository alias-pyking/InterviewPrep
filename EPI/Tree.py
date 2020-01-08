import collections
class Node(object):
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None


class BinaryTree(object):
    def __init__(self, root):
        self.root = Node(root)

result_pre = []
def _preorder(root):
    if root:
        result_pre.append(root.data)
        preorder(root.left)
        preorder(root.right)

result_in = []
def _inorder(root):
    if root:
        inorder(root.left)
        result_in.append(root.data)
        inorder(root.right)




def level_order(root):
    queue = collections.deque()
    queue.append(root)
    while len(queue) > 0:
        print(queue[0].data)
        node = queue.popleft()
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
def reverse_level_order(root):
    queue = collections.deque()
    stack = []
    queue.append(root)
    while  len(queue) > 0:
        stack.append(queue[0])
        node = queue.popleft()
        if node.right:
            queue.append(node.right)
        if node.left:
            queue.append(node.left)
    while stack:
        print(stack.pop().data)
tree = BinaryTree('A')
tree.root.left = Node('B')
tree.root.right = Node('D')
tree.root.left.left = Node('E')
tree.root.left.left.left = Node('M')
tree.root.left.left.right = Node('N')
tree.root.left.right = Node('F')
tree.root.right.right = Node('G')
tree.root.right.right.right = Node('L')
tree.root.right.right.right.left = Node('MN')
tree.root.right.right.right.left.right = Node('MNO')
tree.root.right.left = Node('H')
def calculate_height(root):
    if root == None:
        return -1
    left_height = 1 + calculate_height(root.left)
    right_height = 1 + calculate_height(root.right)
    return max(left_height, right_height)

def height_balanced(root):
    if root is None:
        return True
    left_height = calculate_height(root.left)
    right_height = calculate_height(root.right)
    if abs(left_height - right_height) <= 1:
        return True
    return False
def check_symetric(tree):
    def check_subtree(sub0, sub1):
        if not sub0 and not sub1:
            return True
        elif sub0 and sub1:
            return (sub0.data == sub1.data and check_subtree(sub0.left, sub0.right)\
            and check_subtree(sub1.left, sub1.right))
        return False
    if tree.root == None:
        return True
    if check_subtree(tree.root.left, tree.root.right):
        return True
    return False

def lca(root, node0, node1):
    if root == None:
        return None
    if root.data == node0 or root.data == node1:
        return root
    left = lca(root.left, node0, node1)
    right = lca(root.right, node0, node1)
    if left != None and right != None: return root
    if left == None and right == None: return None

    if left:
        return left
    return right
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

def pre_order_iter(root):
    path, result = [root], []
    while path:
        curr = path.pop()
        if curr:
            res.append(curr.data)
            path +=[curr.right, curr.left]

    return res

def sum_to_leaf(root, p_sum = 0):
    if not root:
        return 0
    p_sum += 2 * p_sum + root.data
    if not root.left and not root.right:
        return p_sum
    return (sum_to_leaf(root.left, p_sum) + sum_to_leaf(root.right, p_sum))

def root_to_leaf(root, sum):
    if not root:
        return False
    if not root.left and root.right:
        return sum == root.data
    return root_to_leaf(root.left, sum - root.data) or root_to_leaf(root.right, sum - root.data)

def  find_kth_node(root,k):
    while root:
        left_size = root.left.size if root.left else 0
        if left_size + 1 < k:
            root = root.right
        elif left_size == k - 1:
            return root
        else:
            root = root.left
    return None

def find_successor(node):
    if node.right:
        node = node.right
        while node.left:
            node = node.left
        return node
    while node.parent and node.parent.right is node:
        node = node.parent
    return node.parent
    

#       A
#     B      D    inorder(root.left)

#   E  F  H    G
# M   N           L
#               MN
#                   MNO

def buildTree(inOrder, preOrder, inStrt, inEnd, node_to_idx):
    if inStrt > inEnd:
        return None
    tNode = Node(preOrder[buildTree.preIndex])
    buildTree.preIndex +=1
    if inStrt == inEnd:
        return tNode

    idx = node_to_idx[tNode.data]
    tNode.left = buildTree(inOrder,preOrder,inStrt,idx - 1,node_to_idx)
    tNode.right = buildTree(inOrder, preOrder,idx + 1, inEnd,node_to_idx)
    return tNode


inorder = ['F','B','A','E','H','C','D','I','G']
preorder = ['H','B','F','E','A','C','D','G','I']
node_to_idx = {data:i for i,data in enumerate(inorder)}
buildTree.preIndex = 0
a = buildTree(inorder,preorder,0,8,node_to_idx)
print(inorder_iter(a))
