class Solution {
    public int maxAscendingSum(int[] nums) {
    int maxSum = 0, sum = nums[0];  // Start with the first element
    for (int i = 1; i < nums.length; i++) {
        if (nums[i - 1] < nums[i]) {  // Check if ascending
            sum += nums[i];
        } else {
            maxSum = Math.max(maxSum, sum);  // Store max sum
            sum = nums[i];  // Reset sum for new sequence
        }
    }
    return Math.max(maxSum, sum);  // Return max sum
}
}