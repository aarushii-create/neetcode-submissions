class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(), ans=0;
        for(int i=0; i<n; i++){
            int l=i-1, r=i+1;
            int left=i, right=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                ans++, l--, r++;
            }
            while(left>=0 && right<n && s[left]==s[right]){
                ans++, left--, right++;
            }
        }
        return ans+n;
    }
};