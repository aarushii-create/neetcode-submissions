class DSU{
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n+1);
        for(int i=1; i<=n; i++)
            parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int a, int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb) return false;
        parent[pa]=pb;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        int node, neigh;
        for(auto &edge:edges){
            int u=edge[0], v=edge[1];
            if(!dsu.unite(u, v)){
                node=u;
                neigh=v;
            }
        }
        return {node, neigh};
    }
};
