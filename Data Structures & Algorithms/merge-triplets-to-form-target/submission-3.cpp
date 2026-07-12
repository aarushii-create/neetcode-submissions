class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        sort(triplets.begin(), triplets.end());
        int x=target[0], y=target[1], z=target[2];
        int a=0, b=0, c=0;
        for(int i=0; i<n; i++){
            int p=triplets[i][0], q=triplets[i][1], r=triplets[i][2];
            if(max(a, p)<=x && max(b, q)<=y && max(c, r)<=z){
                a=max(a, p);
                b=max(b, q);
                c=max(c, r);
            }
        }
        return (a==x)&&(b==y)&&(c==z);
    }
};
