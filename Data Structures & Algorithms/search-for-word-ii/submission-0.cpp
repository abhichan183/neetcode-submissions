class TrieNode{
public:
    TrieNode* child[26];
    bool end;
    string s;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        end=false;
        s="";
    }
};

class Solution {
public:
    TrieNode* root=new TrieNode();
    vector<string> ans;
    void insert(string word){
        TrieNode* curr=root;
        for(char c:word){
            int pos=c-'a';
            if(curr->child[pos]==NULL) curr->child[pos]=new TrieNode();
            curr=curr->child[pos];
        }
        curr->end=true;
        curr->s=word;
    }
    void dfs(vector<vector<char>>& board,int i,int j,TrieNode* curr){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()) return;
        char c=board[i][j];
        if(c=='#') return;
        if(curr->child[c-'a']==NULL) return;
        curr=curr->child[c-'a'];
        if(curr->end) {
            ans.push_back(curr->s);
            curr->end=false;
        }
        board[i][j]='#';
        dfs(board,i+1,j,curr);
        dfs(board,i-1,j,curr);
        dfs(board,i,j+1,curr);
        dfs(board,i,j-1,curr);
        board[i][j]=c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string s:words) insert(s);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,i,j,root);
            }
        }
        return ans;
    }
};
