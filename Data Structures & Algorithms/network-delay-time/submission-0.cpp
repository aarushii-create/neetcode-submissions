class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto time:times){
            int u=time[0], v=time[1], w=time[2];
            graph[u].push_back({v, w});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        int minCost=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            auto [currDist, node]=pq.top();
            pq.pop();
            if(dist[node]<currDist) continue;
            for(auto [neigh, weigh]:graph[node]){
                if(currDist+weigh<dist[neigh]){
                    dist[neigh]=currDist+weigh;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        for(int i=1; i<=n; i++){
            if(dist[i]==INT_MAX) return -1;
            minCost=max(minCost, dist[i]);
        }
        return minCost;
    }
};
