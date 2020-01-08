class Queue {
	public static class Node {
		int data;
		Node next;

		Node(int data) {
			this.data = data;
		}
	}

	Node head;
	Node tail;

	public int peek() {
		return head.data;	
	}

	public void add(int data) {
		Node node = new Node(data);
		if (tail != null) {
			tail.next = node;
		}
		tail = node;
		if (head == null) {
			head = node;
		}
	}

	public int remove() {
		int data = head.data;
		head = head.next;
		if (head == null) {
			tail = null;
		}
		return data;
	}
}

class Main {
	public static void main(String[] args) {
		Queue queue = new Queue();
		queue.add(90);
		queue.add(100);
		queue.add(12);
		System.out.println(queue.peek());
		System.out.println(queue.remove());
		System.out.println(queue.peek());
		
	}
}