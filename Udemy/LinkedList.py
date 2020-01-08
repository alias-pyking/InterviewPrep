class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None
class LinkedList:
    def __init__(self):
        self.head=None
        self.prev=None
    def insert(self,data):
        newNode=Node(data)
        if self.head is None:
            self.head=newNode
        else:
            node=self.head
            while node.next is not None:
                node=node.next
            node.next=newNode
    def show(self):
        node=self.head
        while node.next is not None:
            print(node.data)
            node=node.next
        print(node.data)
    def delete(self,data):
        if self.head is None:
            print("Linked List is Empty")
            return
        node=self.head
        parenrNode=None
        while node.next is not None:
            if node.data is data:
                parenrNode.next=node.next
                return
            parenrNode=node
            node=node.next
        if node.data is data:
            parenrNode.next=None
            return
        print("Item is not present in the Linked List")
        return
    def insertAtStart(self,data):
        node=Node(data)
        node.next=self.head
        self.head=node

        


        


link=LinkedList()
link.insert(90)
link.insert(89)
link.insert(12)
link.insert(888)
link.insert(55)
link.insert(45)
link.insertAtStart(9999)
link.show()

