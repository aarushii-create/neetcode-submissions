class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int t=0;
        while(!pq.empty()){
            auto [w, r, c]=pq.top();
            pq.pop();
            if(visited[r][c]) continue;
            t=max(w, t);
            visited[r][c]=true;
            cout<<w<<"\t";
            if(r==n-1 && c==n-1) return t;
            int dr[4]={-1, 1, 0, 0};
            int dc[4]={0, 0, -1, 1};
            int minV=INT_MAX, minR, minC;
            for(int k=0; k<4; k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]){
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return t;
    }
};
