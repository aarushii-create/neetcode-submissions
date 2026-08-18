class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> ind, outd;
        for(auto ticket:tickets){
            graph[ticket[0]].push_back(ticket[1]);
            ind[ticket[1]]++, outd[ticket[0]]++;
        }
        for(auto& vertex:graph){
            sort(vertex.second.begin(), vertex.second.end(), greater<string>());
        }
        unordered_map<string, bool> visited;
        stack<string> st;
        st.push("JFK");
        visited["JFK"]=true;
        vector<string> res;
        while(!st.empty()){
            string temp=st.top();
            if(!graph[temp].empty()){
                string next=graph[temp].back();
                graph[temp].pop_back();
                st.push(next);
            }
            else {
                st.pop();
                res.push_back(temp);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
