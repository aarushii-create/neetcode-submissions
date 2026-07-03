class Solution {
public:
    int counting1(int n){
        int m=0;
        while(n){
            m+=n & 1;
            n=(n>>1);
        }
        return m;
    }
    vector<int> countBits(int n) {
        int i=0;
        vector<int> res;
        while(i<=n){
            res.push_back(counting1(i));
            i++;
        }
        return res;
    }
};
