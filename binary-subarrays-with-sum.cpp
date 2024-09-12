class Solution {
    public int atmost(int[] nums, int k){
        if(k<0)return 0;
        int l=0, cnt=0;
        int res=0;
        for(int i=0; i<nums.length; i++){
            cnt+=nums[i];
            while(cnt>k && l<=i){
                cnt-=nums[l++];
            }
            res+=(i-l+1);
        }
        return res;
    }
    public int numSubarraysWithSum(int[] nums, int goal) {
        return atmost(nums, goal)-atmost(nums, goal-1);
    }
}