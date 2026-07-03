class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i=0;
        int m=0;
        while(i<32){
            m+=(n)&1;
            n=n>>1;
            i++;
        }
        return m;
    }
};
