class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> list(n);
        vector<int> vis(n,0);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            list[a].push_back(b);
            list[b].push_back(a);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                count++;
                dfs(i,vis,list);
            }
        }
        return count;
    }
    void dfs(int node,vector<int>& vis,vector<vector<int>>& list){
        vis[node]=1;
        for(int x: list[node]){
            if(vis[x]!=1){
                dfs(x,vis,list);
            }
        }
    }
};
