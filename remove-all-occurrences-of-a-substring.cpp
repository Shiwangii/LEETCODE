class Solution {
    public String removeOccurrences(String s, String part) {
        while(s.contains(part)){
            int p=s.indexOf(part);
            s=s.substring(0, p)+s.substring(p+part.length());
        }return s;

    }
}