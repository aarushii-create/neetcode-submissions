class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int l=-1, r=0;
        int maxSum=INT_MIN, sum=0;
        while(l<r && r<n){
            sum+=nums[r];
            maxSum=max(maxSum, sum);
            if(sum<0){
                sum=0;
                l=r;
            }
            r++;
        }
        return maxSum;
    }
};
