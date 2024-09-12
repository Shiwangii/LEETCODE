class Solution {
    public boolean isAnagram(String s, String t) {
        char s1[]= s.toCharArray();
        char t1[]=t.toCharArray();
        HashMap<Character, Integer> mp=new HashMap<Character, Integer>();
        HashMap<Character, Integer> mp1=new HashMap<Character, Integer>();
        for(int i=0; i<s.length(); i++){
            mp.put(s1[i],mp.getOrDefault(s1[i], 0)+1);
        }
        for(int i=0; i<t.length(); i++){
            mp1.put(t1[i],mp1.getOrDefault(t1[i], 0)+1);
        }
        
        return mp.equals(mp1);
    }
}