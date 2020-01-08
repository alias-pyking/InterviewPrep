from LinkedLists import SinglyLinkedList
l = SinglyLinkedList()
l.insert(4)
l.insert(5)
l.insert(10)
l.insert(12)
l.insert(14)
l.make_cycle()
def test_cyclicity(lis):
    b = lis.head
    lis = lis.head
    while True:
        if lis.next == b:
            return b
        if lis.next == None:
            return None
        lis = lis.next

print(test_cyclicity(l).data)

        