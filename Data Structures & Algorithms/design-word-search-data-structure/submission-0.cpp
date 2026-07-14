class TrieNode{
public:
    TrieNode* child[26];
    bool end;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        end=false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr=root;
        for(char c:word){
            int pos=c-'a';
            if(curr->child[pos]==NULL){
                curr->child[pos]=new TrieNode();
            }
            curr=curr->child[pos];
        }
        curr->end=true;
    }
    
    bool search(string word) {
        return dfs(root,word,0);
    }
    bool dfs(TrieNode* curr,string& word, int idx){
        if(idx==word.size()) return curr->end;
        if(word[idx]!='.'){
        int pos=word[idx]-'a';
        if(curr->child[pos]==NULL) return false;
        return dfs(curr->child[pos],word,idx+1);
        }
        for(int i=0;i<26;i++){
            if(curr->child[i]){
                if(dfs(curr->child[i],word,idx+1)) return true;
            }
        }
        return false;
    }
};
