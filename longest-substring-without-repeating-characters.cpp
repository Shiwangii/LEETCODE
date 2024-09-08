class Solution {
    public int lengthOfLongestSubstring(String s) {
        int m=0, n=s.length();
        Set<Character> ss =new HashSet<>();
        int left=0;
        for(int right=0; right<n; right++){
            if(!ss.contains(s.charAt(right))){
                ss.add(s.charAt(right));
                m=Math.max(m, right-left+1);
            }else{
                while(ss.contains(s.charAt(right))){
                    ss.remove(s.charAt(left));
                    left++;
                }
                ss.add(s.charAt(right));
            }
        } 
        return m;
    }
}