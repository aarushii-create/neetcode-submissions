class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tSum=0;
        for(int num:nums) tSum+=num;
        if(tSum%2) return false;
        vector<bool> dp(tSum/2);
        dp[0]=true;
        for(int num:nums){
            int hSum=tSum/2;
            for(; hSum>=num; hSum--){
                if(dp[hSum-num]) dp[hSum]=true;
            }
        }
        return dp[tSum/2];
    }
};
