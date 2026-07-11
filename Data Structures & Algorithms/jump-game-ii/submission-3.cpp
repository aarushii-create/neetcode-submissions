class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int steps=0, i=0;
        if(i==n-1) return steps;
        while(i<n){
            if(i+nums[i]>=n-1) return steps+1;
            int pos, m=0;
            for(int k=i+1; k<=i+nums[i] && k<n; k++){
                if(k+nums[k]>m) {
                    pos=k;
                    m=k+nums[k];
                }
            }
            i=pos;
            steps++;
        }
        return steps+1;
    }
};