class Node:
        def __init__(self,data = 0, next_node = None):
            self.data = data
            self.next = next_node
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    def get_head(self):
        return self.head
    def get_tail(self):
        return self.tail
    def insert(self,data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
    def print_list(self):
        L = self.head
        while L and L.next != None:
            print(L.data)
            L = L.next
        print(L.data)
    def reverse(self):
        prev = None
        current = self.head
        while current is not None:
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev
    def reverse_sublist(self, start, finish):
        current = self.head
        prev = self.head
        for _ in range(start):
            current = current.next
        for _ in range(finish):
            prev = prev.next
        for _ in range(finish - start):
            next = current.next
            current.next = prev
            prev = current
            current = next
            
        



def merge_sorted_lists(L1, L2):
    result = LinkedList()
    while L1 and L2:
        if L1.data < L2.data:
            result.insert(L1.data)
            L1 = L1.next
        else:
            result.insert(L2.data)
            L2 = L2.next
    while L1:
        result.insert(L1.data)
        L1 = L1.next
    while L2:
        result.insert(L2.data)
        L2 = L2.next
    return result

def has_cycle(head):
    slow = fast = head
    while fast and fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
        if slow is fast:
            return True
    return False

def overlappig_no_cycle_list(L1, L2):
    while L1 and L2:
        if L1 is L2:
            return L1
        L1 = L1.next
        L2 = L2.next
    return None

def even_odd_merge(L):
    even, odd = Node(), Node()
    tails, turn = [even,odd], 0
    while L:
        tails[turn].next = L
        L = L.next
        tails[turn] = tails[turn].next
        turn ^= 1
    tails[1].next = None
    tails[0].next = odd.next
    return even.next
def pivot_list(L, pivot):
    less_head = less_iter = Node()
    equal_head = euqal_iter = Node()
    greater_head = greater_iter = Node()

    while L:
        if L.data < pivot:
            less_iter.next = L
            less_iter = less_iter.next
        elif L.data == pivot:
            euqal_iter.next = L
            euqal_iter = euqal_iter.next
        else:
            greater_iter.next = L
            greater_iter = greater_iter.next
        L = L.next
    greater_iter.next = None
    euqal_iter.next = greater_head.next
    less_iter.next = equal_head.next
    return less_head.next

def add_two_numbers(L1,L2):
    sum_iter = sum_head = Node()
    carry = 0
    while L1 or L2 or carry:
        val = carry + (L1.data if L1 else 0) + (L2.data if L2 else 0)
        L1 = L1.next if L1 else None
        L2 = L2.next if L2 else None
        sum_iter.next = Node(val%10)
        sum_iter = sum_iter.next
        carry = val // 10
    return sum_head.next

def print_list(head):
    while head:
        print(head.data)
        head = head.next


list1 = LinkedList()
list1.insert(1)
list1.insert(9)
list1.insert(20)
list1.insert(22)
list1.insert(232) # 4
list1.insert(10)
list1.insert(11)
list1.insert(25)
list1.insert(100) # 8
list1.insert(111)

head = list1.get_head()
pivot_list(head,100)
# list1.print_list()

L1 = Node(3)
t1 = L1.next = Node(1)
t2 = t1.next = Node(4)
L2 = Node(7)
t4 = L2.next = Node(0)
t5 = t4.next = Node(9)

# print_list(L1)
# print_list(L2)
L3 = add_two_numbers(L1,L2)
print_list(L3)

 



    

