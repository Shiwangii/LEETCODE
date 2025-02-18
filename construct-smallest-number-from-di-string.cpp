class Solution {
    public String smallestNumber(String pattern) {
        StringBuilder result=new StringBuilder();
        buildSequence(0, 0, pattern.toCharArray(), result);
        return result.reverse().toString();
        
    }
    int buildSequence(int currentIndex, int currentCount, char[] patternArray, StringBuilder result){
        if(currentIndex!=patternArray.length){
            if(patternArray[currentIndex]=='I')buildSequence(currentIndex+1, currentIndex+1, patternArray, result);
            else currentCount=buildSequence(currentIndex+1, currentCount, patternArray, result);
        }
        
        result.append(currentCount+1);
        return currentCount+1;

    }
    
}