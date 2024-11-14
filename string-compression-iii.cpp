class Solution {
    public String compressedString(String word) {
        StringBuilder comp = new StringBuilder();
        int n = word.length();
        int i = 0;

        while (i < n) {
            char currentChar = word.charAt(i);
            int count = 0;

           
            while (i < n && word.charAt(i) == currentChar && count < 9) {
                count++;
                i++;
            }

           
            comp.append(count).append(currentChar);
        }

        return comp.toString();
    }


}