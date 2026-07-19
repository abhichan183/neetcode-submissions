class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(i,j,word,0,board)) return true;
            }
        }
        return false;
    }
    bool dfs(int i,int j, string& word,int idx,vector<vector<char>>& board){
        if(idx==word.size()) return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()) return false;
        char c=board[i][j];
        if(c!=word[idx]) return false;
        board[i][j]='#';
        bool a=dfs(i+1,j,word,idx+1,board);
        bool b=dfs(i,j+1,word,idx+1,board);
        bool x=dfs(i-1,j,word,idx+1,board);
        bool d=dfs(i,j-1,word,idx+1,board);
        board[i][j]=c;
        return a||b||x||d;
    }
};