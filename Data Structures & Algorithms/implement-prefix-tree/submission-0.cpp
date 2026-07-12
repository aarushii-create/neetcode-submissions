class PrefixTree {
    unordered_map<char, PrefixTree*> mp;
    bool isEnd;
public:
    PrefixTree() {
        isEnd=false;
    }
    
    void insert(string word) {
        PrefixTree* curr=this;
        for(char c:word){
            if(curr->mp.find(c)==curr->mp.end())
                curr->mp[c]=new PrefixTree();
            curr=curr->mp[c];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        PrefixTree* curr=this;
        for(char c:word){
            if(curr->mp.find(c)==curr->mp.end()) return false;
            curr=curr->mp[c];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* curr=this;
        for(char c:prefix){
            if(curr->mp.find(c)==curr->mp.end()) return false;
            curr=curr->mp[c];
        }
        return true;
    }
};
