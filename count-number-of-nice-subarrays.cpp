class Solution {
    public int atmost(int[] nums, int k){
        int count = 0;
        int n = nums.length;
        int prefix[] = new int[n + 1];
        int odd = 0;
        
        for (int i = 0; i < n; i++) {
            prefix[odd]++;
            
            if ((nums[i] & 1) == 1)
                odd++;
            
            if (odd >= k)
                count += prefix[odd - k];
        }
        
        return count;
    }
    
    public int numberOfSubarrays(int[] nums, int k) {
        return atmost(nums, k);
    }
}