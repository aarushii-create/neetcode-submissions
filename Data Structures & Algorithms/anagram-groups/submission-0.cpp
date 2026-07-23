class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<n; i++){
            string w=strs[i];
            sort(w.begin(), w.end());
            mp[w].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto &m:mp){
            res.push_back(m.second);
        }
        return res;
    }
};
