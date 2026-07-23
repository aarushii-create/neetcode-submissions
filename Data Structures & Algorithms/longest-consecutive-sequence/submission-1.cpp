class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num:nums)
            pq.push(num);
        int best=1, prev=pq.top();
        pq.pop();
        int len=1;
        while(!pq.empty()){
            if(abs(prev-pq.top())==1) len++;
            else if(abs(prev-pq.top())>1) len=1;
            prev=pq.top();
            pq.pop();
            best=max(best, len);
        }
        return best;
    }
};
