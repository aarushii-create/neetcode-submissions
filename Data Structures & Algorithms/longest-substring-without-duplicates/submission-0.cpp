class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxLen=0, l=0, r=0;
        unordered_set<char> st;
        while(l<=r && r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
            maxLen=max(maxLen, r-l);
        }
        return maxLen;
    }
};
