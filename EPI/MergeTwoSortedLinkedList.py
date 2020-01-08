from LinkedLists import SinglyLinkedList

l1 = SinglyLinkedList()
l2 = SinglyLinkedList()
l1.insert(2)
l1.insert(5)
l1.insert(7)
l1.insert(19)
l1.insert(100)
l2.insert(3)
l2.insert(7)
l2.insert(14)

def merge(list1, list2):
    list1 = list1.head
    list2 = list2.head
    list3 = SinglyLinkedList()
    while list1 and list2:
        if list1.data < list2.data:
            list3.insert(list1.data)
            list1 = list1.next
        else:
            list3.insert(list2.data)
            list2 = list2.next

    while list1:
        list3.insert(list1.data)
        list1 = list1.next
        
    while list2:
        list3.insert(list2.data)
        list2 = list2.next
    return list3
l3 = merge(l1, l2)
l3.printList()

        


