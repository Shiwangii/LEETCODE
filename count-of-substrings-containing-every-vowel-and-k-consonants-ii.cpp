import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public long countAtLeastMConsonants(String word, int m) {
        int n = word.length();
        long ans = 0;
        int start = 0;
        int end = 0;
        int numConsonants = 0; // Count of consonants
        HashSet<Character> vowels = new HashSet<>(Set.of('a', 'e', 'i', 'o', 'u'));
        HashMap<Character, Integer> vowelMap = new HashMap<>(); // Map to keep track of vowel counts

        while (end < n) {
            // Expand the window by moving the end pointer
            char endChar = word.charAt(end);
            if (vowels.contains(endChar)) {
                vowelMap.put(endChar, vowelMap.getOrDefault(endChar, 0) + 1);
            } else {
                numConsonants++;
            }
            end++;

            // Check if we have all vowels
            while (vowelMap.size() == 5 && numConsonants >= m) {
                // Count valid substrings from start to end
                ans += (n - end + 1); // Count valid substrings

                char startChar = word.charAt(start);
                if (vowels.contains(startChar)) {
                    vowelMap.put(startChar, vowelMap.get(startChar) - 1);
                    if (vowelMap.get(startChar) == 0) {
                        vowelMap.remove(startChar); // Remove vowel if count is zero
                    }
                } else {
                    numConsonants--; // Decrease consonant count
                }
                start++; // Move the start pointer
            }
        }

        return ans; // Return the total count
    }

    public long countOfSubstrings(String word, int k) {
        return countAtLeastMConsonants(word, k) - countAtLeastMConsonants(word, k + 1);
    }

    // Main method for testing
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.countOfSubstrings("aeiou", 0)); // Expected output: 1
        System.out.println(solution.countOfSubstrings("aeioqq", 1)); // Expected output: 0
        System.out.println(solution.countOfSubstrings("ieaouqqieaouqq", 1)); // Expected output: 3
    }
}
