class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int, int>>> graph(n);
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int w=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                graph[i].push_back({j, w});
                graph[j].push_back({i, w});
            }
        }
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int minCost=0;
        while(!pq.empty()){
            auto[weight, node]=pq.top();
            pq.pop();
            if(visited[node]) continue;
            minCost+=weight;
            visited[node]=true;
            for(auto [neigh, weigh]:graph[node]){
                if(!visited[neigh]){
                    pq.push({weigh, neigh});
                }
            }
        }
        return minCost;
    }
};
