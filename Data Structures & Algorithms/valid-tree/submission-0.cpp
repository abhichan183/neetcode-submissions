class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(dfs(0,-1,adj,vis)) return false;
        for(int i=0;i<n;i++){
            if(vis[i]!=1) return false;
        }
        return true;
    }
    bool dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;
        for(int x:adj[node]){
            if(vis[x]!=1){
                if(dfs(x,node,adj,vis)) return true;
            }
            else if(x!=parent) return true;
        }
        return false;
    }
};
