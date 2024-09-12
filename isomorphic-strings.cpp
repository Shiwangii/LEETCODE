
class Solution {
    public boolean isIsomorphic(String s, String t) {
        char s1[] = s.toCharArray();
        char t1[] = t.toCharArray();
        HashMap<Character, Character> mp = new HashMap<Character, Character>();
        HashMap<Character, Character> mp1 = new HashMap<Character, Character>();

        if (t.length() != s.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            if (mp.containsKey(s1[i])) {
                if (mp.get(s1[i]) != t1[i]) {
                    return false;
                }
            } else {
                if (mp1.containsKey(t1[i])) {
                    return false;
                }
                mp.put(s1[i], t1[i]);
                mp1.put(t1[i], s1[i]);
            }
        }

        return true;
    }
}
