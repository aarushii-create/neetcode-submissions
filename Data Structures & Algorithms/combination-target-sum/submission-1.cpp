class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void helper(vector<int>& nums, int target, int n, int k){
        if(!target){
            res.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int i=k; i<n; i++){
            target-=nums[i];
            temp.push_back(nums[i]);
            helper(nums, target, n, i);
            temp.pop_back();
            target+=nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        helper(nums, target, n, 0);
        return res;
    }
};
