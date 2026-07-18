class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        unordered_map<string, bool> visited;
        for(auto &word:wordList){
            st.insert(word);
            visited[word]=false;
        }
        if(st.find(endWord)==st.end()) return 0;
        int ans=1;
        queue<string> q;
        q.push(beginWord);
        visited[beginWord]=true;
        int n=beginWord.length();
        while(!q.empty()){
            int z=q.size();
            ans++;
            while(z--){
                auto temp=q.front();
                q.pop();
                for(int i=0; i<n; i++){
                    char ch=temp[i];
                    for(int j=0; j<26; j++){
                        temp[i]=char('a'+j);
                        if(temp[i]==ch) continue;
                        if(temp==endWord) return ans;
                        if(st.find(temp)!=st.end() && !visited[temp]){
                            q.push(temp);
                            visited[temp]=true;
                        }
                    }
                    temp[i]=ch;
                }
            }
        }
        return 0;
    }
};