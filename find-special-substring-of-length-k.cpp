class Solution {
    // class Solution {
    public boolean hasSpecialSubstring(String s, int k) {
        int n = s.length();
        
        for (int i = 0; i <= n - k; i++) {
            char ch = s.charAt(i);
            
            // Check if substring s[i:i+k] consists of the same character
            boolean isValid = true;
            for (int j = i; j < i + k; j++) {
                if (s.charAt(j) != ch) {
                    isValid = false;
                    break;
                }
            }
            
            // Check the boundary conditions
            if (isValid) {
                if ((i == 0 || s.charAt(i - 1) != ch) && (i + k == n || s.charAt(i + k) != ch)) {
                    return true;
                }
            }
        }
        
        return false;
    }
}