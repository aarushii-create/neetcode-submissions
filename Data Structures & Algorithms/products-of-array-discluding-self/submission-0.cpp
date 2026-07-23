class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> suffix(n+1, 1);
        for(int i=n-1; i>0; i--){
            suffix[i-1]=nums[i]*suffix[i];
        }
        int prefix=1;
        vector<int> res;
        for(int i=0; i<n; i++){
            res.push_back(suffix[i]*prefix);
            prefix*=nums[i];
        }
        return res;
    }
};
