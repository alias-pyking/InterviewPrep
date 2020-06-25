import java.util.*;
class Main {
	public String fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0)
			return "0";
		StringBuilder sb = new StringBuilder();
		if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) {
			sb.append("-");
		}
		long dividend = Math.abs((long) numerator);
		long divisor = Math.abs((long) denominator);
		long remainder = dividend % divisor;
		sb.append(dividend / divisor);
		if (remainder == 0) {
			return sb.toString();
		}
		sb.append('.');
		Map<Long, Integer> map = new HashMap<>();
		while (remainder != 0) {
			if (map.containsKey(remainder)) {
				sb.insert(map.get(remainder), "(");
				sb.append(")");
				break;
			}
			map.put(remainder, sb.length());
			remainder *= 10;
			System.out.println(remainder + " " + divisor);
			sb.append(remainder / divisor);
			System.out.println(sb.toString());
			remainder %= divisor;
		}
		return sb.toString();
	}

	public static void main(String[] args) {
		System.out.println(new Main().fractionToDecimal(2, 6));
	}
}
