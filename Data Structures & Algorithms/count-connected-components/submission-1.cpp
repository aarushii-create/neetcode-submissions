class Solution {
public:
    vector<int> visited;
    void dfs(vector<vector<int>>& graph, int r){
        visited[r]=true;
        for(int neigh:graph[r]){
            if(!visited[neigh]){
                dfs(graph, neigh);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        visited.resize(n, false);
        for(auto edge: edges){
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(graph, i);
                ans++;
            }
        }
        return ans;
    }
};
