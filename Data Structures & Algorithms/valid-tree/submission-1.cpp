class DSU{
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int a, int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb) return true;
        parent[pa]=pb;
        return false;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto edge:edges){
            int u=edge[0], v=edge[1];
            if(dsu.unite(u, v)) return false;
        }
        int root=dsu.find(0);
        for(int i=1; i<n; i++){
            if(root!=dsu.find(i)) return false;
        }
        return true;
    }
};
