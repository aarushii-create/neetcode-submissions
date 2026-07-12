class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int i=0, steps=0;
        if(i==n-1) return 0;
        while(i<n-1){
            int max=0, indx;
            steps++;
            if(i+nums[i]>=n-1) return steps;
            for(int k=i+1; k<=i+nums[i] && k<n; k++){
                if(k+nums[k]>max){
                    max=k+nums[k];
                    indx=k;
                }
            }
            i=indx;
        }
        return steps;
    }
};
