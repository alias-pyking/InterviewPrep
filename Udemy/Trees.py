class binaryNode:
    def __init__(self,value):
        self.value=value
        self.left=None
        self.right=None
class BinarySearchTree:
    def __init__(self):
        self.root=None
    def insert(self,value):
        newNode=binaryNode(value)
        if self.root is None:
            self.root=newNode
        else:
            currentNode=self.root
            while True:
                if value<currentNode.value:
                    #left 
                    if currentNode.left is None:
                        currentNode.left=newNode
                        break
                    currentNode=currentNode.left
                else:
                    # right
                    if currentNode.right is None:
                        currentNode.right=newNode
                        break
                    currentNode=currentNode.right
    def lookup(self,value):
        if self.root is None:
            return False
        currentNode=self.root
        if value is currentNode.value:
            return currentNode
        while(currentNode is not None):
            if(value<currentNode.value):
                currentNode=currentNode.left
            elif(value>currentNode.value):
                currentNode=currentNode.right
            elif(currentNode.value is value):
                return currentNode
        return False
    def printInorder(self,node):
        if node:
            self.printInorder(node.left)
            print(node.value)
            self.printInorder(node.right)
    def InOrder(self):
        node=self.root
        self.printInorder(node)
    def printPostOrder(self,node):
        if node is not None:
            self.printPostOrder(node.left)
            self.printPostOrder(node.right)
            print(node.value)
    def PostOrder(self):
        node=self.root
        self.printPostOrder(node)
    def printPreOrder(self,node):
        if node is not None:
            print(node.value)
            self.printPreOrder(node.left)
            self.printPreOrder(node.right)
    def PreOrder(self):
        node=self.root
        self.printPreOrder(node)
    # def remove(self,value):
    #     if self.root is None:
    #         return False
    #     currentNode=self.root
    #     parentNode=None
    #     while(currentNode is not None):
    #         if value<currentNode.value:
    #             parentNode=currentNode
    #             currentNode=currentNode.left
    #         elif value>currentNode.value:
    #             parentNode=currentNode
    #             currentNode=currentNode.right
    #         elif value is currentNode.value:
    #             # option1 
    #             # if node we are deleting has no right child
    #             if currentNode.right is None:
    #                 # Means we are deleting root node which has
    #                 #  no right child
    #                 if parentNode is None:
    #                     self.root=currentNode.left
    #                 else:
    #                     # if parent > current value,make left
    #                     # child a right child of parent
    #                     if currentNode.value<parentNode.value:
    #                         parentNode.left=currentNode.left
    #                         # if parent node is less than current
    #                     if currentNode.value>parentNode.value:
    #                         parentNode.right=currentNode.left
    #             # option 2 Right child which doesnt have a
    #             # left child
    #             elif currentNode.right.left is None:
    #                 if parentNode is None:
    #                     self.root=currentNode.left
    #                 else:
    #                     currentNode.right.left=currentNode.left
    #                     # means current node is in right 
    #                     if currentNode.value<parentNode.value:
    #                         parentNode.left= currentNode.right
    #                     elif currentNode.value>parentNode.value:
    #                         parentNode.right=currentNode.right
    #             else:
    #                 # TODO: i did'nt uderstood this Very very tough concept very tough


tree=BinarySearchTree()
tree.insert(90)
tree.insert(10)
tree.insert(100)
tree.insert(12)
tree.insert(5)
tree.insert(15)
tree.insert(200)
tree.insert(110)
tree.insert(111)
tree.PostOrder()
