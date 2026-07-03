class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            graph[v].push_back(u);
            in[u]++;
        }
        vector<int> res;
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(!in[i]) q.push(i);
        }
        int indx=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int r=q.front();
                q.pop();
                indx++;
                res.push_back(r);
                for(int neigh:graph[r]){
                    in[neigh]--;
                    if(!in[neigh]){
                        q.push(neigh);
                    }
                }
            }
        }
        if(indx==numCourses) return res;
        return {};
    }
};
