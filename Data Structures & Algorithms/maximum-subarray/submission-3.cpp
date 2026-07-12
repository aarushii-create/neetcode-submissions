class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), maxSum=nums[0];
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            dp[i]=max(nums[i], dp[i+1]+nums[i]);
            maxSum=max(maxSum, dp[i]);
        }
        return maxSum;
    }
};
