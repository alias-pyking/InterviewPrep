class Node(object):
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = None


class SinglyLinkedList(object):
    def __init__(self, head=None, tail = None):
        self.head = head
        self.tail = tail

    def insert(self, data):
        node = Node(data)
        if self.head == None:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            self.tail = node
    # Reverses the linked List
    def reverse(self):
        prev = None
        current = self.head
        while current is not None:
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev
    # Make cycle of linked list
    def make_cycle(self):
        self.tail.next = self.head

    def printList(self):
        L = self.head
        while L.next != None:
            if L.next == self.head:
                break
            print(L.data)
            L = L.next
        print(L.data)
        

