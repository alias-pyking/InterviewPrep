from LinkedLists import SinglyLinkedList

def reverse_sublist(L, start, end):
    L = L.head
    s = 0
    start_node = None
    end_node = None
    for i in range(1,start):
        L = L.next
    sub_list = SinglyLinkedList()
    for i in range(end - start + 1):
        sub_list.insert(L.data)
        L = L.next
    sub_list.reverse()
    return sub_list

l = SinglyLinkedList()
l.insert(11)
l.insert(3)
l.insert(5)
l.insert(7)
l.insert(2)

s = reverse_sublist(l, 2, 4)
s.printList()
