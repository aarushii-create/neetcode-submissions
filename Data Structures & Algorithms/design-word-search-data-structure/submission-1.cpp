class WordDictionary {
    unordered_map<char, WordDictionary*> mp;
    bool isEnd;
    bool dfs(string word, int i, WordDictionary* curr){
        if(i==word.length()){
            return curr->isEnd;
        }
        if(word[i]!='.'){
            if(curr->mp.find(word[i])==curr->mp.end()){
                return false;
            }
            WordDictionary* next = curr->mp[word[i]];
            return dfs(word, i+1, next);
        }
        if(word[i]=='.'){
            for(auto &child:curr->mp){
                if(dfs(word, i+1, child.second)) return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        isEnd=false;
    }
    
    void addWord(string word) {
        WordDictionary* curr=this;
        for(char c:word){
            if(curr->mp.find(c)==curr->mp.end())
                curr->mp[c]=new WordDictionary();
            curr=curr->mp[c];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        WordDictionary* curr=this;
        return dfs(word, 0, curr);
    }
};
