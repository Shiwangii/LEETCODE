class Solution {
    public char kthCharacter(int k) {
        StringBuilder word=new StringBuilder("a");
        while(word.length()<k){
            StringBuilder nextWord=new StringBuilder();
            for(int i=0; i<word.length(); i++){
                char nextchar=(char)(((word.charAt(i)-'a'+1)%26)+'a');
                nextWord.append(nextchar);

            }
            word.append(nextWord);
        }
        return word.charAt(k-1);
    }
}