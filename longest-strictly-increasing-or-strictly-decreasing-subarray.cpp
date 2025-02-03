class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n=nums.length;
        int l=1;
        int si=1, sd=1;
        for(int i=0; i<n-1; i++){
            if(nums[i+1]>nums[i])si++;
            else si=1;
            if(nums[i+1]<nums[i])sd++;
            else sd=1;
            l=Math.max(l,Math.max(si, sd) );
        }
        return l;
        
    }
}