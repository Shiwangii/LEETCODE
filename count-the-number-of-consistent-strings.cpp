class Solution {
    public static boolean found(String word, String allowed){
        int n=word.length();
        int m=allowed.length();
        for(int i=0; i<n; i++){
            if(allowed.indexOf(word.charAt(i))==-1){
                return false;
            }
           

        }
        return true;
    }
    public int countConsistentStrings(String allowed, String[] words) {
        int n=words.length;
        int count=0;
        for(int i=0; i<n; i++){
            if(found(words[i], allowed)){
                count++;
            }
        }
        return count;
    }
}