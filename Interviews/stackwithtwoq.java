import java.util.*;
public class Solution{
	
}

public class MyQueue<T> {
	private Stack<T> stackNewestOnTop = new Stack<>();
	private Stack<T> stackOldestOnTop = new Stack<>();

	public void enqueue(T value) {
		// add the value
		stackNewestOnTop.push(value);
	}

	public T peek() {
		// Get the oldest value
		// shiftStack();
		return stackOldestOnTop.peek();
	}

	private void shiftStack() {
		if (stackOldestOnTop.isEmpty()) {
			while (!stackNewestOnTop.isEmpty()) {
				stackOldestOnTop.push(stackNewestOnTop.pop());
			}
		}
	}
	public T dequeue() {
		// get the oldest value and remove it 
		// shiftStack();
		return stackOldestOnTop.pop();
	} 
	

}