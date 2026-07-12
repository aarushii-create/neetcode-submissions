class Solution {
    bool isPalindrome(string s){
        int n=s.length(), i=0;
        while(i<n/2){
            if(s[i]!=s[n-1-i]) return false;
            i++;
        }
        return true;
    }
public:
    vector<vector<string>> res;
    vector<string> temp;
    void helper(string s, int n, int i){
        if(i==n){
            res.push_back(temp);
            return;
        }
        for(int j=i; j<n; j++){
            string sol=s.substr(i, j-i+1);
            if(isPalindrome(sol)){
                temp.push_back(sol);
                helper(s, n, j+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        helper(s, n, 0);
        return res;
    }
};
