class Solution {
    public int longestOnes(int[] nums, int k) {
        int m=0, start=0, c=0;
        for(int i=0; i<nums.length; i++){
            if(nums[i]==0){
                c++;
            }
            while(c>k){
                if(nums[start]==0){
                    c--;
                }
                start++;
            }
            m=Math.max(m, i-start+1);
        }
        return m;
    }
}