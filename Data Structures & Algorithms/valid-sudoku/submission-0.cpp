class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, char num){
        for(int i=r; i<9; i++){
            if(i==r) continue;
            if(board[i][c]==num) return false;
        }
        for(int i=c; i<9; i++){
            if(i==c) continue;
            if(board[r][i]==num) return false;
        }
        int bi=r-r%3;
        int bj=c-c%3;
        for(int i=bi; i<bi+3; i++){
            for(int j=bj; j<bj+3; j++){
                if(i==r && j==c) continue;
                if(board[i][j]==num) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.' && !isSafe(board, i, j, board[i][j])) return false;
            }
        }
        return true;
    }
};
