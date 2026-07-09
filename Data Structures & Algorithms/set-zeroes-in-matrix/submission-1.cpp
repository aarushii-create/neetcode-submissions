class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        queue<pair<int, int>> q;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(!matrix[r][c]) q.push({r, c});
            }
        }
        while(!q.empty()){
            auto [r, c]=q.front();
            q.pop();
            for(int i=0; i<rows; i++){
                matrix[i][c]=0;
            }
            for(int j=0; j<cols; j++){
                matrix[r][j]=0;
            }
        }
    }
};
