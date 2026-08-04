class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto flight:flights){
            int from=flight[0];
            int to=flight[1];
            int price=flight[2];
            graph[from].push_back({to, price});
        }
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, src, 0});
        dist[src][0]=0;
        while(!pq.empty()){
            auto [cost, city, step]=pq.top();
            pq.pop();
            if(dist[city][step]>cost || step>k) continue;
            for(auto [neigh, price]:graph[city]){
                if(cost+price<dist[neigh][step+1]){
                    dist[neigh][step+1]=cost+price;
                    pq.push({dist[neigh][step+1], neigh, step+1});
                }
            }
        }
        int minCost=INT_MAX;
        for(int i=0; i<=k+1; i++){
            minCost=min(minCost, dist[dst][i]);
        }
        if(minCost==INT_MAX) return -1;
        return minCost;
    }
};
