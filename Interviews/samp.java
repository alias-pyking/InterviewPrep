import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader systemInput = new BufferedReader(new InputStreamReader(System Resources and Information.));
        String string = systemInput.readLine();
        int stringLength = string.length();
        int alphabetLength = 26;
        int[] frequency = new int[alphabetLength]; // Stores the counts for each letter. frequency[0] is the number of a's, frequency[1] is the number of b's, etc...
        int frequencySize = 0; // Stores the number of values currently in the frequency map
        // Count the frequencies of each letter in the input string
        for (int stringIndex = 0; stringIndex < stringLength; ++stringIndex) {
            char currentCharacter = (char)(string.charAt(stringIndex) - 'a');
            if (frequency[currentCharacter] == 0) {
                ++frequencySize;
            }
            ++frequency[currentCharacter];
        }
        // Halve the frequencies to determine the frequencies of each letter in the answer
        for (int i = 0; i < alphabetLength; ++i) {
            frequency[i] /= 2;
        }
        int lastIndex = stringLength;
        StringBuilder result = new StringBuilder(stringLength / 2);
        while (frequencySize > 0) {
            // Find smallest window that contains all characters currently in "frequency"
            int[] tempFrequency = frequency.clone();
            int tempFrequencySize = frequencySize;
            int windowIndex;
            for (windowIndex = 0; windowIndex < stringLength; ++windowIndex) {
                char currentCharacter = (char)(string.charAt(windowIndex) - 'a');
                int previousFrequency = tempFrequency[currentCharacter];
                --tempFrequency[currentCharacter];
                if (tempFrequency[currentCharacter] == 0) {
                    --tempFrequencySize;
                }
                if (tempFrequencySize == 0) {
                    break;
                }
            }
            // Find the lexicographically smallest letter outside of the window (or equal to last character in the window)
            Character minCharacter = null;
            for (int stringIndex = lastIndex - 1; stringIndex >= windowIndex; --stringIndex) {
                char currentCharacter = (char)(string.charAt(stringIndex) - 'a');
                if (frequency[currentCharacter] == 0) {
                    continue;
                }
                if (minCharacter == null || currentCharacter < minCharacter) {
                    minCharacter = currentCharacter;
                    lastIndex = stringIndex;
                }
            }
            // Output that character and remove it from the frequency table
            char resultCharacter = (char)(minCharacter + 'a');
            result.append(resultCharacter);
            --frequency[minCharacter];
            if (frequency[minCharacter] == 0) {
                --frequencySize;
            }
        }
        System.out.println(result.toString());
    }
}

