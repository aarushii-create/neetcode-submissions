class Solution {
public:
    int dr[4]={-1, 1, 0, 0};
    int dc[4]={0, 0, -1, 1};
    void dfs(vector<vector<char>>& board, int rows, int cols, int r, int c){
        board[r][c]='T';
        for(int k=0; k<4; k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=1 && nr<rows-1 && nc>=1 && nc<cols-1 && board[nr][nc]=='O'){
                dfs(board, rows, cols, nr, nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i==0 || i==m-1) && board[i][j]=='O'){
                    dfs(board, m, n, i, j);
                } 
                if((j==0 || j==n-1) && board[i][j]=='O'){
                    dfs(board, m, n, i, j);
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='T') board[i][j]='O';
            }
        }
    }
};
