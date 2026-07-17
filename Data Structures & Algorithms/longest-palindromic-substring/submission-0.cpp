class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans=s.substr(0, 1);
        for(int i=0; i<n; i++){
            int l=i-1, r=i+1;
            while(l>=0 && r<n){
                if(s[l]!=s[r]) break;
                l--, r++;
            }
            int left=i, right=i+1;
            while(left>=0 && right<n){
                if(s[left]!=s[right]) break;
                left--, right++;
            }
            int oddLen=r-l-1, evenLen=right-left-1;
            if(oddLen>ans.length()) ans=s.substr(l+1, oddLen);
            if(evenLen>ans.length()) ans=s.substr(left+1, evenLen);
        }
        return ans;
    }
};