class Trie{
public:
    unordered_map<char, Trie*> mp;
    bool isEnd;
    string s;
    Trie(){
        isEnd=false;
    }
    void add(string &word){
        Trie* curr=this;
        for(char c:word){
            if(curr->mp.find(c)==curr->mp.end())
                curr->mp[c]=new Trie();
            curr=curr->mp[c];
        }
        curr->isEnd=true;
        curr->s=word;
    }
};
class Solution {
public:
    vector<string> ans;
    void dfs(vector<vector<char>>& board, int rows, int cols, int r, int c, Trie* node){
        if(node->isEnd){
            ans.push_back(node->s);
            node->isEnd=false;
        }
        int dr[4]={-1, 1, 0, 0};
        int dc[4]={0, 0, -1, 1};
        char temp=board[r][c];
        board[r][c]='#';
        for(int k=0; k<4; k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nr<rows && nc>=0 && nc<cols && board[nr][nc]!='#' && node->mp.count(board[nr][nc])){
                dfs(board, rows, cols, nr, nc, node->mp[board[nr][nc]]);
            }
        }
        board[r][c]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows=board.size();
        int cols=board[0].size();
        Trie trie;
        for(auto word:words){
            trie.add(word);
        }
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                char ch=board[r][c];
                if(trie.mp.count(ch))
                    dfs(board, rows, cols, r, c, trie.mp[ch]);
            }
        }
        return ans;
    }
};