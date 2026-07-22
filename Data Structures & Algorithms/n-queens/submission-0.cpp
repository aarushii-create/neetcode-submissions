class Solution {
public:
    vector<vector<string>> res;
    vector<string> temp;
    bool isSafe(int n, int row, int col){
        for(int i=row-1; i>=0; i--)
            if(temp[i][col]=='Q') return false;
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
            if(temp[i][j]=='Q') return false;
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
            if(temp[i][j]=='Q') return false;
        return true;
    }
    void solve(int n, int level){
        if(n==level){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(isSafe(n, level, i)){
                temp[level][i]='Q';
                solve(n, level+1);
                temp[level][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        temp.resize(n, string(n, '.'));
        solve(n, 0);
        return res;
    }
};