class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1, 0);
        dp[0]=1;
        if(s[0]!='0') dp[1]+=dp[0];
        else return 0;
        for(int i=2; i<n+1; i++){
            if(s[i-1]!='0') dp[i]+=dp[i-1];
            string temp="";
            temp+=s[i-2];
            temp+=s[i-1];
            if(temp>="1" && temp<="26") dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};