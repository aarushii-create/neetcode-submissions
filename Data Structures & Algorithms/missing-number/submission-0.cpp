class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int eSum=n*(n+1)/2;
        int aSum=0;
        for(int i=0; i<n; i++){
            aSum+=nums[i];
        }
        return eSum-aSum;
    }
};
