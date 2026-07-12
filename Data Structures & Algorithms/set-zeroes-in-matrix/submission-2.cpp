class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        bool firstRow=false, firstCol=false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!i && !matrix[i][j]) firstRow=true;
                if(!j && !matrix[i][j]) firstCol=true;
                if(!matrix[i][j]){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(!matrix[0][j] || !matrix[i][0]) matrix[i][j]=0;
            }
        }
        if(firstRow) {
            for(int j=0; j<n; j++) matrix[0][j]=0;
        }
        if(firstCol){
            for(int i=0; i<m; i++) matrix[i][0]=0;
        }
    }
};
