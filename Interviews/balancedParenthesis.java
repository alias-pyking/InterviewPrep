import java.util.*;
class parenthesis {
	public static boolean isBalanced(String expression) {
		Stack<Character> stack = new Stack<>();
		for (char c : expression.toCharArray()) {
			if (c == '[' || c == '{' || c == '(') {
				//open 
				stack.push(c);
				System.out.println(stack.toString());
			}
			else {
				if (stack.isEmpty()) {
					return false;
				}
				char top = stack.pop();
				if (top == '{' && c != '}')
					return false;
				if (top == '(' && c != ')')
					return false;
				if (top == '[' && c != ']')
					return false;
			}
		}
		return stack.isEmpty();
	}
	public static void main(String[] args) {
		String str1 = "{{}}";
		String str2 = "{}{([]}}";
		System.out.println(isBalanced(str1));
		System.out.println(isBalanced(str2));
	}
}