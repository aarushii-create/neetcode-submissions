class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int l=0, r=0, res=0;
        while(r<n){
            if(prices[r]<prices[l]) l=r;
            res=max(res, prices[r]-prices[l]);
            r++;
        }
        return res;
    }
};
