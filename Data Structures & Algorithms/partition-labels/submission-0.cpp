class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        int n=s.length();
        for(int i=0; i<n; i++){
            mp[s[i]]=i;
        }
        unordered_set<char> st;
        int l=0, i=0;
        vector<int> res;
        while(i<n){
            int r=mp[s[i]];
            while(l<r){
                if(st.find(s[l])==st.end()){
                    st.insert(s[l]);
                    r=max(mp[s[l]], r);
                }
                l++;
            }
            cout<<" "<<r<<" "<<l<<" "<<i<<endl;
            l=r;
            res.push_back(r-i+1);
            i=r+1;
        }
        return res;
    }
};