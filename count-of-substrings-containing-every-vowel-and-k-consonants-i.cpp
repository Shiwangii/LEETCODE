class Solution {
    public int countOfSubstrings(String word, int k) {
        int n=word.length();
        List<Character> vowels=Array.asList('a', 'e', 'i', 'o', 'u');
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                List<Integer> freq(26, 0);
                int cnt=0;
                for(int k=i; k<=j; k++){
                    freq[word[k]-'a']++;
                    bool isVowel=false;
                    for(int l=0; l<5; l++){
                        if(word[k]==vowels[l])isVowel=true;
                    }
                    if(!isVowel)cnt++;
                }
                boolean constainsAllVowel=true;
                if(freq['a'-'a']==0)containsAllVowels=false;
                if(freq['a'-'a']==0)containsAllVowels=false;
            }
        }
    }
}