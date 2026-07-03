class Solution {
public:
    bool ans;
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& path, int n){
        visited[n]=true;
        path[n]=true;
        for(int neigh:graph[n]){
            if(path[neigh]){
                ans=false;
                return;
            } 
            dfs(graph, visited, path, neigh);
        }
        path[n]=false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited, path;
        visited.resize(numCourses, false);
        path.resize(numCourses, false);
        vector<vector<int>> graph(numCourses);
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            graph[v].push_back(u);
        }
        ans=true;
        for(int i=0; i<numCourses; i++){
            if(!visited[i]) dfs(graph, visited, path, i);
        }
        return ans;
    }
};
