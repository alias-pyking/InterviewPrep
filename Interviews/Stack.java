class Stack {
	public static class Node {
		int data;
		Node next;

		Node(int data) {
			this.data = data;
		}
	}

	Node head;

	public void add(int data) {
		Node node = new Node(data);
		if (head != null) {
			node.next = head;
		}
		head = node;
	}

	public boolean isEmpty() {
		return head == null;
	}
	public int peek() {
		return head.data;
	}

	public int pop() {
		int data = head.data;
		head = head.next;
		return data;
	}
}
class Main {
	public static void main(String[] args) {
		Stack stack = new Stack();
		stack.add(90);
		stack.add(100);
		stack.add(12);
		System.out.println(stack.peek());
		System.out.println(stack.pop());
		System.out.println(stack.peek());
		
	}
}