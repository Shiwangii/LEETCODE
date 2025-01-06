class Solution {
    public int[] minOperations(String boxes) {
        int[] answer=new int[boxes.length()];
        for(int c=0; c<boxes.length(); c++){
            if(boxes.charAt(c)=='1'){
                for(int n=0; n<boxes.length(); n++){
                    answer[n]+=Math.abs(n-c);
                }
            }
        }
        return answer;
        
    }
}